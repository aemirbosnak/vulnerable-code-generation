//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <time.h>

#define TIMEOUT 1  // Set a timeout for connections
#define BUFFER_SIZE 1024

// Function to gently check if a port is open
int is_port_open(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create a calming socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return 0;
    }

    // Setting the timeout for the connection
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Prepare the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    // Attempt to connect to the soothing server
    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
    
    close(sock);
    return (result == 0);
}

// Function to scan a range of ports quietly and mindfully
void scan_ports(const char *ip, int start_port, int end_port) {
    printf("Gently scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("Port %d is open. 🌼\n", port);
        } else {
            printf("Port %d is closed. 🌱\n", port);
        }
        // Sleep to ease the scan process
        usleep(50000);  // 50 milliseconds
    }
    printf("Scanning completed. May peace be with you. ☮️\n");
}

// Main function that brings tranquility to the process
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Please provide a valid range of ports (1-65535).\n");
        return 1;
    }

    scan_ports(ip, start_port, end_port);
    return 0;
}