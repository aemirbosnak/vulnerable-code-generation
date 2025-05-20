//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main() {
    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, BACKLOG);
    addrlen = sizeof(cli_addr);
    puts("Waiting for connections...");

    while (TRUE) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUF_SIZE);
            if ((recv(newsockfd, buffer, BUF_SIZE, 0)) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv failed");
                    exit(1);
                } else {
                    puts("Client disconnected");
                    break;
                }
            }

            printf("Received message: %s\n", buffer);
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}