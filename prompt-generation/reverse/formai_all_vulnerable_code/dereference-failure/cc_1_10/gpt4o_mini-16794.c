//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define MAX_PORT 65535
#define TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Fill server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // Attempt connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            // Connection refused, port is closed
            printf("Port %d is closed\n", port);
        }
        // Other errors can be ignored for scanning purposes
    }

    // Close socket
    close(sockfd);
}

void scan_ports(const char *ip) {
    printf("Scanning ports for IP: %s\n", ip);
    for (int port = 1; port <= MAX_PORT; port++) {
        scan_port(ip, port);
        // Optional: Sleep to avoid network congestion
        // usleep(1000); // 1ms delay
    }
    printf("Port scan completed for IP: %s\n", ip);
}

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    
    // Start scanning ports
    clock_t start_time = clock();
    scan_ports(ip_address);
    clock_t end_time = clock();

    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to complete scan: %.2f seconds\n", time_spent);
    
    return EXIT_SUCCESS;
}