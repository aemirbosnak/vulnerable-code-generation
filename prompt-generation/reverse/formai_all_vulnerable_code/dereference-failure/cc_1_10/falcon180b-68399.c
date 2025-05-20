//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_HOST 100
#define MAX_PORT 65535
#define BUF_SIZE 1024

int scan_port(char *hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out on port %d\n", port);
        } else {
            perror("connect");
        }
        close(sock);
        return -1;
    }

    close(sock);
    printf("Port %d is open\n", port);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return -1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    if (port <= 0 || port > MAX_PORT) {
        printf("Invalid port number\n");
        return -1;
    }

    int count = 0;
    for (int i = 1; i <= MAX_PORT; i++) {
        if (scan_port(hostname, i) == 0) {
            count++;
        }
    }

    if (count == 0) {
        printf("No open ports found\n");
    }

    return 0;
}