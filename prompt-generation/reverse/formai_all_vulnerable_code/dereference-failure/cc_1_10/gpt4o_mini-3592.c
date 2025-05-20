//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Calculate the checksum of the packet
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

// Create an ICMP packet
struct icmp *create_packet(int seq) {
    struct icmp *icmp_packet = (struct icmp *)malloc(sizeof(struct icmp));
    icmp_packet->icmp_type = ICMP_ECHO; // Echo Request
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid();
    icmp_packet->icmp_seq = seq;
    icmp_packet->icmp_cksum = 0; // Checksum will be calculated later
    memset(icmp_packet->icmp_data, 0, PACKET_SIZE - sizeof(struct icmp));
    icmp_packet->icmp_cksum = checksum(icmp_packet, sizeof(struct icmp));

    return icmp_packet;
}

// Send an ICMP echo request
void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct icmp *icmp_packet = create_packet(seq);
    sendto(sockfd, icmp_packet, sizeof(struct icmp), 0, (struct sockaddr *)addr, sizeof(*addr));
    free(icmp_packet);
}

// Receiver function to capture the ping replies
void receive_pong(int sockfd) {
    char buffer[PACKET_SIZE];
    int addr_len = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;
    
    while (1) {
        ssize_t bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len);
        if (bytes_received < 0) {
            perror("recvfrom");
            break;
        }

        struct iphdr *ip_header = (struct iphdr *)buffer;
        struct icmp *icmp_header = (struct icmp *)(buffer + ip_header->ihl * 4);

        if (icmp_header->icmp_type == ICMP_ECHOREPLY && icmp_header->icmp_id == getpid()) {
            printf("Received reply from %s: seq=%d bytes=%ld\n",
                   inet_ntoa(addr.sin_addr), icmp_header->icmp_seq, bytes_received);
            break;
        }
    }
}

// Main function for the ping test
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s:\n", hostname);
    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(sockfd, &addr, i + 1);
        receive_pong(sockfd);
        sleep(1);
    }

    close(sockfd);
    return 0;
}