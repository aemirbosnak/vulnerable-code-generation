//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/socket.h>

#define BUFFER_SIZE 65536

// Function to check for a specific packet type (for example, from a blacklisted IP)
int should_block(const struct iphdr *ip_header) {
    // Example rule: Block packets from a specific IP (for demonstration)
    unsigned long block_ip = inet_addr("192.168.1.100");
    if (ip_header->saddr == block_ip) {
        return 1; // Block this packet
    }
    return 0; // Allow this packet
}

// Function to print IP address as string
void print_ip_address(unsigned long ip) {
    struct in_addr ip_addr;
    ip_addr.s_addr = ip;
    printf("%s", inet_ntoa(ip_addr));
}

int main() {
    int sock_raw;
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);

    // Create a raw socket that captures IP packets
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Listening for incoming packets...\n");

    while (1) {
        // Receive packets
        int data_size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, &saddr, (socklen_t*)&saddr_len);
        if (data_size < 0) {
            perror("Recvfrom error");
            return 1;
        }

        // Process the packet
        struct iphdr *ip_header = (struct iphdr *) buffer;
        printf("Packet captured from ");
        print_ip_address(ip_header->saddr);
        printf("\n");

        if (should_block(ip_header)) {
            printf("Packet from ");
            print_ip_address(ip_header->saddr);
            printf(" is blocked.\n");
            // Here we would typically drop the packet, but with raw sockets, we're just printing.
        } else {
            printf("Packet from ");
            print_ip_address(ip_header->saddr);
            printf(" is allowed.\n");
        }

        // Optionally, you could add more checks to handle other protocols
        // or log the packets for analysis

        // Sleep for a brief moment to avoid overwhelming the output
        usleep(10000); // 10ms
    }

    free(buffer);
    close(sock_raw);
    return 0;
}