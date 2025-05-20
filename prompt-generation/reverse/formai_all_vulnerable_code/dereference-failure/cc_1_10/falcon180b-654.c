//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT 8080

int main() {
    int sockfd, newsockfd, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    struct hostent *server;
    int yes = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (TRUE) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection on socket %d\n", newsockfd);
        fflush(stdout);

        while (TRUE) {
            ret = recv(newsockfd, buffer, BUF_SIZE, 0);
            if (ret <= 0) {
                if (ret == 0)
                    printf("Client disconnected\n");
                else
                    perror("recv");

                close(newsockfd);
                break;
            }

            send(newsockfd, buffer, ret, 0);
        }
    }

    close(sockfd);
    return 0;
}