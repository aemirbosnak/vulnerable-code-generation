//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval timeout;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Define server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        if (errno != EINPROGRESS) {
            // Connection failed: port is closed
            // printf("Port %d is closed\n", port); // Optional: Uncomment if you want feedback on closed ports.
        }
    }

    // Clean up
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range (e.g. 1-100)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port = 0, end_port = 0;

    // Parse port range
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2 ||
        start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please use format <x-y> where x >= %d and y <= %d.\n", MIN_PORT, MAX_PORT);
        exit(EXIT_FAILURE);
    }

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip_address);

    // Scan ports in the specified range
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Port scan completed.\n");
    return 0;
}