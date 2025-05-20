//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serveraddr, clientaddr;
    char buffer[MAXLINE];
    int n;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    for (;;) {
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        read(newsockfd, buffer, MAXLINE);
        printf("Received: %s\n", buffer);

        write(newsockfd, buffer, strlen(buffer));
        close(newsockfd);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}