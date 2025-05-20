//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portnum, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&n);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        portnum = atoi(inet_ntoa(cli_addr.sin_addr));

        if (portnum!= 8080) {
            close(newsockfd);
            continue;
        }

        if (fork() == 0) {
            close(sockfd);
            close(newsockfd);

            char msg[256];
            strcpy(msg, "Welcome to the C Port Scanner!");

            send(newsockfd, msg, strlen(msg), 0);

            close(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    }

    return 0;
}