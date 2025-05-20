//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <linux/if_ether.h>

#define BUFFER_SIZE 65536  // Buffer size to receive packets

void process_packet(unsigned char *buffer, int size) {
    struct ethhdr *eth = (struct ethhdr *)buffer;  // Get Ethernet header
    
    // Print source and destination MAC addresses
    printf("Source MAC: %s\n", ether_ntoa((struct ether_addr *)eth->h_source));
    printf("Destination MAC: %s\n", ether_ntoa((struct ether_addr *)eth->h_dest));
    
    // Check for IP packet
    if (ntohs(eth->h_proto) == ETH_P_IP) {
        struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));  // Get IP header

        // Print basic IP info
        printf("Protocol: %d\n", ip->protocol);
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
        printf("-----------------------------\n");
    }
}

int main() {
    int sock_raw;
    struct sockaddr saddr;
    struct sockaddr_in *ip_saddr = (struct sockaddr_in *)&saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    // Create a raw socket
    sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(sock_raw < 0) {
        perror("Socket Creation Error");
        return 1;
    }

    // Capture packets
    while (1) {
        int packet_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *)&saddr_len);
        if (packet_size < 0) {
            perror("Recvfrom Error");
            return 1;
        }

        process_packet(buffer, packet_size);
    }

    close(sock_raw);
    free(buffer);
    return 0;
}