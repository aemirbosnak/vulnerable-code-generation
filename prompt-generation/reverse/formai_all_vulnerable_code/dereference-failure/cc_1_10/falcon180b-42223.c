//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int n;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    addrlen = sizeof(client_addr);
    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            n = recv(conn_fd, buffer, MAX_LINE, 0);
            if (n <= 0) {
                if (n == 0)
                    printf("Client disconnected\n");
                else
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