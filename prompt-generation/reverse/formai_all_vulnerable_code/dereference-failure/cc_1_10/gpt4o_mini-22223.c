//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>

#define PING_PKT_S 64
#define DEFAULT_TTL 64
#define PING_SLEEP_RATE 1000000 // 1 second in microseconds
#define MAX_ATTEMPTS 4

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S - sizeof(struct icmphdr)];
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
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_pkt pckt;
    struct sockaddr_in r_addr;
    int addr_len = sizeof(r_addr);
    struct timeval start_time, end_time, timeout;
    int attempts = 0, max_attempts = MAX_ATTEMPTS;
    ssize_t bytes_sent, bytes_received;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);
    
    while (attempts < max_attempts) {
        attempts++;
        
        // Prepare the packet
        memset(&pckt, 0, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = getpid();
        pckt.hdr.un.echo.sequence = attempts;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        gettimeofday(&start_time, NULL);
        bytes_sent = sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping));
        
        if (bytes_sent <= 0) {
            fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
            continue; // Skip to the next attempt
        }

        bytes_received = recvfrom(sockfd, &r_addr, sizeof(r_addr), 0, NULL, NULL);
        gettimeofday(&end_time, NULL);
        
        if (bytes_received <= 0) {
            fprintf(stderr, "Packet receive error: %s\n", strerror(errno));
            printf("Request timed out.\n");
        } else {
            double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
            time_taken += (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("Reply from %s: bytes=%ld time=%.2f ms\n", ip_addr, bytes_received, time_taken);
        }

        usleep(PING_SLEEP_RATE);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);

    return 0;
}