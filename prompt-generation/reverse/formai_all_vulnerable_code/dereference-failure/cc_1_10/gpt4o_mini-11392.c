//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 5

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

void ping(const char *ip_addr) {
    printf("Pinging %s:\n", ip_addr);

    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_pkt pckt;
    struct timeval timeout;
    fd_set readfds;
    int pingloop = PING_COUNT;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    while (pingloop--) {
        memset(&pckt, 0, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = getpid();
        pckt.hdr.un.echo.sequence = PING_COUNT - pingloop;

        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        usleep(100000);  // 100ms wait before sending packet

        if (sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Packet send failed");
            continue;
        }

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        
        // Wait for the reply for defined timeout
        int rv = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (rv < 0) {
            perror("Select call failed");
            break;
        } else if (rv == 0) {
            printf("Request timed out.\n");
            continue;
        } else {
            struct sockaddr_in r_addr;
            socklen_t r_addr_len = sizeof(r_addr);
            char buffer[PACKET_SIZE];

            if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &r_addr_len) <= 0) {
                perror("Packet receive failed");
                continue;
            } else {
                struct iphdr *ip_hdr = (struct iphdr *)buffer;
                struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (ip_hdr->ihl << 2));

                if (icmp_hdr->type == ICMP_ECHO) {
                    printf("Received packet from %s: seq=%d time=%.2f ms\n",
                           inet_ntoa(r_addr.sin_addr),
                           icmp_hdr->un.echo.sequence,
                           (float)(1000 / TIMEOUT)); // Rough estimation of time
                }
            }
        }
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip-address>\n", argv[0]);
        return 1;
    }

    ping(argv[1]);

    return 0;
}