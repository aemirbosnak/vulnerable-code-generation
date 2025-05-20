//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 5
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int addrlen = sizeof(cli_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == 0) {
        printf("socket failed\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        printf("listen failed\n");
        exit(1);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_fd < 0) {
            printf("accept failed\n");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            bzero(buffer, BUF_SIZE);
            memset(buffer, '*', BUF_SIZE);
            send(conn_fd, buffer, strlen(buffer), 0);
        }

        close(conn_fd);
    }

    return 0;
}