//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define ATTEMPTS 4

typedef struct {
    struct sockaddr_in address;
    char ip[INET_ADDRSTRLEN];
    int packet_size;
    int timeout;
    int attempts;
} PingTest;

// Color codes for terminal
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Utility function to set the address
void set_address(PingTest *ping_test, const char *hostname) {
    memset(&ping_test->address, 0, sizeof(ping_test->address));
    ping_test->address.sin_family = AF_INET;
    ping_test->address.sin_port = htons(0); // Port 0 for ICMP
    inet_pton(AF_INET, hostname, &ping_test->address.sin_addr);
    strncpy(ping_test->ip, hostname, sizeof(ping_test->ip) - 1);
}

// Function to perform the ping test
void ping(PingTest *ping_test) {
    int sockfd;
    char packet[PACKET_SIZE];
    struct timespec start, end;
    double elapsed;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    // Creating a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ping_test->attempts; i++) {
        // Setting packet data
        memset(packet, 0, PACKET_SIZE);
        // Here we're just sending a "ping" packet
        sprintf(packet, "Ping #%d", i + 1);

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&ping_test->address, sizeof(ping_test->address)) < 0) {
            perror("Failed to send packet");
            continue;
        }

        // Receive response
        if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&addr, &addr_len) < 0) {
            perror("No response");
            printf(RED "Ping to %s failed\n" RESET, ping_test->ip);
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0; // milliseconds

        printf(GREEN "Ping to %s: %f ms\n" RESET, ping_test->ip, elapsed);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    PingTest ping_test;
    ping_test.packet_size = PACKET_SIZE;
    ping_test.timeout = TIMEOUT;
    ping_test.attempts = ATTEMPTS;

    set_address(&ping_test, argv[1]);
    ping(&ping_test);

    return 0;
}