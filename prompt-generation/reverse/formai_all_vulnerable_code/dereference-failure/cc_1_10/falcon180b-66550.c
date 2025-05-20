//Falcon-180B DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char *hostname = argv[1];
    int portno = atoi(argv[2]);

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);
            send(newsockfd, buffer, strlen(buffer), 0);

            memset(buffer, 0, BUFFER_SIZE);
            bcopy(buffer, buffer, recv(newsockfd, buffer, BUFFER_SIZE, 0));
            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                close(newsockfd);
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}