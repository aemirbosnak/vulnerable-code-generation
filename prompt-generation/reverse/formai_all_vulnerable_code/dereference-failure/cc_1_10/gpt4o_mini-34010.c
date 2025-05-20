//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 65536
#define ALLOWED_IP "192.168.1.100"

void handle_packet(unsigned char *buffer, int size) {
    struct iphdr *ip = (struct iphdr *)buffer;
    struct sockaddr_in source, dest;

    memset(&source, 0, sizeof(source));
    memset(&dest, 0, sizeof(dest));
    
    source.sin_addr.s_addr = ip->saddr; // Source IP
    dest.sin_addr.s_addr = ip->daddr;   // Destination IP

    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &source.sin_addr, source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &dest.sin_addr, dest_ip, INET_ADDRSTRLEN);

    // Check if the packet is from the allowed IP
    if (strcmp(source_ip, ALLOWED_IP) == 0) {
        printf("Allowed packet from %s to %s\n", source_ip, dest_ip);
    } else {
        printf("Blocked packet from %s to %s\n", source_ip, dest_ip);
    }
}

int main() {
    int sock_raw;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    // Create a raw socket that uses the IP protocol
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket Creation Failed");
        return 1;
    }
    
    while (1) {
        // Receive packets
        int packet_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t *)&saddr_len);
        if (packet_size < 0) {
            perror("Failed to get packets");
            free(buffer);
            close(sock_raw);
            return 1;
        }
        handle_packet(buffer, packet_size);
    }

    free(buffer);
    close(sock_raw);
    return 0;
}