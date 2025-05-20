//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./server <IP Address> <Port Number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Error receiving data\n");
                exit(1);
            }

            printf("Received data: %s\n", buffer);

            ssize_t bytes_sent = send(newsockfd, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0) {
                printf("Error sending data\n");
                exit(1);
            }
        }

        close(newsockfd);
    }

    return 0;
}