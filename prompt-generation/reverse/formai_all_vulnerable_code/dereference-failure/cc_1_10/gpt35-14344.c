//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MIN_PORT 1             // Minimum port number
#define MAX_PORT 65535         // Maximum port number
#define TIMEOUT 3              // Timeout for connection attempts

void scan_port(char *ip_addr, int port_num);

int main(int argc, char *argv[]) {
    char *ip_addr = NULL;
    int st_port = 0, end_port = 0;

    if (argc != 4) {
        printf("Usage: ./portscanner <ip_address> <start_port> <end_port>\n");
        return 1;
    }

    ip_addr = argv[1];
    st_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (st_port <= 0 || end_port <= 0 || st_port > MAX_PORT || end_port > MAX_PORT || st_port > end_port) {
        printf("Invalid input! Please try again.\n");
        return 1;
    }

    printf("Scanning ports %d to %d on %s...\n\n", st_port, end_port, ip_addr);

    for (int i = st_port; i <= end_port; i++) {
        scan_port(ip_addr, i);
    }

    printf("\nScan complete.\n");

    return 0;
}

void scan_port(char *ip_addr, int port_num) {
    int sock = 0, result = 0;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Could not create socket.\n");
        return;
    }

    server.sin_addr.s_addr = inet_addr(ip_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(port_num);

    // Set timeout for connection attempt
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Connect to server
    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d is open.\n", port_num);
    }

    close(sock);
}