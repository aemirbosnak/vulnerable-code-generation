//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define TIMEOUT 1
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;
    fd_set fdset;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    
    // Set the socket options
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        if (errno == EINPROGRESS) {
            printf("Port %d: FILTERED\n", port);
        } else {
            printf("Port %d: CLOSED\n", port);
        }
    }

    // Close the socket
    close(sock);
}

void usage(const char *program_name) {
    printf("Usage: %s <IP> <start-port> <end-port>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate the port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Error: Port range must be between %d and %d\n", MIN_PORT, MAX_PORT);
        return 1;
    }

    printf("Starting scan on host: %s\n", ip_address);
    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
        usleep(1000); // Adding a slight delay to avoid overwhelming the system
    }

    printf("Port scan on host %s completed.\n", ip_address);
    return 0;
}