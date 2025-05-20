//FormAI DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define PACKET_SIZE     64
#define TIMEOUT_US      1000000  
#define MAX_HOPS        30

// A function to compute the checksum of a packet
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address or hostname>\n", argv[0]);
        return -1;
    }

    struct sockaddr_in dest_addr;
    struct hostent *host;
    char* hostname = argv[1];
    char ip[100];
    int ttl = 1;

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Failed to resolve hostname '%s'\n", hostname);
        return -1;
    }

    inet_ntop(AF_INET, host->h_addr_list[0], ip, sizeof(ip));
    printf("PING %s (%s):\n", hostname, ip);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd == -1) {
        printf("Failed to open socket\n");
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip);

    // set ICMP TTL value
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
        printf("Failed to set TTL value\n");
        return -1;
    }

    struct timeval timeout = {1, 0}; // set timeout to 1 second
    socklen_t addr_len = sizeof(dest_addr);
    int seq = 0;

    while (ttl <= MAX_HOPS) {
        // create ICMP packet
        char packet[PACKET_SIZE];
        memset(packet, 0, sizeof(packet));
        struct icmp *icmp = (struct icmp*) packet;
        icmp->icmp_type = ICMP_ECHO;
        icmp->icmp_code = 0;
        icmp->icmp_id = getpid() & 0xffff;
        icmp->icmp_seq = seq++;
        gettimeofday((struct timeval*)icmp->icmp_data, NULL);
        icmp->icmp_cksum = 0;
        icmp->icmp_cksum = checksum(packet, sizeof(packet));

        // send the packet
        clock_t start = clock();
        if (sendto(sockfd, packet, sizeof(packet), 0, 
                (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == -1) {
            printf("Failed to send packet\n");
            break;
        }

        // receive the response
        char recv_buf[PACKET_SIZE];
        memset(recv_buf, 0, sizeof(recv_buf));
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        int n = select(sockfd + 1, &fds, NULL, NULL, &timeout);

        if (n == -1) {
            printf("Select failed\n");
            break;
        }

        if (n == 0) {
            printf("%2d: *\n", ttl);
            ttl++;
            continue;
        }

        if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0,
                (struct sockaddr*)&dest_addr, &addr_len) == -1) {
            printf("Failed to receive packet\n");
            break;
        }

        // calculate the round-trip time
        struct timeval end;
        gettimeofday(&end, NULL);
        double rtt = (double)(end.tv_sec - ((struct timeval*)icmp->icmp_data)->tv_sec)
                * 1000.0 + (double)(end.tv_usec - ((struct timeval*)icmp->icmp_data)->tv_usec)
                / 1000.0;
        printf("%2d: %s (%.2f ms)\n", ttl, inet_ntoa(dest_addr.sin_addr), rtt);

        // check if we have reached the destination
        if (icmp->icmp_type == ICMP_ECHOREPLY) {
            break;
        } 

        // increment TTL value
        ttl++;
    }

    // close the socket
    close(sockfd);

    return 0;
}