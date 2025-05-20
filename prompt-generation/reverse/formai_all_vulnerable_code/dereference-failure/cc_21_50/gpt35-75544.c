//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    struct sockaddr_in proxyaddr = {0};
    proxyaddr.sin_family = AF_INET;
    proxyaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxyaddr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *)&proxyaddr, sizeof(proxyaddr)) < 0) {
        perror("bind error");
        exit(1);
    }

    if (listen(sockfd, 10) < 0) {
        perror("listen error");
        exit(1);
    }

    fd_set rset;
    FD_ZERO(&rset);
    FD_SET(sockfd, &rset);

    int maxfd = sockfd;
    int connfd;
    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);

    while (1) {
        fd_set tmpset = rset;
        int nready = select(maxfd+1, &tmpset, NULL, NULL, NULL);
        if (nready < 0) {
            perror("select error");
            continue;
        }
        if (FD_ISSET(sockfd, &tmpset)) {
            connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
            if (connfd < 0) {
                perror("accept error");
                continue;
            }
            FD_SET(connfd, &rset);
            if (connfd > maxfd) maxfd = connfd;
        }
        for (int i = sockfd + 1; i <= maxfd; i++) {
            if (FD_ISSET(i, &tmpset)) {
                char buffer[MAXLINE];
                int n = recv(i, buffer, MAXLINE, 0);
                if (n < 0) {
                    perror("recv error");
                    continue;
                }
                else if (n == 0) {
                    close(i);
                    FD_CLR(i, &rset);
                }
                else {
                    char *p = strstr(buffer, "\r\n");
                    if (p) {
                        char line[MAXLINE];
                        strncpy(line, buffer, p-buffer);
                        line[p-buffer] = '\0';
                        printf("%s\n", line);
                        char *token = strtok(line, " ");
                        token = strtok(NULL, " ");
                        printf("%s\n", token);

                        struct sockaddr_in serveraddr = {0};
                        serveraddr.sin_family = AF_INET;
                        serveraddr.sin_port = htons(80);
                        struct hostent *host = gethostbyname(token);
                        if (host == NULL) {
                            perror("gethostbyname error");
                            exit(1);
                        }
                        memcpy(&serveraddr.sin_addr, host->h_addr, host->h_length);

                        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
                        if (serverfd < 0) {
                            perror("server socket error");
                            exit(1);
                        }

                        int flags = fcntl(serverfd, F_GETFL, 0);
                        fcntl(serverfd, F_SETFL, flags | O_NONBLOCK);

                        if (connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
                            if (errno != EINPROGRESS) {
                                perror("connect error");
                                exit(1);
                            }
                            FD_SET(serverfd, &rset);
                            if (serverfd > maxfd) maxfd = serverfd;
                        }
                    }
                }
            }
        }
        for (int i = sockfd + 1; i <= maxfd; i++) {
            if (FD_ISSET(i, &tmpset)) {
                int error = 0;
                socklen_t len = sizeof(error);
                if (getsockopt(i, SOL_SOCKET, SO_ERROR, &error, &len) < 0 || error != 0) {
                    printf("connect failed\n");
                    close(i);
                    FD_CLR(i, &rset);
                } else {
                    char buffer[MAXLINE];
                    int n = recv(i, buffer, MAXLINE, 0);
                    if (n < 0) {
                        perror("recv error");
                        continue;
                    }
                    else if (n == 0) {
                        close(i);
                        FD_CLR(i, &rset);
                    }
                    else {
                        send(connfd, buffer, n, 0);
                    }
                }
            }
        }
    }
    return 0;
}