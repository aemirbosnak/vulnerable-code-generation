//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int clientfd = accept(sockfd, (struct sockaddr *) NULL, NULL);
        if (clientfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        bzero(buffer, sizeof(buffer));

        int n = read(clientfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received: %s\n", buffer);
        send(clientfd, "Thank you for connecting!", sizeof("Thank you for connecting!"), 0);
        close(clientfd);
    }

    close(sockfd);
    return 0;
}