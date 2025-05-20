//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_PINGS 10

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} icmp_packet;

volatile sig_atomic_t stop_ping = 0;

void handle_sigint(int sig) {
    stop_ping = 1;
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

void ping(const char *ip_addr, int packet_count) {
    int sockfd;
    struct sockaddr_in addr;
    icmp_packet packet;
    struct timespec start, end;
    double time_taken;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    signal(SIGINT, handle_sigint);
    
    for (int i = 0; i < packet_count; i++) {
        if (stop_ping) {
            break;
        }
        
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, &addr_len) <= 0) {
            perror("Receive failed");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) * 1000.0; // seconds to ms
        time_taken += (end.tv_nsec - start.tv_nsec) / 1000000.0; // ns to ms

        if (packet.hdr.type == ICMP_ECHOREPLY && packet.hdr.un.echo.id == getpid()) {
            printf("Ping to %s: seq=%d time=%.2f ms\n", ip_addr, packet.hdr.un.echo.sequence, time_taken);
        } else {
            printf("Ping to %s: seq=%d: error: ICMP type (%d)\n", ip_addr, packet.hdr.un.echo.sequence, packet.hdr.type);
        }

        sleep(1);
    }

    close(sockfd);
    printf("Ping session completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PACKET_COUNT>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int packet_count = atoi(argv[2]);
    if (packet_count <= 0 || packet_count > MAX_PINGS) {
        fprintf(stderr, "Packet count must be between 1 and %d\n", MAX_PINGS);
        return EXIT_FAILURE;
    }

    ping(argv[1], packet_count);
    return EXIT_SUCCESS;
}