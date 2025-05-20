//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

// Define constants
#define TIMEOUT 5
#define MIN_PORT 1
#define MAX_PORT 65535

// Define function to scan a given port
int scan_port(int sock, struct sockaddr_in server_addr) {
    // Set server address/port for connection
    server_addr.sin_family = AF_INET;

    // Check if connection is successful
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        if (errno == ECONNREFUSED) {
            // Port is closed
            return 0;
        } else {
            // Error occurred while connecting
            return -1;
        }
    } else {
        // Port is open
        return 1;
    }
}

// Define main function
int main(int argc , char *argv[]) {
    // Check for correct number of arguments
    if (argc < 2) {
        printf("Not enough arguments!\n");
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    // Get IP address
    char *ip_address = argv[1];

    // Open socket
    int sock;
    if ((sock = socket(AF_INET , SOCK_STREAM , 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Set connection timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("Timeout setting error");
        close(sock);
        return 1;
    }

    // Set server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Scan all ports
    int port;
    printf("Scanning ports...\n");
    for (port = MIN_PORT; port <= MAX_PORT; port++) {
        // Set server port
        server_addr.sin_port = htons(port);

        // Scan port
        int result = scan_port(sock, server_addr);

        // Print port status
        if (result == 1) {
            printf("Port %d is open\n", port);
        } else if (result == -1) {
            printf("Error while scanning port %d\n", port);
        }
    }

    // Close socket
    close(sock);

    return 0;
}