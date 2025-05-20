//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    char buf[BUF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server listening on port %d\n", ntohs(listen_addr.sin_port));

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, sizeof(conn_addr));
        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (1) {
            memset(buf, 0, BUF_SIZE);
            ssize_t bytes_received = recv(conn_fd, buf, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
                break;
            }

            ssize_t bytes_sent = send(conn_fd, buf, bytes_received, 0);
            if (bytes_sent <= 0) {
                fprintf(stderr, "Error sending data: %s\n", strerror(errno));
                break;
            }
        }

        close(conn_fd);
    }

    return 0;
}