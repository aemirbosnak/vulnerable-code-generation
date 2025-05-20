//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;

    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding to socket\n");
        exit(1);
    }

    listen(sockfd, 5);

    printf("Server is listening on port %d\n", portno);

    while (1) {

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));

        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection established with client %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {

            bzero(buffer, sizeof(buffer));

            n = recv(newsockfd, buffer, sizeof(buffer), 0);

            if (n <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            printf("Received data: %s\n", buffer);

            if (send(newsockfd, buffer, sizeof(buffer), 0) < 0) {
                printf("Error sending data\n");
                exit(1);
            }
        }

        close(newsockfd);
    }

    return 0;
}