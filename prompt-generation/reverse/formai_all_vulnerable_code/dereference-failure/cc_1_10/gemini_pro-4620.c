//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("error opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("error binding socket");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("error accepting connection");
            exit(1);
        }

        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("error reading from socket");
            exit(1);
        }

        printf("Client: %s\n", buffer);

        bzero(buffer, 256);
        strcpy(buffer, "Hello from server");
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("error writing to socket");
            exit(1);
        }

        close(newsockfd);
    }

    return 0;
}