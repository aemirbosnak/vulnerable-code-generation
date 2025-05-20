//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>

// Ping Packet Size
#define PACKET_SIZE 64
#define PING_INTERVAL 1

// Function to calculate checksum
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

// Function to send ping
void send_ping(int sockfd, struct sockaddr_in *dest_addr) {
    char packet[PACKET_SIZE];
    struct icmp *icmp_hdr = (struct icmp *)packet;

    memset(packet, 0, PACKET_SIZE);
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;
    icmp_hdr->icmp_cksum = checksum(packet, PACKET_SIZE);

    ssize_t bytes_sent = sendto(sockfd, packet, PACKET_SIZE, 0,
                                 (struct sockaddr *)dest_addr, sizeof(*dest_addr));
    
    if (bytes_sent <= 0) {
        perror("Error sending packet");
        return;
    }

    printf("Ping sent...\n");
}

// Function to receive a ping response
void receive_ping(int sockfd) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    ssize_t bytes_received;

    bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                              (struct sockaddr *)&from, &fromlen);
    
    if (bytes_received <= 0) {
        perror("Error receiving packet");
        return;
    }

    struct iphdr *ip_hdr = (struct iphdr *)buffer;
    struct icmp *icmp_hdr = (struct icmp *)(buffer + ip_hdr->ihl * 4);

    if (icmp_hdr->icmp_type == ICMP_ECHOREPLY) {
        printf("Received reply from %s: icmp_seq=%d ttl=%d\n",
               inet_ntoa(from.sin_addr), icmp_hdr->icmp_seq, ip_hdr->ttl);
    }
}

// Main function to setup and perform ping testing
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, hostname, &dest_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", hostname);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    printf("Pinging %s...\n", hostname);
    while (1) {
        send_ping(sockfd, &dest_addr);
        sleep(PING_INTERVAL);
        receive_ping(sockfd);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}