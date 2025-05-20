//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Cannot create socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Cannot bind socket");
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("Cannot listen on socket");
        return 1;
    }

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Cannot accept connection");
        return 1;
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t n = read(newsockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            perror("Cannot read from socket");
            break;
        } else if (n == 0) {
            printf("Connection closed by client\n");
            break;
        }

        printf("Received: %s", buffer);

        memset(buffer, 0, sizeof(buffer));
        strcpy(buffer, "World");
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Cannot write to socket");
            break;
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}