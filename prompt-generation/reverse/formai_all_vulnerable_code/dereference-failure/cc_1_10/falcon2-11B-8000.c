//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(0);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(0);
    }

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(0);
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        if (recv(newsockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("recv");
            exit(0);
        }
        printf("Received: %s\n", buffer);

        bzero(buffer, sizeof(buffer));
        if (send(newsockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("send");
            exit(0);
        }
        printf("Sent: %s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}