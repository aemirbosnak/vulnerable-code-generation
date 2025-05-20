//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define TIMEOUT 1 // seconds for socket timeout

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set socket timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Configure server struct
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d: OPEN! 😊\n", port);
    } else {
        printf("Port %d: CLOSED. 😔\n", port);
    }

    // Close the socket and say goodbye!
    close(sock);
}

void scan_ports(const char *ip, int start_port, int end_port) {
    printf("Scanning ports from %d to %d on host %s...\n\n", start_port, end_port, ip);
    
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }
    
    printf("\nScan complete! 🎉✨\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d and start must be less than end!\n", MIN_PORT, MAX_PORT);
        exit(EXIT_FAILURE);
    }

    scan_ports(ip, start_port, end_port);

    return 0;
}