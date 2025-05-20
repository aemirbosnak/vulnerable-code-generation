//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 10

struct icmp_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(unsigned short *buf, int len) {
    unsigned long sum = 0;
    while (len > 1) {
        sum += *buf++;
        len -= sizeof(unsigned short);
    }
    if (len)
        sum += *(unsigned char *) buf;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short) (~sum);
}

double get_time_diff(struct timespec *start, struct timespec *end) {
    return (double) (end->tv_sec - start->tv_sec) + (double) (end->tv_nsec - start->tv_nsec) / 1e9;
}

int ping(char *ip) {
    struct hostent *host;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int sockfd, recvbytes, sendbytes, ttl = 64, nsend = 0, nrecv = 0, ret = -1, wait_time = 1;
    struct timespec start, end;
    char packet[PACKET_SIZE];
    struct icmp_packet *icmp = (struct icmp_packet *) packet;
    struct timeval timeout = {MAX_WAIT_TIME, 0};
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    if ((host = gethostbyname(ip)) == NULL) {
        printf("ping: unknown host %s\n", ip);
        return -1;
    }
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);
    printf("PING %s (%s): %d bytes of data.\n", ip, inet_ntoa(addr.sin_addr), PACKET_SIZE);

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket error");
        return -1;
    }

    // set timeout
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_IP, IP_TTL, &ttl, sizeof(ttl));

    while (nsend < 4) {
        memset(&icmp->hdr, 0, sizeof(struct icmphdr));
        icmp->hdr.type = ICMP_ECHO;
        icmp->hdr.code = 0;
        icmp->hdr.un.echo.id = 0;
        icmp->hdr.un.echo.sequence = nsend++;
        memset(&icmp->msg, 0, sizeof(icmp->msg));
        icmp->hdr.checksum = checksum((unsigned short *) icmp, PACKET_SIZE);
        clock_gettime(CLOCK_MONOTONIC, &start);
        if ((sendbytes = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *) &addr, addr_len)) < 0) {
            perror("sendto error");
            continue;
        }

        if ((recvbytes = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &addr, &addr_len)) < 0) {
            printf("Request timed out.\n");
            continue;
        }
        clock_gettime(CLOCK_MONOTONIC, &end);

        if (icmp->hdr.type == ICMP_ECHOREPLY) {
            printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.3fms\n", recvbytes,
                   inet_ntoa(addr.sin_addr), icmp->hdr.un.echo.sequence, ttl, get_time_diff(&start, &end) * 1000);
            nrecv++;
            ret = 0;
        } else {
            printf("Error: packet received with type %d\n", icmp->hdr.type);
        }
        sleep(wait_time);
    }

    printf("--- %s ping statistics ---\n", ip);
    printf("%d packets transmitted, %d received, %.0f%% packet loss, time %.0fms\n",
           nsend, nrecv, (double) (nsend - nrecv) / nsend * 100, get_time_diff(&start, &end) * 1000);
    close(sockfd);
    return ret;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }
    return ping(argv[1]);
}