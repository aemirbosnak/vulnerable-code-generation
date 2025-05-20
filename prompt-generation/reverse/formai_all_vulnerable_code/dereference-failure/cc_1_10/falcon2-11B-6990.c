//Falcon2-11B DATASET v1.0 Category: Networking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1000];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
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

    while (1) {
        socklen_t clilen = sizeof(struct sockaddr_in);
        int newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        char name[100];
        bzero(name, 100);

        n = read(newsockfd, name, 100);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (strcmp(name, "quit") == 0) {
            close(newsockfd);
            break;
        }

        printf("Client connected: %s\n", name);
        fgets(buffer, 100, stdin);
        send(newsockfd, buffer, strlen(buffer), 0);
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}