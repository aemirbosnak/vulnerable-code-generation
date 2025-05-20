//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_LINE];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, MAX_LINE);
        int n = read(newsockfd, buffer, MAX_LINE - 1);
        if (n < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        if (n == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Received from client: %s", buffer);

        bzero(buffer, MAX_LINE);
        strcpy(buffer, "Hello from server!");
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }
    }

    close(newsockfd);
    close(sockfd);

    return EXIT_SUCCESS;
}