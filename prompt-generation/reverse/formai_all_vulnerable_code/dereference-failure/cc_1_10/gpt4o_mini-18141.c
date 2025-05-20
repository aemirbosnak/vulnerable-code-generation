//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 65536

// Packet Handling Function
void handle_packet(unsigned char *buffer, int size) {
    struct iphdr *ip_header = (struct iphdr*) buffer;
    struct sockaddr_in source, dest;

    memset(&source, 0, sizeof(source));
    memset(&dest, 0, sizeof(dest));

    source.sin_addr.s_addr = ip_header->saddr;
    dest.sin_addr.s_addr = ip_header->daddr;

    printf("Packet captured from %s to %s\n", inet_ntoa(source.sin_addr), inet_ntoa(dest.sin_addr));
    
    // Rule: Block packets from a specific IP address (e.g., 192.168.1.100)
    if (strcmp(inet_ntoa(source.sin_addr), "192.168.1.100") == 0) {
        printf("Blocked packet from %s\n", inet_ntoa(source.sin_addr));
        return;
    }

    // Allowing all other packets
    printf("Allowed packet from %s to %s\n", inet_ntoa(source.sin_addr), inet_ntoa(dest.sin_addr));
}

// Main function
int main() {
    int sock_raw;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *) malloc(BUFFER_SIZE);

    // Create a raw socket that shall sniff packets
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket Creation Error");
        return 1;
    }

    printf("Surprising C Firewall running... 🚀\n");

    while (1) {
        // Receive packets
        int bytes_received = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);
        if (bytes_received < 0) {
            perror("Recvfrom Error");
            break;
        }

        // Handle the captured packet
        handle_packet(buffer, bytes_received);
    }

    // Clean up
    close(sock_raw);
    free(buffer);
    return 0;
}