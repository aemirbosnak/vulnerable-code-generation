//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        while (1) {
            bzero(buffer, 256);
            if (read(newsockfd, buffer, 255) < 0) {
                perror("Error reading from socket");
                exit(1);
            }

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            printf("Received message: %s", buffer);

            bzero(buffer, 256);
            strcpy(buffer, "Hello, world!");
            if (write(newsockfd, buffer, strlen(buffer)) < 0) {
                perror("Error writing to socket");
                exit(1);
            }
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}