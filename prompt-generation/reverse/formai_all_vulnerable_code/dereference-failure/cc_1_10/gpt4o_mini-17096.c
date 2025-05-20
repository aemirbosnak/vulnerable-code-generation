//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_PORT 65535
#define SCAN_TIMEOUT 1

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct timeval tv;
    
    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Mysterious error in socket creation");
        return;
    }

    // Set socket timeout
    tv.tv_sec = SCAN_TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Preparing server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // Attempting to connect
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Alive! Port %d on %s is open.\n", port, ip);
    } else {
        printf("Silent wasteland... Port %d on %s is closed.\n", port, ip);
    }

    // Closing the socket
    close(sock);
}

void scan_range(const char *ip, int start_port, int end_port) {
    printf("Venture forth! Scanning %s from port %d to %d...\n", ip, start_port, end_port);
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }
    printf("Scanning complete. Retreating to safety...\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("In this forsaken land, you must provide an IP and the port range!\n");
        printf("Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        printf("The path is damaged! Check your port range.\n");
        return EXIT_FAILURE;
    }

    printf("Preparing for the journey...\n");
    printf("Scanning the desolate network for remnants...\n");
    scan_range(ip, start_port, end_port);
    
    return EXIT_SUCCESS;
}