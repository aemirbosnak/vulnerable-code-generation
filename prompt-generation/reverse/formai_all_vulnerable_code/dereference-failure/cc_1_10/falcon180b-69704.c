//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to scan a single port
void scan_port(int sock, int port) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in target;
    int target_len = sizeof(target);
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &target.sin_addr);

    if (connect(sock, (struct sockaddr *)&target, target_len) == 0) {
        printf("Port %d is open.\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed.\n", port);
    } else {
        printf("Error scanning port %d: %s\n", port, strerror(errno));
    }
}

// Function to scan a range of ports
void scan_range(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return;
    }

    for (int port = start_port; port <= end_port; port++) {
        scan_port(sock, port);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    scan_range(start_port, end_port);

    return 0;
}