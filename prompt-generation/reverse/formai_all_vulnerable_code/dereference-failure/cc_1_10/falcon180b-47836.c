//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAXLINE 1024

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAXLINE];
    socklen_t clilen;
    int opt = 1;
    char *message = "Welcome to the Cyberpunk TCP/IP Server!";

    if (argc < 2) {
        die("usage:./server <port>");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die("socket failed");
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        die("setsockopt");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("bind failed");
    }

    if (listen(sockfd, 5) < 0) {
        die("listen");
    }

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            die("accept");
        }

        send(newsockfd, message, strlen(message), 0);
    }

    close(sockfd);
    return 0;
}