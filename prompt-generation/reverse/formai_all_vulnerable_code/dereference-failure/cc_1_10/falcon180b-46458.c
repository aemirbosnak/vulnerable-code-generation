//Falcon-180B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    fd_set readfds;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(listen_fd, BACKLOG);

    FD_ZERO(&readfds);
    FD_SET(listen_fd, &readfds);

    while (TRUE) {
        addrlen = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);

        if (FD_ISSET(conn_fd, &readfds)) {
            if (send(conn_fd, "Welcome to the chat server\n", strlen("Welcome to the chat server\n"), 0) < 0) {
                perror("send");
            }
        }

        FD_SET(conn_fd, &readfds);
    }

    return 0;
}