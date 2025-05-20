//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>

#define BUF_SIZE 65536

// Function declarations
void process_packet(unsigned char *buffer, int size);
void filter_packets(const char *allowed_ips[], int num_allowed_ips);

const char *allowed_ips[] = {
    "192.168.1.5",
    "192.168.1.10",
    "10.0.0.10"
};

// Function to process incoming packets
void process_packet(unsigned char *buffer, int size) {
    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct in_addr source_ip;

    // Get the source IP address
    source_ip.s_addr = ip_header->saddr;
    
    // Convert IP address to string
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(source_ip), ip_str, INET_ADDRSTRLEN);
    printf("Packet from: %s\n", ip_str);

    // Filter based on allowed IPs
    int allow_packet = 0;
    for(int i = 0; i < sizeof(allowed_ips) / sizeof(allowed_ips[0]); i++) {
        if(strcmp(ip_str, allowed_ips[i]) == 0) {
            allow_packet = 1;
            break;
        }
    }

    if(allow_packet) {
        printf("Allowed packet from: %s\n", ip_str);
    } else {
        printf("Blocked packet from: %s\n", ip_str);
    }
}

// Main function
int main() {
    int sockfd;
    unsigned char *buffer = (unsigned char *)malloc(BUF_SIZE);

    // Create a raw socket
    if((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_IP)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Receive packets promiscuously
    struct sockaddr_in source, dest;
    socklen_t addrlen = sizeof(source);
    while(1) {
        // Clear the buffer
        memset(buffer, 0, BUF_SIZE);

        // Receive packets
        int data_size = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&source, &addrlen);
        if(data_size < 0) {
            perror("Recvfrom error");
            free(buffer);
            close(sockfd);
            return 1;
        }

        // Process the packet
        process_packet(buffer, data_size);
    }

    // Clean up
    free(buffer);
    close(sockfd);
    return 0;
}