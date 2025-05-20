//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "socket failed\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        fprintf(stderr, "bind failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "listen failed\n");
        exit(1);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (conn_fd == -1) {
            fprintf(stderr, "accept failed\n");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            bzero(buffer, BUF_SIZE);
            n = recv(conn_fd, buffer, BUF_SIZE, 0);
            if (n <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(conn_fd, buffer, n, 0)!= n) {
                fprintf(stderr, "send failed\n");
                exit(1);
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}