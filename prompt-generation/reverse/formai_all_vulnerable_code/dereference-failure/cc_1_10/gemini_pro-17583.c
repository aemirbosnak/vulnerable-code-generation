//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define ICMP_ECHO_REQUEST 8  // ICMP Echo Request code
#define ICMP_ECHO_REPLY 0   // ICMP Echo Reply code
#define ICMP_HDR_SIZE 8    // Size of ICMP header
#define ICMP_DATA_SIZE 56  // Size of ICMP data

// ICMP header structure
struct icmp_header {
    uint8_t type;           // ICMP type
    uint8_t code;           // ICMP code
    uint16_t checksum;       // ICMP checksum
    uint16_t identification; // ICMP identification
    uint16_t sequence_number; // ICMP sequence number
};

// ICMP data structure
struct icmp_data {
    char data[ICMP_DATA_SIZE]; // ICMP data
};

// Function to calculate ICMP checksum
uint16_t icmp_checksum(struct icmp_header *header, int data_size) {
    uint32_t sum = 0;
    uint16_t *ptr = (uint16_t *)header;
    
    // Calculate 16-bit checksum
    for (int i = 0; i < (data_size / 2); i++) {
        sum += *ptr++;
    }
    
    // Handle odd-sized data
    if (data_size % 2) {
        uint16_t last_byte = *((uint8_t *)ptr);
        sum += last_byte;
    }

    // Fold 32-bit sum into 16-bit checksum
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    
    // Return one's complement of the checksum
    return ~sum;
}

// Function to create an ICMP packet
void create_icmp_packet(struct icmp_header *header, struct icmp_data *data, char *target_ip) {
    // Initialize ICMP header
    header->type = ICMP_ECHO_REQUEST;
    header->code = 0;
    header->checksum = 0;
    header->identification = rand();
    header->sequence_number = rand();
    
    // Initialize ICMP data
    memset(data->data, 0, ICMP_DATA_SIZE);
    strcpy(data->data, "Greetings from the apocalypse!");
    
    // Calculate ICMP checksum
    header->checksum = icmp_checksum(header, ICMP_HDR_SIZE + ICMP_DATA_SIZE);
}

// Function to send an ICMP packet
int send_icmp_packet(char *target_ip) {
    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        return -1;
    }

    // Create ICMP packet
    struct icmp_header header;
    struct icmp_data data;
    create_icmp_packet(&header, &data, target_ip);
    
    // Set destination address
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Send ICMP packet
    int bytes_sent = sendto(sockfd, &header, ICMP_HDR_SIZE + ICMP_DATA_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (bytes_sent < 0) {
        perror("Error sending ICMP packet");
        return -1;
    }

    // Close socket
    close(sockfd);
    
    return 0;
}

// Function to receive an ICMP packet
int receive_icmp_packet(char *target_ip) {
    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }
    
    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        return -1;
    }

    // Set timeout
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting socket timeout");
        return -1;
    }
    
    // Receive ICMP packet
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);
    char buffer[ICMP_HDR_SIZE + ICMP_DATA_SIZE];
    int bytes_received = recvfrom(sockfd, buffer, ICMP_HDR_SIZE + ICMP_DATA_SIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
    if (bytes_received < 0) {
        perror("Error receiving ICMP packet");
        return -1;
    }
    
    // Check ICMP header
    struct icmp_header *header = (struct icmp_header *)buffer;
    if (header->type != ICMP_ECHO_REPLY) {
        printf("Received non-ICMP Echo Reply packet\n");
        return -1;
    }

    // Check ICMP data
    struct icmp_data *data = (struct icmp_data *)(buffer + ICMP_HDR_SIZE);
    if (strcmp(data->data, "Greetings from the apocalypse!") != 0) {
        printf("Received incorrect ICMP data\n");
        return -1;
    }

    // Print ICMP packet information
    printf("Received ICMP Echo Reply packet from %s\n", inet_ntoa(src_addr.sin_addr));
    printf("ICMP data: %s\n", data->data);
    
    // Close socket
    close(sockfd);
    
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <target IP address>\n", argv[0]);
        return 1;
    }
    
    // Send ICMP packet
    if (send_icmp_packet(argv[1]) < 0) {
        return 1;
    }
    
    // Receive ICMP packet
    if (receive_icmp_packet(argv[1]) < 0) {
        return 1;
    }
    
    return 0;
}