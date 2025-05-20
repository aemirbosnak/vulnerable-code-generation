//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    int opt = TRUE;
    int addrlen = sizeof(listen_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == -1) {
        printf("Error setting socket option\n");
        return 1;
    }

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, addrlen) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        char buf[BUF_SIZE];
        int n;

        while ((n = read(conn_fd, buf, BUF_SIZE)) > 0) {
            write(STDOUT_FILENO, buf, n);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}