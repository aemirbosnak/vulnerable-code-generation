//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buff[BUFF_SIZE], method[BUFF_SIZE], path[BUFF_SIZE], version[BUFF_SIZE];
    int n, i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return -1;
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(listenfd, 10) < 0) {
        perror("listen");
        return -1;
    }

    for (;;) {
        socklen_t len = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
            perror("accept");
            continue;
        }

        n = recv(connfd, buff, BUFF_SIZE, 0);
        if (n < 0) {
            perror("recv");
            continue;
        }

        buff[n] = '\0';

        sscanf(buff, "%s %s %s", method, path, version);

        if (strcmp(method, "GET") != 0) {
            fprintf(stderr, "Only GET method is supported\n");
            close(connfd);
            continue;
        }

        if (strcmp(version, "HTTP/1.1") != 0) {
            fprintf(stderr, "Only HTTP/1.1 version is supported\n");
            close(connfd);
            continue;
        }

        char *host = NULL;
        char *port = NULL;

        for (i = 0; i < n; i++) {
            if (buff[i] == '\n' && buff[i + 1] == '\r') {
                buff[i] = '\0';
                break;
            }
        }

        char *line = strtok(buff, "\n");
        while (line != NULL) {
            if (strncmp(line, "Host: ", 6) == 0) {
                host = line + 6;
            } else if (strncmp(line, "Port: ", 6) == 0) {
                port = line + 6;
            }

            line = strtok(NULL, "\n");
        }

        if (host == NULL) {
            fprintf(stderr, "Host header is missing\n");
            close(connfd);
            continue;
        }

        if (port == NULL) {
            port = "80";
        }

        struct sockaddr_in target;
        memset(&target, 0, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(atoi(port));
        if (inet_aton(host, &target.sin_addr) == 0) {
            fprintf(stderr, "Invalid host address\n");
            close(connfd);
            continue;
        }

        int targetfd;
        if ((targetfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket");
            close(connfd);
            continue;
        }

        if (connect(targetfd, (struct sockaddr *)&target, sizeof(target)) < 0) {
            perror("connect");
            close(connfd);
            close(targetfd);
            continue;
        }

        send(targetfd, buff, n, 0);

        while ((n = recv(targetfd, buff, BUFF_SIZE, 0)) > 0) {
            send(connfd, buff, n, 0);
        }

        close(connfd);
        close(targetfd);
    }

    return 0;
}