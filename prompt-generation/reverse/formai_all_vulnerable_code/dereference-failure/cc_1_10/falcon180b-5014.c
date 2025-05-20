//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(errno);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    listen(sockfd, BACKLOG);

    while (TRUE) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept failed");
            exit(errno);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            bzero(buffer, 1024);

            int n = read(newsockfd, buffer, 1024);

            if (n <= 0) {
                close(newsockfd);
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(newsockfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send failed");
                exit(errno);
            }
        }
    }

    close(sockfd);

    return 0;
}