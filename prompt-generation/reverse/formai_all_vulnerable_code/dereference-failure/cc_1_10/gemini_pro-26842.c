//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void Die(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) Die("ERROR opening socket");

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) Die("ERROR on binding");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) Die("ERROR on accept");

        bzero(buffer, 256);

        int n = read(newsockfd, buffer, 255);
        if (n < 0) Die("ERROR reading from socket");

        printf("Here is the message: %s\n", buffer);

        n = write(newsockfd, "I got your message", 18);
        if (n < 0) Die("ERROR writing to socket");

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}