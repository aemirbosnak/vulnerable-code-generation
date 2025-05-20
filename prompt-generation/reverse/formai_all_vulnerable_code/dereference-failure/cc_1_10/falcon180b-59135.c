//Falcon-180B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd, addrlen;
    struct sockaddr_in servaddr, cliaddr;
    char *message;
    int n;

    if (argc!= 2) {
        printf("usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd == -1) {
        printf("socket failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        printf("listen failed\n");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);

        if (connfd == -1) {
            printf("accept failed\n");
            exit(1);
        }

        message = malloc(MAXLINE);

        if (message == NULL) {
            printf("malloc failed\n");
            exit(1);
        }

        n = read(connfd, message, MAXLINE);

        if (n == -1) {
            printf("read failed\n");
            exit(1);
        }

        message[n] = '\0';

        printf("client message: %s\n", message);

        write(connfd, message, strlen(message));

        close(connfd);
    }

    return 0;
}