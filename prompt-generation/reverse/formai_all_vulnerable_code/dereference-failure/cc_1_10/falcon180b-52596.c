//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    int addrlen;
    char buf[BUF_SIZE];
    int n;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (TRUE) {
            n = recv(conn_fd, buf, BUF_SIZE, 0);
            if (n <= 0) {
                printf("Connection closed\n");
                break;
            }

            send(conn_fd, buf, n, 0);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}