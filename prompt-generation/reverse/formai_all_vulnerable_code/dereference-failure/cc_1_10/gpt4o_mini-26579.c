//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define MAX_PORTS 65535

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = 1;  // Timeout of 1 second
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        // Connection failed, port is likely closed.
        printf("Port %d: CLOSED\n", port);
    }

    close(sock);
}

void scan_ports(const char *ip, int start_port, int end_port) {
    if(start_port < 0 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        return;
    }
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Validate IP address format
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result <= 0) {
        fprintf(stderr, "Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    scan_ports(ip, start_port, end_port);
    printf("Scanning completed!\n");

    return EXIT_SUCCESS;
}