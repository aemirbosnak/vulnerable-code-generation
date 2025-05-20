//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8888
#define BACKLOG 10
#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[BUFFERSIZE];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUFFERSIZE);
            if (recv(connfd, buffer, BUFFERSIZE, 0) <= 0) {
                if (errno!= ECONNRESET) {
                    perror("recv");
                }
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(connfd, buffer, strlen(buffer), 0) < 0) {
                perror("send");
            }
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}