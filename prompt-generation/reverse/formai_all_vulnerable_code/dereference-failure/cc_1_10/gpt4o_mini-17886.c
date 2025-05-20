//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define BUFFER_SIZE 1024

void scan_port(const char *ip_address, int port) {
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server.sin_addr);

    // Connect with a timeout
    struct timeval timeout;
    timeout.tv_sec = 1; // 1-second timeout
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Try to connect
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) >= 0) {
        printf("Port %d is open.\n", port);
    } else {
        // Error case
        if (errno != ECONNREFUSED) {
            printf("Error checking port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
}

void print_banner() {
    printf("*********************************\n");
    printf("*       Simple Port Scanner     *\n");
    printf("*********************************\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Port range must be between %d and %d, and start port must be less than end port.\n", MIN_PORT, MAX_PORT);
        exit(EXIT_FAILURE);
    }

    print_banner();
    printf("Scanning IP: %s\n", ip_address);
    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    // Timing the scan
    time_t start_time = time(NULL);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    time_t end_time = time(NULL);
    double duration = difftime(end_time, start_time);
    printf("Scan completed in %.2f seconds.\n", duration);

    return EXIT_SUCCESS;
}