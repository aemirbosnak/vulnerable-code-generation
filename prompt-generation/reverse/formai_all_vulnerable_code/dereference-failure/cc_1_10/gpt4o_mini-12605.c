//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

#define BUFFER_SIZE 65536
#define BLOCKED_IP "192.168.1.10" // Example IP to block

// Function to check if the incoming packet should be blocked
int should_block(char *src_ip) {
    return strcmp(src_ip, BLOCKED_IP) == 0;
}

// Function to get the IP address in string format from the packet
void get_src_ip(struct iphdr *ip_header, char *ip_str) {
    struct sockaddr_in src_addr;
    src_addr.sin_addr.s_addr = ip_header->saddr;
    strcpy(ip_str, inet_ntoa(src_addr.sin_addr));
}

// Main firewall function
void start_firewall() {
    int raw_socket;
    char buffer[BUFFER_SIZE];
    struct sockaddr saddr;
    socklen_t saddr_len = sizeof(saddr);
    struct iphdr *ip_header;

    // Creating a raw socket to capture packets
    raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (raw_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    printf("Firewall is running and monitoring traffic...\n");

    while (1) {
        // Receive a packet
        ssize_t packet_size = recvfrom(raw_socket, buffer, BUFFER_SIZE, 0, &saddr, &saddr_len);
        if (packet_size < 0) {
            perror("Packet receiving failed");
            continue;
        }

        // Cast the buffer to an IP header structure
        ip_header = (struct iphdr *)buffer;

        // Get the source IP address
        char src_ip[INET_ADDRSTRLEN];
        get_src_ip(ip_header, src_ip);

        // Check if the packet should be blocked
        if (should_block(src_ip)) {
            printf("Blocked packet from %s\n", src_ip);
        } else {
            printf("Allowed packet from %s\n", src_ip);
        }
    }

    // Close the socket
    close(raw_socket);
}

int main() {
    start_firewall();
    return 0;
}