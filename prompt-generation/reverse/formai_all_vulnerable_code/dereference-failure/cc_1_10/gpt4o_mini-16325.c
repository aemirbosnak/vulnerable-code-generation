//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define TIMEOUT 1

void scan_port(const char *ip, int port);
void recursive_scan(const char *ip, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Error: Ports must be between 1 and 65535 and start port must be less than or equal to end port.\n");
        return 1;
    }

    recursive_scan(ip, start_port, end_port);

    return 0;
}

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket.\n");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
    } else {
        // If connection fails, most likely port is closed
        // fprintf(stderr, "Port %d is closed\n", port); // Uncomment for verbose
    }

    close(sock);
}

void recursive_scan(const char *ip, int start_port, int end_port) {
    if (start_port > end_port) {
        return; // base case: end of recursive scanning
    }

    scan_port(ip, start_port); // check the current port
    recursive_scan(ip, start_port + 1, end_port); // recursive call for next port
}