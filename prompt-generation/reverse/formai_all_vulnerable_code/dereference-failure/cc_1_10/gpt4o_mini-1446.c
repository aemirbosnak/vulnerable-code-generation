//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_SLEEP_RATE 1000000 // Sleep rate in microseconds (1 second)
#define MAX_PINGS 5

struct ping_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate the checksum
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

// Function to send a ping
void send_ping(int sockfd, struct sockaddr_in *ping_addr, int seq) {
    struct ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.un.echo.sequence = seq;
    packet.header.un.echo.id = getpid();
    strcpy(packet.msg, "Ping!");

    packet.header.checksum = checksum(&packet, sizeof(packet));

    if (sendto(sockfd, &packet, sizeof(packet), 0,
               (struct sockaddr *)ping_addr, sizeof(*ping_addr)) <= 0) {
        perror("Ping send failed");
    }
}

// Function to receive ping reply
void receive_ping(int sockfd, int seq, struct sockaddr_in *ping_addr) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int bytes_received;

    bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                              (struct sockaddr *)&r_addr, &addr_len);
    if (bytes_received < 0) {
        perror("Ping receive failed");
        return;
    }

    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct icmphdr *icmp_header = (struct icmphdr *)(buffer + (ip_header->ihl * 4));

    if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.sequence == seq) {
        printf("Received ping response from %s: seq=%d\n", inet_ntoa(r_addr.sin_addr), seq);
    } else {
        fprintf(stderr, "Received unexpected packet\n");
    }
}

// Main function for ping testing
int main(int argc, char **argv) {
    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS|HOSTNAME> [ping_count] [timeout]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target = argv[1];
    int ping_count = (argc > 2) ? atoi(argv[2]) : MAX_PINGS;
    int timeout = (argc > 3) ? atoi(argv[3]) : 1;

    struct sockaddr_in ping_addr;
    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;

    // Convert hostname to IP address
    if (inet_pton(AF_INET, target, &ping_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or hostname.\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ping_count; i++) {
        send_ping(sockfd, &ping_addr, i + 1);
        receive_ping(sockfd, i + 1, &ping_addr);
        usleep(PING_SLEEP_RATE);
    }

    close(sockfd);
    return 0;
}