//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024 /* max text line length */
#define TRUE 1
#define FALSE 0
#define PORT 8080 /* port number */

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAXLINE];
    int n;
    struct hostent *host;
    char hostname[MAXLINE];
    int port;

    if (argc!= 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname error for %s\n", argv[1]);
        exit(1);
    }

    strcpy(hostname, inet_ntoa(*(struct in_addr *)host->h_addr));
    port = atoi(argv[2]);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "bind error\n");
        exit(1);
    }

    if (listen(listenfd, 5) < 0) {
        fprintf(stderr, "listen error\n");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd < 0) {
            fprintf(stderr, "accept error\n");
            exit(1);
        }

        fprintf(stdout, "connected with %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            bzero(buffer, MAXLINE);
            n = read(connfd, buffer, MAXLINE);
            if (n <= 0) {
                fprintf(stdout, "client %s:%d closed\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                close(connfd);
                break;
            }

            fprintf(stdout, "received %d bytes of data\n", n);
            write(connfd, buffer, n);
        }
    }

    return 0;
}