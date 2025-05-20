//FormAI DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 5
#define MAX_NO_OF_PINGS 4

int failed_ping_count = 0;
int received_ping_count = 0;

// Method to calculate checksum
unsigned short calculate_checksum(unsigned short *buf, int nwords) {
    unsigned long sum;
    for(sum=0; nwords>0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

// Send an ICMP Echo Request packet
void send_ping(int ping_sockfd, struct sockaddr *addr, int count) {
    int packet_size = PACKET_SIZE;
    char *packet = (char *) malloc(packet_size);
    if (packet == NULL) {
        perror("Failed to allocate memory for packet");
        exit(EXIT_FAILURE);
    }
    memset(packet, 0, packet_size);
    struct icmphdr *icmp_header = (struct icmphdr *) packet;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = getpid();
    icmp_header->un.echo.sequence = count;
    struct timespec time_sent;
    clock_gettime(CLOCK_MONOTONIC, &time_sent);
    memcpy(packet + sizeof(struct icmphdr), &time_sent, sizeof(time_sent));
    icmp_header->checksum = calculate_checksum((unsigned short *) icmp_header, packet_size);
    int bytes_sent = sendto(ping_sockfd, packet, packet_size, 0, addr, sizeof(*addr));
    if (bytes_sent <= 0) {
        perror("Failed to send packet");
        failed_ping_count++;
    }
    free(packet);
}

// Receive an ICMP Echo Reply packet
void receive_ping(int ping_sockfd, struct sockaddr *addr, int seq_no) {
    char packet[PACKET_SIZE];
    socklen_t addr_len = sizeof(*addr);
    int bytes_received = recvfrom(ping_sockfd, packet, sizeof(packet), 0, addr, &addr_len);
    if (bytes_received <= 0) {
        perror("Failed to receive packet");
        failed_ping_count++;
        return;
    }
    struct icmphdr *icmp_header = (struct icmphdr *) (packet + sizeof(struct iphdr));
    if ((icmp_header->type == ICMP_ECHOREPLY) && (icmp_header->un.echo.id == getpid()) && (icmp_header->un.echo.sequence == seq_no)) {
        struct timespec *time_sent = (struct timespec *) (packet + sizeof(struct iphdr) + sizeof(struct icmphdr));
        struct timespec time_received, time_diff;
        clock_gettime(CLOCK_MONOTONIC, &time_received);
        time_diff.tv_sec = time_received.tv_sec - time_sent->tv_sec - (time_received.tv_nsec - time_sent->tv_nsec < 0 ? 1 : 0);
        time_diff.tv_nsec = (time_received.tv_nsec - time_sent->tv_nsec + 1000000000) % 1000000000;
        printf("%d bytes from %s: icmp_seq=%d time=%.2f ms\n", bytes_received, inet_ntoa(((struct sockaddr_in *) addr)->sin_addr), seq_no, time_diff.tv_sec * 1000.0 + time_diff.tv_nsec / 1000000.0);
        received_ping_count++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip_address_str = argv[1];
    struct in_addr ip_address;
    if (inet_pton(AF_INET, ip_address_str, &ip_address) != 1) {
        perror("Failed to parse IP address");
        exit(EXIT_FAILURE);
    }
    int ping_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (ping_sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = ip_address;
    for (int i = 0; i < MAX_NO_OF_PINGS; i++) {
        send_ping(ping_sockfd, (struct sockaddr *) &addr, i);
        sleep(1);
        receive_ping(ping_sockfd, (struct sockaddr *) &addr, i);
    }
    printf("%d packets transmitted, %d received, %.0f%% packet loss\n", MAX_NO_OF_PINGS, received_ping_count, 100.0 - (received_ping_count * 100.0 / MAX_NO_OF_PINGS));
    if (failed_ping_count > 0) {
        printf("Failed to send/receive %d packets\n", failed_ping_count);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}