//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>

#define TIMEOUT 1 // Timeout for socket connection attempts in seconds
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set the socket timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return;
    }

    // Try to connect to the given port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open on %s\n", port, ip);
    } else {
        // Check if the error is due to the connection timeout
        if (errno != ECONNREFUSED) {
            printf("Port %d is filtered on %s\n", port, ip);
        } else {
            printf("Port %d is closed on %s\n", port, ip);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Valid range is from %d to %d.\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Scanning ports on %s from %d to %d...\n", ip, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}