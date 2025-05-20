//FormAI DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PACKET_FILTER_PORT 80

void packet_filter(unsigned char* buffer, int size);

int main() {
    int sock_raw;
    struct sockaddr_in saddr;

    // Create socket
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket Error");
        return 1;
    }

    // Set socket options
    int on = 1;
    if (setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
        perror("Setsockopt Error");
        return 1;
    }

    // Bind to all network interfaces and listen for incoming packets
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(PACKET_FILTER_PORT);
    if (bind(sock_raw, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
        perror("Bind Error");
        return 1;
    }

    // Listen for incoming packets
    unsigned char* buffer = (unsigned char*)malloc(65536);
    int data_size;
    while (1) {
        data_size = recvfrom(sock_raw, buffer, 65536, 0, NULL, NULL);
        if (data_size < 0) {
            perror("Recvfrom Error");
            continue;
        }
        packet_filter(buffer, data_size);
    }

    free(buffer);
    close(sock_raw);

    return 0;
}

void packet_filter(unsigned char* buffer, int size) {
    struct iphdr* ip_header = (struct iphdr*) buffer;

    if (ip_header->protocol == IPPROTO_TCP) {
        struct tcphdr* tcp_header = (struct tcphdr*) (buffer + sizeof(struct iphdr));

        // Check if the destination port is 80 (HTTP)
        if (ntohs(tcp_header->dest) == PACKET_FILTER_PORT) {
            printf("HTTP packet blocked\n");
            return;
        }
    }

    // If this point is reached, the packet can pass through the firewall
    printf("Packet Allowed\n");
}