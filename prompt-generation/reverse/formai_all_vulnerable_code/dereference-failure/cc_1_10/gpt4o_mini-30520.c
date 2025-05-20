//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define MAX_DATA_SIZE 56
#define TIMEOUT 1

struct ping_packet {
    struct icmphdr hdr;
    char msg[MAX_DATA_SIZE];
};

// Function to calculate checksum
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

// Function to send ping
int send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct ping_packet packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = seq;
    memset(packet.msg, 0, MAX_DATA_SIZE);
    snprintf(packet.msg, MAX_DATA_SIZE, "Ping data %d", seq);
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    return sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr));
}

// Function to receive ping response
void receive_ping(int sockfd, int seq) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    struct iphdr *ip_header;
    struct icmphdr *icmp_header;
    int bytes_received;

    bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len);
    if (bytes_received <= 0) {
        perror("Failed to receive packet");
        return;
    }

    ip_header = (struct iphdr *)buffer;
    icmp_header = (struct icmphdr *)(buffer + (ip_header->ihl << 2));

    if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.sequence == seq) {
        printf("Received ping from %s: seq=%d time=%.2f ms\n",
               inet_ntoa(r_addr.sin_addr),
               seq,
               (double)(clock()) / CLOCKS_PER_SEC * 1000);
    } else {
        printf("Unexpected response type or sequence number.\n");
    }
}

// Main function to execute ping test
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Pinging %s:\n", argv[1]);

    for (int seq = 1; seq <= 5; seq++) {
        if (send_ping(sockfd, &addr, seq) < 0) {
            perror("Ping send failed");
        }
        receive_ping(sockfd, seq);
        sleep(PING_INTERVAL);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}