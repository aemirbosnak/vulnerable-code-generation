//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

// Define constants
#define PACKET_SIZE 64
#define PING_COUNT 4
#define ICMP_ECHO 8

// Packet structure
struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (int i = 0; i < len / 2; i++)
        sum += buf[i];
    if (len % 2)
        sum += ((unsigned char *)b)[len - 1];
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Ping function
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct sockaddr_in from;
    socklen_t from_len = sizeof(from);
    int nrecv;
    int nsend = 0;
    clock_t start, end;
    
    memset(&packet, 0, sizeof(packet));
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < PING_COUNT; i++) {
        // Fill packet details
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        start = clock();
        nsend = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
        if (nsend <= 0) {
            perror("Error sending packet");
            continue;
        }

        nrecv = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&from, &from_len);
        if (nrecv < 0) {
            perror("Error receiving packet");
            continue;
        }

        end = clock();
        double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        // Check if the packet received is from the correct source
        if (packet.hdr.type == ICMP_ECHOREPLY && packet.hdr.un.echo.id == getpid()) {
            printf("Reply from %s: bytes=%d time=%.2fms\n", ip_addr, nrecv, time_spent);
        } else {
            printf("Received packet with an invalid ID.\n");
        }

        // Sleep before sending the next packet
        usleep(1000000);  // 1 second
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_addr = argv[1];
    ping(ip_addr);

    return EXIT_SUCCESS;
}