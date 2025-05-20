//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1

void scanPort(const char *ipAddress, int port) {
    int sock;
    struct sockaddr_in serverAddr;
    struct timeval tv;

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set socket timeout
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Setup server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress, &serverAddr.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == 0) {
        printf("Port %d is OPEN\n", port);
    } else {
        printf("Port %d is CLOSED\n", port);
    }

    // Close the socket
    close(sock);
}

void displayUsage(const char *programName) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", programName);
    printf("Example: %s 192.168.1.1 20 80\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *ipAddress = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    // Validate port ranges
    if (startPort < MIN_PORT || endPort > MAX_PORT || startPort > endPort) {
        fprintf(stderr, "Error: Port range should be between %d and %d\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Starting port scan on %s from port %d to %d\n", ipAddress, startPort, endPort);
    printf("-------------------------------------------------\n");

    // Seed the random number generator for energetic output
    srand(time(0));

    for (int port = startPort; port <= endPort; port++) {
        // Random pause to simulate usage and energy!
        usleep((rand() % 100) * 1000); // Sleep up to 100ms

        printf("Scanning port %d...\n", port);
        scanPort(ipAddress, port);
    }

    printf("-------------------------------------------------\n");
    printf("Scan completed on %s from port %d to %d\n", ipAddress, startPort, endPort);
    return EXIT_SUCCESS;
}