//Falcon-180B DATASET v1.0 Category: Chat server ; Style: inquisitive
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
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAXLINE];
    int n;

    if (argc!= 2) {
        printf("usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Chat server is running on port %d\n", PORT);

    while (TRUE) {
        socklen_t len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Client connected, IP: %s, Port: %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            bzero(buff, MAXLINE);
            n = read(connfd, buff, MAXLINE);
            if (n == 0) {
                printf("Client disconnected\n");
                break;
            } else if (n == -1) {
                perror("read");
                break;
            }

            write(connfd, buff, n);
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}