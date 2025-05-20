//Falcon-180B DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = TRUE;
    char buffer[1024];

    if (argc < 2) {
        printf("Usage:./chat_server <port>\n");
        exit(0);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        printf("Waiting for connection...\n");
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        if (connfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(connfd, buffer, sizeof(buffer), 0) <= 0) {
                printf("Disconnected\n");
                close(connfd);
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(connfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }
    }

    return 0;
}