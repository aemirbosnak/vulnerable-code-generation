//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define TRUE   1
#define FALSE  0
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = 1;
    char *ip = "127.0.0.1";
    int port = 8080;
    pid_t pid;

    if (argc > 1) {
        ip = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t *)&opt);

        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            close(listenfd);

            send(connfd, "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n", 45, 0);

            char *html = "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "<title>Simple Web Server</title>\n"
                        "</head>\n"
                        "<body>\n"
                        "<h1>Hello World!</h1>\n"
                        "</body>\n"
                        "</html>\n";

            send(connfd, html, strlen(html), 0);

            close(connfd);
            exit(0);
        } else {
            close(connfd);
        }
    }

    return 0;
}