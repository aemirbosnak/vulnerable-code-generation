//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    portno = htons(atoi(getenv("PORT")));
    printf("Proxy server started on port %d\n", portno);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with client\n");

        while (1) {
            bzero(buffer, sizeof(buffer));
            read(newsockfd, buffer, sizeof(buffer));
            printf("%s\n", buffer);
            send(newsockfd, buffer, strlen(buffer), 0);

            bzero(buffer, sizeof(buffer));
            read(newsockfd, buffer, sizeof(buffer));
            printf("%s\n", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}