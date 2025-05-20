//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, ret;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t conn_len;
    char buffer[MAX_LINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    ret = bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr));
    if (ret == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    ret = listen(listen_fd, BACKLOG);
    if (ret == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        conn_len = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &conn_len);
        if (conn_fd == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while ((ret = recv(conn_fd, buffer, MAX_LINE, 0)) > 0) {
            send(conn_fd, buffer, ret, 0);
        }

        close(conn_fd);
    }

    return 0;
}