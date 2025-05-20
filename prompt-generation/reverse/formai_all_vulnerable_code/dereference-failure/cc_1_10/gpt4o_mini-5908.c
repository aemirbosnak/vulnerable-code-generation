//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 1
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate the checksum of the packet
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to send a ping request
int ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct timeval timeout;
    int packets_sent = 0, packets_received = 0;

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize destination address
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Configure timeout for receiving responses
    timeout.tv_sec = PING_TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Prepare the ping packet
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    for (int i = 0; i < sizeof(packet.msg) - 1; i++) {
        packet.msg[i] = 'A';
    }
    packet.msg[sizeof(packet.msg) - 1] = 0;
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    // Send the ping requests
    for (int i = 0; i < PING_COUNT; i++) {
        packets_sent++;
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
        } else {
            struct sockaddr_in r_addr;
            socklen_t r_addr_len = sizeof(r_addr);
            char buffer[PACKET_SIZE];

            // Receive the ping response
            if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&r_addr, &r_addr_len) > 0) {
                struct iphdr *ip_header = (struct iphdr *) buffer;
                struct icmphdr *icmp_header = (struct icmphdr *)(buffer + ip_header->ihl * 4);
                // Validate the response
                if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid()) {
                    packets_received++;
                    printf("Reply from %s: bytes=%d time=%ld ms\n", ip_address,
                           ntohs(ip_header->tot_len) - (ip_header->ihl * 4),
                           (long)(clock() * 1000.0 / CLOCKS_PER_SEC));
                }
            }
        }
        sleep(1); // Wait for 1 second before sending next ping
    }

    // Print summary
    printf("\n--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n",
           packets_sent, packets_received,
           ((packets_sent - packets_received) / (float) packets_sent) * 100);

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}