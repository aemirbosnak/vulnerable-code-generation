//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (sockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (1) {
        char buffer[1024];
        int n;

        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        send(sockfd, buffer, n, 0);
    }

    close(sockfd);
    return 0;
}