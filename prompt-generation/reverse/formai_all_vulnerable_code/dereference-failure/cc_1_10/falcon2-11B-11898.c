//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd, n, addrlen;
    struct sockaddr_in serv_addr;
    char buffer[MAXLINE];
    char *response = "Hello World!";

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(serv_addr);
        n = accept(sockfd, (struct sockaddr *)&serv_addr, &addrlen);
        if (n < 0) {
            perror("accept");
            exit(1);
        }

        read(sockfd, buffer, MAXLINE);
        if (strcmp(buffer, "GET / HTTP/1.1\r\n\r\n") == 0) {
            send(sockfd, response, strlen(response), 0);
        }

        close(sockfd);
        break;
    }

    close(sockfd);
    return 0;
}