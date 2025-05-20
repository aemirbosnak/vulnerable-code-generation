//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 65536

// Function to compute the checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create a raw socket
int create_raw_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to set the socket options
void set_socket_options(int sockfd) {
    int opt = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }
}

// Function to log packets
void log_packet(const char *packet) {
    FILE *log_file = fopen("firewall_log.txt", "a");
    if (log_file == NULL) {
        perror("Log file opening failed");
        return;
    }
    fprintf(log_file, "%s\n", packet);
    fclose(log_file);
}

// Function to filter packets
bool filter_packet(struct iphdr *ip_header) {
    // Example filter: block packets from a specific IP address
    const char *blocked_ip = "192.168.1.10"; // IP to block
    if (strcmp(inet_ntoa(*(struct in_addr *)&ip_header->saddr), blocked_ip) == 0) {
        return true; // Block the packet
    }
    return false; // Allow the packet
}

// Main function
int main() {
    int sockfd = create_raw_socket();
    set_socket_options(sockfd);

    char *buffer = (char *)malloc(BUFFER_SIZE);
    struct sockaddr_in source_addr;
    socklen_t addr_len = sizeof(source_addr);

    printf("Firewall is running. Monitoring packets...\n");

    while (true) {
        // Receive a packet
        ssize_t packet_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                                       (struct sockaddr *)&source_addr, &addr_len);
        if (packet_size < 0) {
            perror("Packet capture failed");
            free(buffer);
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        struct iphdr *ip_header = (struct iphdr *)buffer;

        // Check if the packet should be filtered
        if (filter_packet(ip_header)) {
            printf("Blocked packet from %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
            continue; // Skip logging and processing blocked packets
        }

        // Log the allowed packet
        log_packet(inet_ntoa(*(struct in_addr *)&ip_header->saddr));
        printf("Allowed packet from %s\n", inet_ntoa(*(struct in_addr *)&ip_header->saddr));
    }

    free(buffer);
    close(sockfd);
    return 0;
}