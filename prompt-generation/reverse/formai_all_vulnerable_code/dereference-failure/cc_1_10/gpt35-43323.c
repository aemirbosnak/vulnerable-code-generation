//FormAI DATASET v1.0 Category: Simple Web Server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        printf("Error: No port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not bind socket\n");
        exit(1);
    }

    printf("Starting Simple Web Server...\n");

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);

        if (newsockfd < 0) {
            printf("Error: Could not accept connection\n");
            exit(1);
        }

        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1024);

        if (n < 0) {
            printf("Error: Could not read from socket\n");
        }
        else {
            printf("Request Received: %s\n", buffer);
            char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my Simple Web Server!</h1></body></html>";
            n = write(newsockfd, response, strlen(response));
            if (n < 0) {
                printf("Error: Could not write to socket\n");
            }
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}