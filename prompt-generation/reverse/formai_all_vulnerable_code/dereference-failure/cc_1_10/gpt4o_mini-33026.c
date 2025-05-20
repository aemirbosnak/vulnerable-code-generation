//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>

#define BUFFER_SIZE 65536

// Function to check if the packet should be blocked based on rules
int should_block_packet(struct iphdr *ip_header) {
    // Simple rule: block all packets from a specific IP address
    char *block_ip = "192.168.1.10"; // Example IP address to block

    struct sockaddr_in source;
    source.sin_addr.s_addr = ip_header->saddr;
    char *source_ip = inet_ntoa(source.sin_addr);

    if (strcmp(source_ip, block_ip) == 0) {
        printf("Blocked packet from %s\n", source_ip);
        return 1; // Block the packet
    }

    return 0; // Allow the packet
}

int main() {
    int sock_raw;
    struct sockaddr_in addr;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    if ((sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Allow the socket to capture packets
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, NULL, 0) < 0) {
        perror("Setsockopt failed");
        return 1;
    }

    addr.sin_family = AF_INET;

    while (1) {
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (data_size < 0) {
            perror("Recvfrom error");
            return 1;
        }

        struct iphdr *ip_header = (struct iphdr *)buffer;

        // Check if the packet should be blocked
        if (should_block_packet(ip_header)) {
            // If blocked, skip further processing
            continue;
        }

        // Process the packet (for demonstration purposes)
        printf("Packet received from IP: %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));

        // Additional processing can be done here:
        // This could be logging, modifying the packet, etc.
    }

    close(sock_raw);
    free(buffer);
    return 0;
}