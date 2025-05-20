//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in target;
    int start_port = 1, end_port = MAX_PORTS;

    if (argc < 2) {
        printf("Usage: %s <target_ip> [start_port] [end_port]\n", argv[0]);
        return 1;
    }

    if (argc >= 3) {
        start_port = atoi(argv[2]);
    }

    if (argc >= 4) {
        end_port = atoi(argv[3]);
    }

    char *ip = argv[1];

    printf("Starting cheerful port scan on IP address %s\n", ip);
    printf("Scanning ports %d to %d\n", start_port, end_port);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Setup target address structure
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);

    // Start scanning port range
    for (int port = start_port; port <= end_port; port++) {
        target.sin_port = htons(port);

        // Attempt to connect to target on this port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("\033[32m[*]\033[0m Port %d is open\n", port);
        }
    }

    // Cleanup and exit
    close(sock);
    return 0;
}