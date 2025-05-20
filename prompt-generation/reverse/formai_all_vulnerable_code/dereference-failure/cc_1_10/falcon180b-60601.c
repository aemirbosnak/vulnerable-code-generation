//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    char *message;
    int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    addrlen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
    if (newsockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    message = "Welcome to the realm of TCP/IP programming, noble user. How may I assist thee?\n";
    send(newsockfd, message, strlen(message), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        message = "Thou hast spoken wisely, noble user. May I offer thee further assistance?\n";
        send(newsockfd, message, strlen(message), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}