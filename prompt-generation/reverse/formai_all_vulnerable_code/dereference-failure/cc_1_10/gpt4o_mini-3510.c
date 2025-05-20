//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>

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

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void set_socket_options(int sockfd) {
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Set Socket Options Failed");
        exit(EXIT_FAILURE);
    }
}

void ping(const char *ip_addr) {
    struct sockaddr_in addr_ping;
    struct ping_packet pckt;
    struct sockaddr_in r_addr;
    int addr_len = sizeof(r_addr);
    int sockfd = create_socket();
    set_socket_options(sockfd);

    memset(&pckt, 0, sizeof(pckt));
    pckt.hdr.type = ICMP_ECHO;
    pckt.hdr.un.echo.id = getpid();
    strncpy(pckt.msg, "Ping Test", sizeof(pckt.msg) - 1);
    pckt.hdr.un.echo.sequence = 1;
    pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    printf("Pinging %s:\n", ip_addr);
    for (int i = 0; i < PING_COUNT; i++) {
        if (sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send Failed");
            continue;
        }

        char buffer[PACKET_SIZE];
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&r_addr, (socklen_t*)&addr_len) <= 0) {
            printf("Ping request timed out.\n");
            continue;
        }

        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (ip_hdr->ihl * 4));

        if (icmp_hdr->type == ICMP_ECHOREPLY) {
            printf("Reply from %s: seq=%d, time=%ld ms\n", ip_addr, icmp_hdr->un.echo.sequence, 
                   (long)(clock() - clock()) * 1000 / CLOCKS_PER_SEC);
        } else {
            printf("Received ICMP Type: %d\n", icmp_hdr->type);
        }

        sleep(1);
    }

    close(sockfd);
    printf("Ping test completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);

    return 0;
}