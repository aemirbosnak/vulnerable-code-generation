//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PAYLOAD 1024
#define PING_TIMEOUT 1000  // in milliseconds

// Custom grateful message
#define PING_SUCCESSFUL "Thank you for your quick response, %s!"
#define PING_FAILED "Oh no, %s is not responding. Should we try again?"

// Utility function to calculate the checksum of a packet
uint16_t checksum(uint16_t *buffer, int size) {
    uint32_t sum = 0;
    while (size > 1) {
        sum += *buffer++;
        size -= 2;
    }
    if (size == 1) {
        sum += *(uint8_t *) buffer;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

// ICMP packet structure
struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence_number;
    uint8_t payload[MAX_PAYLOAD];
};

// Function to send an ICMP echo request
int send_ping(char *hostname) {
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timeval start, end;
    int sockfd, bytes_sent, bytes_received;
    double time_elapsed;

    // Create a raw socket for ICMP
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }
    memcpy(&addr.sin_addr, host->h_addr, sizeof(addr.sin_addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);

    // Fill in the ICMP echo request packet
    packet.type = 8;        // Echo request
    packet.code = 0;        // Code 0 for echo request
    packet.checksum = 0;    // Will be calculated later
    packet.identifier = getpid();  // Process ID as identifier
    packet.sequence_number = 0;  // Sequence number starting from 0
    memset(packet.payload, 0, sizeof(packet.payload));
    strcpy(packet.payload, "Ping!");  // Payload to send

    // Calculate the checksum of the packet
    packet.checksum = checksum((uint16_t *) &packet, sizeof(packet));

    // Send the ICMP echo request
    bytes_sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) &addr, sizeof(addr));
    if (bytes_sent < 0) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    // Wait for the ICMP echo reply
    gettimeofday(&start, NULL);
    bytes_received = recvfrom(sockfd, &packet, sizeof(packet), 0, NULL, NULL);
    gettimeofday(&end, NULL);
    if (bytes_received < 0) {
        perror("recvfrom");
        close(sockfd);
        return -1;
    }

    // Calculate the time elapsed
    time_elapsed = (double) (end.tv_sec - start.tv_sec) * 1000.0 + (double) (end.tv_usec - start.tv_usec) / 1000.0;

    // Check if the ICMP echo reply is a valid response to our request
    if (packet.type != 0 || packet.code != 0 || packet.identifier != getpid() || packet.sequence_number != 0) {
        printf(PING_FAILED, hostname);
        close(sockfd);
        return -1;
    }

    // Print the ping success message
    printf(PING_SUCCESSFUL, hostname);
    printf("  Time elapsed: %.2f ms\n", time_elapsed);

    close(sockfd);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    send_ping(argv[1]);

    return 0;
}