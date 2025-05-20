//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in target;
    socklen_t addr_len = sizeof(target);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout for the socket
    struct timeval tv;
    tv.tv_sec = TIMEOUT;  // 1 second
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &target.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(sockfd);
        return;
    }

    // Attempt to connect
    int connection_status = connect(sockfd, (struct sockaddr *)&target, addr_len);

    if (connection_status == 0) {
        printf("Port %d is OPEN on %s\n", port, ip);
    } else {
        printf("Port %d is CLOSED on %s\n", port, ip);
    }

    close(sockfd);
}

void display_banner() {
    printf("\n==============================================\n");
    printf("          ☢️  Surprise Port Scanner ☢️        \n");
    printf("==============================================\n");
    printf("               (C) 2023 - Portify              \n");
    printf("  Scanning for open ports is super fun!       \n");
    printf("==============================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <PORT NUMBER>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    display_banner();

    // Check for valid port range
    if (start_port < 1 || end_port > MAX_PORT) {
        fprintf(stderr, "Port number must be between 1 and 65535.\n");
        return 1;
    }

    printf("Scanning %s from port %d to port %d...\n", ip, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
        // Adding a delay to avoid overwhelming the target
        usleep(500000); // Sleep for 0.5 seconds
    }

    printf("\nScanning completed.\n");
    printf("==============================================\n");

    return 0;
}