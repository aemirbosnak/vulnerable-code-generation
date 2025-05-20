//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 4096
#define LISTENQ 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int open_listenfd(int port) {
    int listenfd, optval=1;
    struct sockaddr_in serveraddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int)) < 0)
        return -1;

    memset((char *)&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)port);

    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        return -1;

    if (listen(listenfd, LISTENQ) < 0)
        return -1;

    return listenfd;
}

int open_clientfd(char *hostname, int port) {
    int clientfd;
    struct hostent *hp;
    struct sockaddr_in serveraddr;

    if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;

    if ((hp = gethostbyname(hostname)) == NULL)
        return -2;

    memset((char *)&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    memcpy((char *)&serveraddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);
    serveraddr.sin_port = htons(port);

    if (connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        return -1;

    return clientfd;
}

int main(int argc, char **argv) {
    int listenfd, connfd, clientfd, n, proxy_port, server_port;
    struct sockaddr_in clientaddr;
    socklen_t clientlen = sizeof(clientaddr);
    char buf[MAXLINE], server_buf[MAXLINE];
    char *proxy_ip, *server_ip;
    fd_set read_fds, write_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    if (argc != 5) {
        fprintf(stderr, "usage: %s <proxy_ip> <proxy_port> <server_ip> <server_port>\n", argv[0]);
        exit(0);
    }

    proxy_ip = argv[1];
    proxy_port = atoi(argv[2]);
    server_ip = argv[3];
    server_port = atoi(argv[4]);

    if ((clientfd = open_clientfd(server_ip, server_port)) < 0)
        error("open_clientfd error");

    if ((listenfd = open_listenfd(proxy_port)) < 0)
        error("open_listenfd error");

    FD_SET(listenfd, &read_fds);
    FD_SET(clientfd, &read_fds);

    while (1) {
        if (select(FD_SETSIZE, &read_fds, &write_fds, NULL, NULL) < 0) {
            error("select error");
        }

        if (FD_ISSET(listenfd, &read_fds)) {
            if ((connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen)) < 0) {
                error("accept error");
            }

            FD_SET(connfd, &read_fds);
        }

        if (FD_ISSET(clientfd, &read_fds)) {
            if ((n = recv(clientfd, buf, MAXLINE, 0)) < 0) {
                error("recv error");
            }

            if (n == 0) {
                close(clientfd);
                error("server terminated connection");
            }

            if (send(connfd, buf, n, 0) < 0) {
                error("send error");
            }
        }

        if (FD_ISSET(connfd, &read_fds)) {
            if ((n = recv(connfd, buf, MAXLINE, 0)) < 0) {
                error("recv error");
            }

            if (n == 0) {
                close(connfd);
            }

            if (send(clientfd, buf, n, 0) < 0) {
                error("send error");
            }
        }
    }

    return 0;
}