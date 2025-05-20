//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>

// Function prototype
void scan_ports(const char *ip, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\033[1;31mError: Invalid arguments!\033[0m\n");
        printf("Usage: %s <IP> <start_port> <end_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("\033[1;31mError: Ports must be in the range 1-65535 and start_port must be less than or equal to end_port!\033[0m\n");
        return EXIT_FAILURE;
    }

    printf("\033[1;34mStarting the port scan on %s from port %d to %d...\033[0m\n", ip, start_port, end_port);
    scan_ports(ip, start_port, end_port);

    return EXIT_SUCCESS;
}

void scan_ports(const char *ip, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(ip);

        // Set socket options to timeout
        struct timeval timeout;
        timeout.tv_sec = 1;  // 1 second timeout
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (result == 0) {
            printf("\033[0;32mPort %d is open!\033[0m\n", port);
        } else {
            if (errno == ECONNREFUSED) {
                printf("\033[0;31mPort %d is closed!\033[0m\n", port);
            } else {
                printf("\033[0;33mPort %d is filtered or unreachable!\033[0m\n", port);
            }
        }
        close(sock);
    }
    printf("\033[1;34mPort scanning completed!\033[0m\n");
}