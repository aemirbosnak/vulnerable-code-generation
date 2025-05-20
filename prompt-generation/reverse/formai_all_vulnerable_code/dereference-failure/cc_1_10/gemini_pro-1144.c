//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_PAYLOAD 1024
#define PING_INTERVAL 1000 // milliseconds
#define NUM_PINGS 5

struct ping_packet {
    uint64_t timestamp;
    char payload[MAX_PAYLOAD];
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error resolving hostname: %s\n", argv[1]);
        exit(1);
    }

    // Create a raw ICMP socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int on = 1;
    setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on));

    // Prepare ping packet
    struct ping_packet packet;
    packet.timestamp = gettimeofday();
    memset(packet.payload, 'A', MAX_PAYLOAD);

    // Send ping packets
    int sent = 0, received = 0;
    for (int i = 0; i < NUM_PINGS; i++) {
        // Send packet
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr = *((struct in_addr *)host->h_addr);
        addr.sin_port = htons(0);

        int bytes_sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
        if (bytes_sent == -1) {
            perror("sendto");
            exit(1);
        }
        sent++;

        // Wait for response
        struct sockaddr_in from;
        socklen_t fromlen = sizeof(from);
        int bytes_received = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&from, &fromlen);

        // Check if response matches request
        if (bytes_received > 0 && packet.timestamp == gettimeofday()) {
            received++;
        }

        // Print response
        double rtt = (gettimeofday() - packet.timestamp) / 1000.0; // round-trip time in milliseconds
        if (bytes_received > 0) {
            printf("Reply from %s: bytes=%d time=%.3f ms\n", inet_ntoa(from.sin_addr), bytes_received, rtt);
        } else {
            printf("Request timed out\n");
        }

        // Sleep for interval
        usleep(PING_INTERVAL * 1000);
    }

    // Close socket
    close(sockfd);

    // Print summary
    printf("Sent %d pings, received %d (%.2f%% loss)\n", sent, received, 100.0 * (sent - received) / sent);

    return 0;
}