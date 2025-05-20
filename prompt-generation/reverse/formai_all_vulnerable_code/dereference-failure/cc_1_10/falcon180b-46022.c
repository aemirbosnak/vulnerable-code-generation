//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;
    int port = 8080;
    int opt = 1;
    char *ip = "127.0.0.1";

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server listening on port %d\n", port);

    while (1) {
        addrlen = sizeof(client_addr);
        if ((conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(conn_fd, buffer, MAX_LINE, 0) <= 0) {
                printf("Client disconnected\n");
                close(conn_fd);
                break;
            }

            send(conn_fd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}