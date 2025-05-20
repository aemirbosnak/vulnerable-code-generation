//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void proxy(int sockfd, struct sockaddr_in client_address)
{
    int client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0) {
        perror("Unable to create socket");
        exit(1);
    }

    if (connect(client_sockfd, (struct sockaddr *)&client_address, sizeof(struct sockaddr_in)) < 0) {
        perror("Unable to connect to server");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Unable to receive data from client");
            exit(1);
        } else if (bytes_received == 0) {
            break;
        }

        if (send(client_sockfd, buffer, bytes_received, 0) < 0) {
            perror("Unable to send data to server");
            exit(1);
        }

        bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Unable to receive data from server");
            exit(1);
        } else if (bytes_received == 0) {
            break;
        }

        if (send(sockfd, buffer, bytes_received, 0) < 0) {
            perror("Unable to send data to client");
            exit(1);
        }
    }

    close(client_sockfd);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            exit(1);
        }

        proxy(newsockfd, cli_addr);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}