//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT 1

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        return;
    }

    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    
    // Setup the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip_address);

    // Attempt to connect to the server
    int connection_status = connect(sock, (struct sockaddr *)&server, sizeof(server));
    
    // Check if the port is open
    if (connection_status == 0) {
        printf("Port %d is OPEN\n", port);
    } else {
        printf("Port %d is CLOSED\n", port);
    }
    
    // Close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range. Please enter ports between 1 and 65535.\n");
        return 1;
    }

    printf("Scanning %s from port %d to %d...\n", ip_address, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Scanning completed!\n");
    return 0;
}