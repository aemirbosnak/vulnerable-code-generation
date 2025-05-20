//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "bind() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "listen() failed: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        addr_size = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (conn_fd == -1) {
            fprintf(stderr, "accept() failed: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(conn_fd, buffer, MAX_LINE, 0) <= 0) {
                fprintf(stdout, "Client disconnected\n");
                break;
            }

            fprintf(stdout, "Received: %s", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) == -1) {
                fprintf(stderr, "send() failed: %s\n", strerror(errno));
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}