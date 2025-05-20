//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFF_SIZE];

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    while (1) {
        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (new_sockfd < 0)
            error("ERROR on accept");

        int pid = fork();
        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0) {
            close(sockfd);

            memset(buffer, 0, BUFF_SIZE);
            if (read(new_sockfd, buffer, BUFF_SIZE) < 0)
                error("ERROR reading from socket");

            char *host;
            host = strtok(buffer, " ");
            host = strtok(NULL, " ");
            host = strtok(host, "/");
            host = strtok(NULL, "/");

            struct hostent *server;
            server = gethostbyname(host);

            if (server == NULL) {
                fprintf(stderr, "ERROR, no such host\n");
                exit(0);
            }

            int proxy_sockfd;
            struct sockaddr_in proxy_addr;
            memset(&proxy_addr, 0, sizeof(proxy_addr));
            proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (proxy_sockfd < 0)
                error("ERROR opening socket");

            proxy_addr.sin_family = AF_INET;
            bcopy((char *) server->h_addr,
                  (char *) &proxy_addr.sin_addr.s_addr, server->h_length);
            proxy_addr.sin_port = htons(80);

            if (connect(proxy_sockfd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0)
                error("ERROR connecting");

            if (write(proxy_sockfd, buffer, strlen(buffer)) < 0)
                error("ERROR writing to socket");

            memset(buffer, 0, BUFF_SIZE);
            while (read(proxy_sockfd, buffer, BUFF_SIZE) > 0) {
                if (write(new_sockfd, buffer, strlen(buffer)) < 0)
                    error("ERROR writing to socket");
                memset(buffer, 0, BUFF_SIZE);
            }

            close(new_sockfd);
            exit(0);
        } else {
            close(new_sockfd);
        }
    }
    return 0;
}