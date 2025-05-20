//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define ICMP_HEADER_SIZE 8

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - ICMP_HEADER_SIZE];
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
    struct ping_packet packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int n_sent, n_received;
    struct timeval tv_timeout;
    fd_set fdset;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        return;
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    strcpy(packet.msg, "Ping data");
    packet.hdr.un.echo.sequence = random() % 10000;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    tv_timeout.tv_sec = TIMEOUT;
    tv_timeout.tv_usec = 0;

    n_sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping));
    if (n_sent <= 0) {
        perror("Send failed");
        close(sockfd);
        return;
    }

    FD_ZERO(&fdset);
    FD_SET(sockfd, &fdset);
    n_received = select(sockfd + 1, &fdset, NULL, NULL, &tv_timeout);

    if (n_received < 0) {
        perror("Select failed");
        close(sockfd);
        return;
    }
    
    if (n_received == 0) {
        printf("Request timed out.\n");
    } else {
        ssize_t response = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &addr_len);
        if (response < 0) {
            perror("Receive failed");
        } else {
            if (packet.hdr.type == ICMP_ECHOREPLY && packet.hdr.un.echo.id == getpid()) {
                printf("Reply from %s: bytes=%d seq=%d ttl=%d\n",
                       ip_address, response, packet.hdr.un.echo.sequence, r_addr.sin_addr.s_addr);
            } else {
                printf("Received an unexpected ICMP packet.\n");
            }
        }
    }
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s:\n", argv[1]);
    ping(argv[1]);

    return 0;
}