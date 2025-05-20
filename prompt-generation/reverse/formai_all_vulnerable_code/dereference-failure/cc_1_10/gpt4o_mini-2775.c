//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define TIMEOUT_SEC 1

void scan_port(const char* ip, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct timeval timeout;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set socket timeout
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Failed to set socket options");
        close(sock);
        return;
    }

    // Prepare sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(sock);
        return;
    }

    // Attempt to connect to the target port
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        // Check if the error is a connection refused error
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        }
    }

    // Close the socket
    close(sock);
}

void scan_ports(const char* ip, int start_port, int end_port) {
    if (start_port < 0 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range: %d-%d\n", start_port, end_port);
        return;
    }

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Scan specified ports
    scan_ports(ip, start_port, end_port);
    
    return EXIT_SUCCESS;
}