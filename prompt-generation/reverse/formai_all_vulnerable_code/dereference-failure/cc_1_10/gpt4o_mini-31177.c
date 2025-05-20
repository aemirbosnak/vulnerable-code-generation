//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4
#define TIMEOUT 1

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct timeval tv_out;
    socklen_t addr_len = sizeof(addr_ping);
    struct ping_packet pkt;
    int lost = 0;
    int rtt = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        return;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    tv_out.tv_sec = TIMEOUT;
    tv_out.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv_out, sizeof(tv_out));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof(tv_out));

    printf("Pinging %s:\n", ip_address);
    
    for (int i = 0; i < PING_COUNT; i++) {
        memset(&pkt, 0, sizeof(pkt));
        pkt.hdr.type = ICMP_ECHO;
        pkt.hdr.un.echo.id = getpid();
        pkt.hdr.un.echo.sequence = i + 1;
        pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

        gettimeofday((struct timeval *)&pkt.msg, NULL);

        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            fprintf(stderr, "Ping failed: %s\n", strerror(errno));
            lost++;
            continue;
        }

        struct sockaddr_in r_addr;
        unsigned char buffer[PACKET_SIZE];
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&r_addr, &addr_len) <= 0) {
            fprintf(stderr, "No reply from %s.\n", ip_address);
            lost++;
            continue;
        }

        struct icmphdr *recv_hdr = (struct icmphdr *)(buffer + (buffer[0] & 0x0F) * 4);
        if (recv_hdr->type == ICMP_ECHOREPLY) {
            struct timeval *start_time = (struct timeval *)pkt.msg;
            struct timeval end_time;
            gettimeofday(&end_time, NULL);
            rtt = (end_time.tv_sec - start_time->tv_sec) * 1000 + (end_time.tv_usec - start_time->tv_usec) / 1000;
            printf("Reply from %s: seq=%d time=%d ms\n", ip_address, i + 1, rtt);
        }
    }

    close(sockfd);
    printf("\n--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %d%% packet loss\n", PING_COUNT, PING_COUNT - lost, (lost * 100) / PING_COUNT);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}