//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 5

// ICMP header structure
struct icmp_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (int n = 0; n < len / 2; n++) {
        sum += buf[n];
    }

    if (len % 2) {
        sum += ((unsigned char *)buf)[len - 1];
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

// Function to create and send the ping
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timespec start, end;

    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Loop for a specified number of pings
    for (int i = 0; i < PING_COUNT; i++) {
        // Prepare ICMP packet
        memset(&packet, 0, sizeof(packet));
        packet.header.type = ICMP_ECHO;
        packet.header.un.echo.id = getpid();
        packet.header.un.echo.sequence = i + 1;
        packet.header.checksum = checksum(&packet, sizeof(packet));

        // Get current time
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Send ICMP echo request
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Receive ICMP echo reply
        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len) <= 0) {
            perror("Receive failed");
            continue;
        }

        // Get response time
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

        struct iphdr *ip_header = (struct iphdr *)buffer;
        struct icmphdr *icmp_header = (struct icmphdr *)(buffer + (ip_header->ihl * 4));

        // Check if the response is of type ICMP_ECHO_REPLY
        if (icmp_header->type == ICMP_ECHO) {
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, time_taken);
        } else {
            printf("Received unexpected packet type %d\n", icmp_header->type);
        }

        // Sleep for a short duration before the next ping
        sleep(1);
    }

    close(sockfd);
}

int main() {
    char ip_address[16];

    printf("Simple C Ping Test\n");
    printf("Enter IP address or hostname to ping: ");
    scanf("%15s", ip_address);

    ping(ip_address);

    return 0;
}