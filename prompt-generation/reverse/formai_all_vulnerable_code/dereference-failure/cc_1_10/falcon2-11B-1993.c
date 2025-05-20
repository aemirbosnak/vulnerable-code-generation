//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    struct hostent *server;
    int n;
    socklen_t clilen;

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if (portno <= 0 || portno > 65535) {
        fprintf(stderr, "port number out of range\n");
        exit(1);
    }

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "unknown host\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *(struct in_addr *)server->h_addr;
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        printf("New connection from %s\n", inet_ntoa(cli_addr.sin_addr));

        while ((n = recv(newsockfd, buffer, 256, 0)) > 0) {
            printf("received %d bytes: %s\n", n, buffer);
            printf("sending 'Hello, world!'\n");
            send(newsockfd, "Hello, world!", 13, 0);
        }

        close(newsockfd);
    }

    return 0;
}