//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define PING_PKT_S 64
#define PING_SLEEP_RATE 1
#define ICMP_HEADER_SIZE 8

typedef struct {
    struct icmphdr hdr;
    char msg[PING_PKT_S - ICMP_HEADER_SIZE];
} packet;

void calculate_rtt(struct timespec *start, struct timespec *end, double *rtt) {
    *rtt = (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_nsec - start->tv_nsec) / 1000000.0;
}

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

void ping(const char *ip_addr, int count) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct hostent *host;
    packet pckt;
    struct timespec start, end;
    int ping_interval = 1;
    
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = htons(0);
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < count; i++) {
        memset(&pckt, 0, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = getpid();
        pckt.hdr.un.echo.sequence = i + 1;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Packet send failed");
            continue;
        }

        char buffer[PING_PKT_S];
        socklen_t addr_len = sizeof(addr_ping);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr_ping, &addr_len) <= 0) {
            perror("Packet receive failed");
            continue;
        }
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + sizeof(struct iphdr));
        double rtt;
        calculate_rtt(&start, &end, &rtt);
        
        if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == pckt.hdr.un.echo.id) {
            printf("Reply from %s: bytes=%d time=%.3f ms\n", ip_addr, PING_PKT_S, rtt);
        } else {
            printf("Received invalid reply from %s\n", ip_addr);
        }

        sleep(ping_interval);
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname|IP> <count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int count = atoi(argv[2]);
    if (count <= 0) {
        fprintf(stderr, "Count must be a positive integer\n");
        return EXIT_FAILURE;
    }

    char *target = argv[1];
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;

    if (getaddrinfo(target, NULL, &hints, &res) != 0) {
        perror("Error resolving the host");
        return EXIT_FAILURE;
    }

    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in *addr_in = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(addr_in->sin_addr), ip, sizeof(ip));
    
    printf("Pinging %s (%s) with %d bytes of data:\n", target, ip, PING_PKT_S);
    ping(ip, count);

    freeaddrinfo(res);
    return EXIT_SUCCESS;
}