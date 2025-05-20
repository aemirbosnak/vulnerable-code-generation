//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define PING_NUM 5
#define PING_INTERVAL 1
#define PACKET_SIZE 64

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to perform the ping request
int ping(const char *host) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmphdr hdr;
    int msg_count = 0, rtt;
    struct timespec start, end;
    char packet[PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Error");
        return -1;
    }

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("Hostname Resolution Error");
        return -1;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = htons(0);
    addr_ping.sin_addr.s_addr = *(long *)(host_info->h_addr);

    while (msg_count < PING_NUM) {
        msg_count++;
        memset(packet, 0, sizeof(packet));
        hdr.type = ICMP_ECHO;
        hdr.un.echo.id = getpid();
        hdr.un.echo.sequence = msg_count;
        hdr.code = 0;
        hdr.checksum = checksum(&hdr, sizeof(hdr));

        clock_gettime(CLOCK_MONOTONIC, &start);
        sendto(sockfd, &hdr, sizeof(hdr), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping));
        
        if (recv(sockfd, packet, sizeof(packet), 0) > 0) {
            clock_gettime(CLOCK_MONOTONIC, &end);
            rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
            printf("Ping %d: RTT = %d ms\n", msg_count, rtt);
        } else {
            printf("Ping %d: Request timed out\n", msg_count);
        }
        
        sleep(PING_INTERVAL);
    }

    close(sockfd);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    printf("Pinging %s for QoS analysis:\n", argv[1]);
    ping(argv[1]);
    printf("Ping analysis complete.\n");

    return 0;
}