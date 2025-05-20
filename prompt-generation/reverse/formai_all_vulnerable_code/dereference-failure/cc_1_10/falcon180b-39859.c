//Falcon-180B DATASET v1.0 Category: Educational ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX 1000

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Socket failed");
    }

    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Bind failed");
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        error("Accept failed");
    }

    printf("Connection Established with Client\n");

    while (1) {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(newsockfd, buffer, strlen(buffer), 0);
        bzero(buffer, MAX);
        recv(newsockfd, buffer, MAX, 0);
        printf("Client: %s", buffer);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}