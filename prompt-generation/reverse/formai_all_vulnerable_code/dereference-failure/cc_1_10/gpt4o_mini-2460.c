//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define BUFFER_SIZE 65536

// Function to print packet information
void print_packet_info(struct iphdr *ip_header) {
    struct in_addr src_ip, dest_ip;
    src_ip.s_addr = ip_header->saddr;
    dest_ip.s_addr = ip_header->daddr;
    
    printf("Packet captured:\n");
    printf("Source IP: %s\n", inet_ntoa(src_ip));
    printf("Destination IP: %s\n", inet_ntoa(dest_ip));
}

// Function to check filtering rules
int filter_packet(struct iphdr *ip_header) {
    struct in_addr src_ip, dest_ip;
    src_ip.s_addr = ip_header->saddr;
    dest_ip.s_addr = ip_header->daddr;

    // Example filter: Block packets from a specific IP (e.g., 192.168.1.10)
    if (strcmp(inet_ntoa(src_ip), "192.168.1.10") == 0) {
        printf("Blocked packet from %s\n", inet_ntoa(src_ip));
        return 0; // Block the packet
    }

    // Allow all other packets
    return 1; // Allow the packet
}

int main() {
    int sock_raw;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    // Create raw socket
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Allow the socket to receive all packets
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &sock_raw, sizeof(sock_raw)) < 0) {
        perror("Setsockopt failed");
        return 1;
    }

    while (1) {
        // Receive packets
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *)&saddr_len);
        if (data_size < 0) {
            perror("Recvfrom failed");
            return 1;
        }

        // Process the packet
        struct iphdr *ip_header = (struct iphdr *)buffer;
        print_packet_info(ip_header);

        // Check filtering rules
        if (!filter_packet(ip_header)) {
            printf("Packet dropped.\n");
            continue;
        }

        printf("Packet allowed through the firewall.\n");
    }

    // Clean up
    close(sock_raw);
    free(buffer);
    return 0;
}