//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t addrlen;

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
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server listening on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        char buffer[MAX_LINE];
        while (fgets(buffer, MAX_LINE, stdin)!= NULL) {
            send(conn_fd, buffer, strlen(buffer), 0);
        }

        close(conn_fd);
    }

    return 0;
}