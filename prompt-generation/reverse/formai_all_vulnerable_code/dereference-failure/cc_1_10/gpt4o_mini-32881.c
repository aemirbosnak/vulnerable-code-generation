//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_PORT 65535
#define TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server;
    int result;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Could not create socket\n");
        return;
    }

    // Set timeout option
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Set up the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Attempt to connect
    result = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }

    // Close the socket
    close(sockfd);
}

void scan_ports(const char *ip, int start_port, int end_port) {
    if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        return;
    }
    
    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip);
    
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
        fflush(stdout);  // Ensure immediate output
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(ip_address, start_port, end_port);

    return EXIT_SUCCESS;
}