//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(sock);
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            die("connect");
        }
        exit(1);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
    return 0;
}