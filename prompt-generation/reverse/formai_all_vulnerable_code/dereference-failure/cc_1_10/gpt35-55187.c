//FormAI DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Define the maximum number of ports to scan
#define MAX_PORTS 65535

// Function to scan a single port
void scan_port(int port, char *ip) {
    int socket_desc;
    struct sockaddr_in server;

    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set timeout for the socket
    struct timeval timeout;      
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;      
    if (setsockopt (socket_desc, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("Failed to set timeout for socket");
        exit(EXIT_FAILURE);
    }

    // Set server details
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) {
        if (errno != ECONNREFUSED) {
            perror("Failed to connect to server");
            exit(EXIT_FAILURE);
        }
        else {
            printf("Port %d on %s is closed.\n", port, ip);
        }
    }
    else {
        printf("Port %d on %s is open.\n", port, ip);
    }

    close(socket_desc);
}

int main(int argc, char *argv[]) {
    // Check for user input
    if (argc < 2) {  
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip = argv[1];

    printf("Scanning ports for %s...\n", ip);

    // Scan all ports
    for (int port = 1; port <= MAX_PORTS; port++) {
        scan_port(port, ip);
    }

    return 0;
}