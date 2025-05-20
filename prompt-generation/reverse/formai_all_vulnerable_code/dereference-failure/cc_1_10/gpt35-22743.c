//FormAI DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MIN_PORT 1
#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    char *ip_addr;
    int start_port, end_port;
    int sock, conn;
    struct sockaddr_in server;

    if (argc != 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        printf("Example: %s 127.0.0.1 80 443\n", argv[0]);
        return 1;
    }

    ip_addr = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    if (start_port < MIN_PORT) {
        printf("Invalid start port: %d. Minimum port number is %d.\n", start_port, MIN_PORT);
        return 1;
    }

    if (end_port > MAX_PORT) {
        printf("Invalid end port: %d. Maximum port number is %d.\n", end_port, MAX_PORT);
        return 1;
    }

    printf("\nStarting port scan of %s from port %d to %d\n\n", ip_addr, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            return 1;
        }

        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(ip_addr);
        server.sin_port = htons(port);

        conn = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (conn == 0) {
            printf("Port %d - OPEN\n", port);
        }

        close(sock);
    }

    printf("\nPort scan of %s complete.\n", ip_addr);

    return 0;
}