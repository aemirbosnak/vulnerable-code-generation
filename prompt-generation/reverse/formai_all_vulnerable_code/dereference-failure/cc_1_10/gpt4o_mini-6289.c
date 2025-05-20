//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }
    
    // Setup structure to connect to the server
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Set the socket to non-blocking
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        if (errno == EINPROGRESS) {
            close(sock);
            printf("Port %d is closed or filtered on %s\n", port, ip);
        } else {
            printf("Port %d is closed on %s\n", port, ip);
        }
    } else {
        printf("Port %d is open on %s\n", port, ip);
    }

    // Close the socket
    close(sock);
}

void scan_ports(const char *ip) {
    printf("Scanning ports on %s...\n", ip);
    for (int port = MIN_PORT; port <= MAX_PORT; port++) {
        scan_port(ip, port);
    }
    printf("Port scanning completed on %s!\n", ip);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address from the command line
    const char *ip_address = argv[1];
    
    // Check if the IP address is valid
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    if (result <= 0) {
        fprintf(stderr, "Invalid IP address format: %s\n", ip_address);
        return EXIT_FAILURE;
    }

    // Start scanning
    scan_ports(ip_address);

    return EXIT_SUCCESS;
}