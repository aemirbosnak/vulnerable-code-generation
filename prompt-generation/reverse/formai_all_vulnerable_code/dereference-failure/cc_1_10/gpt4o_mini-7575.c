//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TIMEOUT 1

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        return;
    }
    
    // Set up the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip_address);

    // Set the socket to non-blocking
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Try to connect to the server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        // The port is closed
        close(sock);
        return;
    }

    // Port is open
    printf("Port %d is open\n", port);
    close(sock);
}

void scan_ports(const char *ip_address, int start_port, int end_port) {
    printf("Scanning ports from %d to %d on %s\n", start_port, end_port, ip_address);
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Error: Invalid port range. Ports must be between 1 and 65535.\n");
        return 1;
    }

    // Start scanning
    scan_ports(ip_address, start_port, end_port);

    return 0;
}