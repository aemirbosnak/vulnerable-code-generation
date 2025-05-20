//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, len;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;

    if (argc < 2) {
        printf("Usage:./server <port_number>\n");
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: bind failed\n");
        exit(0);
    }

    listen(sockfd, 5);

    printf("Server is listening on port %d\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            printf("Error: accept failed\n");
            exit(0);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, sizeof(buffer));

            len = recv(newsockfd, buffer, 1024, 0);

            if (len <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(newsockfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                printf("Error: send failed\n");
                break;
            }
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}