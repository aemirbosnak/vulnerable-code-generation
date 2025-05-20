//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <errno.h>

// Function to print IP addresses
void print_ip(unsigned char* ip) {
    printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

// Function to handle incoming packets
void handle_packet(unsigned char *buffer, int size) {
    struct iphdr *iph = (struct iphdr*)buffer;

    // Print IP header information
    printf("Packet Info:\n");
    printf("   Source IP: ");
    print_ip((unsigned char*)&iph->saddr);
    printf("\n   Destination IP: ");
    print_ip((unsigned char*)&iph->daddr);
    printf("\n   Protocol: %d\n", iph->protocol);
}

// Main function for packet monitoring
int main() {
    int sock_raw;
    struct sockaddr_in addr;
    int addrlen = sizeof(addr);
    unsigned char *buffer = (unsigned char *)malloc(65536); // Large buffer to store packet data

    // Create a raw socket
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set the socket to receive all packets
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) < 0) {
        perror("Failed to set socket options");
        return 1;
    }

    printf("Listening for packets...\n");

    while (1) {
        // Receive packets
        int packet_size = recvfrom(sock_raw, buffer, 65536, 0, (struct sockaddr *)&addr, (socklen_t *)&addrlen);
        if (packet_size < 0) {
            perror("Recvfrom error");
            return 1;
        }
        
        // Handle the packet
        handle_packet(buffer, packet_size);
    }

    close(sock_raw);
    free(buffer);
    return 0;
}