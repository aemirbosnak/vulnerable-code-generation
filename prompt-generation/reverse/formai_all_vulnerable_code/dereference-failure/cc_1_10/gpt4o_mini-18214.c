//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT 65535
#define TIMEOUT 1

int scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 0;  // Can't open the port
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;  // 1 second timeout
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));
    
    // Prepare the server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        perror("Invalid IP address");
        close(sock);
        return 0;
    }

    // Attempt to connect
    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    close(sock);

    // Check if connection was successful
    return result == 0;
}

void print_banner(const char *ip, int start_port, int end_port) {
    printf("======================================\n");
    printf("         PORT SCANNER v1.0           \n");
    printf("--------------------------------------\n");
    printf("Scanning IP: %s\n", ip);
    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    printf("======================================\n\n");
}

void scan_ports(const char *ip, int start_port, int end_port) {
    printf("Port\tStatus\n");
    printf("---------------------\n");
    
    for (int port = start_port; port <= end_port; port++) {
        if (scan_port(ip, port)) {
            printf("%d\tOPEN\n", port);
        } else {
            printf("%d\tCLOSED\n", port);
        }
    }
    printf("---------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range! Must be from 1 to %d.\n", MAX_PORT);
        return 1;
    }

    print_banner(ip, start_port, end_port);
    scan_ports(ip, start_port, end_port);

    return 0;
}