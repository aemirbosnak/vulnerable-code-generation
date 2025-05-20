//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <netinet/ip_icmp.h>

#define PACKET_LEN 64
#define TIMEOUT 1

// A mystical structure for our ICMP header
struct icmp_packet {
    struct icmphdr header; // The header of our ICMP packet
    char msg[PACKET_LEN - sizeof(struct icmphdr)]; // Message we send
};

// Magic number for identifying our packets
#define MAGIC_NUMBER 0xDEADBEEF

// Function to calculate the checksum of the packet
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result = 0;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        *(unsigned char *)(&result) = *(unsigned char *)buf;
        sum += result;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

// The enchanting function to send ICMP echo request
int send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct icmp_packet packet;
    memset(&packet, 0, sizeof(packet));
    
    packet.header.type = ICMP_ECHO; // Type echo request
    packet.header.un.echo.id = getpid(); // Use process ID as identifier
    packet.header.un.echo.sequence = seq; // Sequence number
    packet.header.checksum = checksum(&packet, sizeof(packet)); // Calculate checksum

    // Send the packet magically into the void
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Failed to send packet");
        return -1;
    }
    return 0; // Success leaves one to wonder
}

// The mystical oracle to receive an ICMP echo reply
void receive_ping(int sockfd) {
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    char buffer[PACKET_LEN];

    // Waiting in the ethereal void for a response
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
        perror("Failed to receive packet");
    } else {
        struct iphdr *ip_hdr = (struct iphdr *)buffer;
        struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + ip_hdr->ihl * 4);
        // Checking for our echo reply
        if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == getpid()) {
            printf("Received ping response, sequence: %d\n", icmp_hdr->un.echo.sequence);
        }
    }
}

// The grand function to initiate the ping test
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0); // ephemeral port
    inet_pton(AF_INET, ip_address, &addr.sin_addr);
    
    // Create our enchanting socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Unable to open socket");
        exit(EXIT_FAILURE);
    }
    
    // A cosmic loop of ping requests
    for (int i = 1; i <= 5; i++) {
        printf("Sending ping request #%d...\n", i);
        send_ping(sockfd, &addr, i);
        receive_ping(sockfd);
        sleep(TIMEOUT); // Allow the universe a moment to reply
    }

    // Close the socket and retreat to the shadows
    close(sockfd);
}

// The portal of entry into our ping saga
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // The journey begins here, a gateway to the unknown
    ping(argv[1]);
    
    return 0; // The end, but only for now...
}