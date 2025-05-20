//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>

#define TIMEOUT 1
#define MAX_PORT 65535

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        return;
    }

    // set timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Prepare the sockaddr_in structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ip);
        close(sock);
        return;
    }

    // Try connecting to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        close(sock);
        return; // Port is closed or filtered
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    int start_port, end_port;

    // Check arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    // Validate port range
    if (start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1 and %d and start_port cannot be greater than end_port\n", MAX_PORT);
        exit(EXIT_FAILURE);
    }

    // Display information
    printf("Scanning IP: %s from port %d to %d...\n", ip, start_port, end_port);

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }

    return 0;
}