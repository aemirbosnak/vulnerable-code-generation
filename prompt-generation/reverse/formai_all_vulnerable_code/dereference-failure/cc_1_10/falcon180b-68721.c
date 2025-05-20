//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_LINE 1024
#define BACKLOG 10

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t addr_len;
    char buffer[MAX_LINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        error("socket");
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        error("bind");
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        error("listen");
    }

    while (1) {
        addr_len = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addr_len);
        if (conn_fd == -1) {
            error("accept");
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            ssize_t bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                break;
            }

            ssize_t bytes_sent = send(conn_fd, buffer, bytes_received, 0);
            if (bytes_sent!= bytes_received) {
                error("send");
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}