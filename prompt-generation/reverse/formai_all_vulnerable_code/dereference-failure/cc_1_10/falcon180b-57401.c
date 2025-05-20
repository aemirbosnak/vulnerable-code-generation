//Falcon-180B DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    fd_set readfds;

    portno = 8080;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket");
        exit(1);
    }

    listen(sockfd, MAX_CLIENTS);

    FD_ZERO(&readfds);

    FD_SET(sockfd, &readfds);

    while (1) {
        clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            printf("Error accepting connection");
            exit(1);
        }

        FD_SET(newsockfd, &readfds);

        if (newsockfd > sockfd) {
            sockfd = newsockfd;
        }

        printf("New client connected with socket fd %d\n", newsockfd);
    }

    return 0;
}