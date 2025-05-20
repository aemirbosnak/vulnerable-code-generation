//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PORT 65535

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Could not create socket\n");
        return;
    }

    // Set up the server structure for the target IP and port
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Attempt to connect to the target
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is open\n", port);
    }

    // Close the socket
    close(sock);
}

void recursive_scan(const char *ip, int start_port, int end_port) {
    if (start_port > end_port) {
        return; // Base case: no more ports to scan
    }

    // Recursively scan the next port
    scan_port(ip, start_port);
    recursive_scan(ip, start_port + 1, end_port);
}

int main(int argc, char *argv[]) {
    char *ip;
    int start_port, end_port;

    // Check for correct number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range is invalid. Must be between 1 and %d.\n", MAX_PORT);
        return 1;
    }

    printf("Scanning IP: %s from port %d to %d...\n", ip, start_port, end_port);
    recursive_scan(ip, start_port, end_port);
    printf("Scan complete.\n");

    return 0;
}