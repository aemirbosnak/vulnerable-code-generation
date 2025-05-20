//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t addr_len;
    char buffer[MAX_LINE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error: socket() failed\n");
        return 1;
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error: bind() failed\n");
        return 1;
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error: listen() failed\n");
        return 1;
    }

    printf("Proxy server started on port %d\n", port);

    while (1) {
        addr_len = sizeof(conn_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addr_len);
        if (conn_fd == -1) {
            printf("Error: accept() failed\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(conn_fd, buffer, MAX_LINE, 0) <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            printf("Received: %s", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                printf("Error: send() failed\n");
                break;
            }
        }

        close(conn_fd);
    }

    return 0;
}