//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in listen_addr, conn_addr;
    char buffer[MAX_LINE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    addrlen = sizeof(conn_addr);
    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (1) {
            n = recv(conn_fd, buffer, MAX_LINE, 0);
            if (n == 0) {
                printf("Client disconnected\n");
                close(conn_fd);
                break;
            } else if (n == -1) {
                perror("recv");
                close(conn_fd);
                break;
            }

            send(conn_fd, buffer, n, 0);
        }
    }

    close(listen_fd);
    return 0;
}