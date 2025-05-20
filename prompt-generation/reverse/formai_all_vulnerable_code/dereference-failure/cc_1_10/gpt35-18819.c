//FormAI DATASET v1.0 Category: Browser Plugin ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);

    while ((n = read(newsockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        if (strstr(buffer, "GET /") != NULL) {
            send(newsockfd, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n", strlen("HTTP/1.1 200 OK\nContent-Type: text/html\n\n"), 0);
            send(newsockfd, "<html><body><h1>Welcome to my website!</h1></body></html>", strlen("<html><body><h1>Welcome to my website!</h1></body></html>"), 0);
            break;
        }

        bzero(buffer, BUFFER_SIZE);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}