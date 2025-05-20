//Falcon-180B DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Welcome to the server!";
    char ip[INET_ADDRSTRLEN];

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Connection established with %s:%d\n", inet_ntop(AF_INET, &cli_addr.sin_addr, ip, INET_ADDRSTRLEN), ntohs(cli_addr.sin_port));

        sd = dup(newsockfd);
        if (sd < 0) {
            perror("dup failed");
            exit(1);
        }

        close(newsockfd);

        while (1) {
            bzero(buffer, BUFFER_SIZE);
            int bytes_received = recv(sd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            printf("Received message: %s\n", buffer);

            strcat(message, " ");
            strcat(message, buffer);

            send(sd, message, strlen(message), 0);
        }

        close(sd);
    }

    return 0;
}