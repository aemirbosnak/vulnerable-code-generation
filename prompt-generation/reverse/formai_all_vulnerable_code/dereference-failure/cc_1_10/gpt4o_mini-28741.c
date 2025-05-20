//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define TIMEOUT 1
#define MAX_PORT 65535

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // Attempt to connect
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Port %d is open.\n", port);
    }

    // Close the socket
    close(sock);
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", prog_name);
    fprintf(stderr, "Example: %s 192.168.0.1 20 80\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int start_port, end_port;

    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Ports must be between 1 and %d.\n", MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);
    
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Port scan completed.\n");
    return EXIT_SUCCESS;
}