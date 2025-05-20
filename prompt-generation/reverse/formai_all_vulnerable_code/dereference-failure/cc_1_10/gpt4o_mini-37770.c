//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server_address;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set up the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    // Attempt to connect to the target port
    int connection_status = connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status == 0) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        // If connection is refused, port is closed
        printf("Port %d is closed\n", port);
    } else {
        // Other errors (e.g., unable to reach the server)
        printf("Port %d: %s\n", port, strerror(errno));
    }

    // Close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate the IP address
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    if (result == 0) {
        fprintf(stderr, "Invalid IP address format.\n");
        return 1;
    } else if (result < 0) {
        perror("inet_pton failed");
        return 1;
    }

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d, and start port must be less than or equal to end port.\n", MIN_PORT, MAX_PORT);
        return 1;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Port scan completed.\n");
    return 0;
}