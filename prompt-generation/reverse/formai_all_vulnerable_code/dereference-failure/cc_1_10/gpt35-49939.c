//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT 65535 // Maximum number of ports a TCP/IP connection can have
#define TIMEOUT 1      // Timeout for connection attempt in seconds

int main(int argc, char *argv[]) {
    // Check if enough arguments provided
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <target_ip> [start_port]\n", argv[0]);
        return 1;
    }

    // Get target IP address from argument
    char *target_ip = argv[1];

    // Parse start port if provided, use default otherwise
    int start_port = argc == 3 ? atoi(argv[2]) : 1;

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket. %s\n", strerror(errno));
        return 1;
    }

    // Set timeout for connection attempt
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char *)&timeout, sizeof(timeout));

    // Prepare address structure for target IP
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    // Scan all ports between start_port and MAX_PORT
    printf("Scanning ports from %d to %d on %s...\n", start_port, MAX_PORT, target_ip);
    for (int port = start_port; port <= MAX_PORT; port++) {
        // Set port number for target address
        target_addr.sin_port = htons(port);

        // Attempt to connect to target on current port
        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open!\n", port);
        }
    }

    // Close socket
    close(sock);

    return 0;
}