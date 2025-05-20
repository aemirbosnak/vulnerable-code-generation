//Falcon-180B DATASET v1.0 Category: Networking ; Style: beginner-friendly
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

#define MAX 100

int main() {
    int sockfd, newsockfd, portno, clilen, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");

    while (1) {
        bzero(buffer, MAX);
        len = recv(newsockfd, buffer, MAX, 0);
        if (len < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("Received message from client: %s\n", buffer);

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    return 0;
}