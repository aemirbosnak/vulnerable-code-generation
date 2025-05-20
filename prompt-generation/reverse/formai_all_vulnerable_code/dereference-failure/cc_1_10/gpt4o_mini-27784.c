//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define TIMEOUT 1 // Timeout in seconds
#define MAX_PORT 65535
#define MIN_PORT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        // Port is closed
        close(sock);
        return;
    }

    // Port is open
    printf("Port %d is open\n", port);
    close(sock);
}

void print_usage(const char* prog_name) {
    printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", prog_name);
    printf("Example: %s 192.168.1.1 1 1024\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate IP address format
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address, &(sa.sin_addr));
    if (result != 1) {
        fprintf(stderr, "Invalid IP address format\n");
        return EXIT_FAILURE;
    }

    // Validate port range
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d\n", MIN_PORT, MAX_PORT);
        return EXIT_FAILURE;
    }

    printf("Scanning ports on %s from %d to %d...\n", ip_address, start_port, end_port);
    
    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    printf("Scan completed.\n");
    return EXIT_SUCCESS;
}