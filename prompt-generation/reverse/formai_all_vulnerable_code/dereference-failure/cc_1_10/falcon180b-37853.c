//Falcon-180B DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE   1
#define FALSE  0
#define PORT 8080
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Chat server started on port %d\n", atoi(argv[1]));

    while (TRUE) {
        memset(&cliaddr, 0, sizeof(cliaddr));
        socklen_t len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            n = recv(connfd, buffer, MAXLINE, 0);
            if (n == 0) {
                printf("Client disconnected\n");
                close(connfd);
                break;
            } else if (n == -1) {
                perror("recv");
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            send(connfd, buffer, strlen(buffer), 0);
        }
    }

    close(listenfd);
    return 0;
}