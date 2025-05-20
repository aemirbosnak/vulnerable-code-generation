//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to check if a port is open
int is_port_open(const char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed!");
        return 0;
    }

    // Setting up the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Attempt to connect to the server
    int connection_status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Close the socket after connection attempt
    close(sock);

    // If connection is successful, the port is open
    return connection_status == 0;
}

// Function to perform the port scan
void scan_ports(const char *host, int start_port, int end_port) {
    printf("🕵️‍♀️ Scanning ports on %s from %d to %d...\n", host, start_port, end_port);
    
    // Loop through the given range of ports
    for (int port = start_port; port <= end_port; port++) {
        // Check if the port is open
        if (is_port_open(host, port)) {
            printf("✅ Port %d is open!\n", port);
        } else {
            printf("❌ Port %d is closed.\n", port);
        }
    }
    
    printf("🔍 Port scan completed on %s!\n", host);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Ensure the port range is valid
    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range! Please enter values between 1 and 65535.\n");
        exit(EXIT_FAILURE);
    }

    // Start the scanning journey
    scan_ports(host, start_port, end_port);
    
    return 0;
}