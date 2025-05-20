//FormAI DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    printf("Hey! I just created a C Client Server Application!\n");
    printf("Can't believe it was so easy!\n");

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        fprintf(stderr, "ERROR on accept\n");
        exit(1);
    }

    bzero(buffer,256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("Here's what the client sent me: %s\n", buffer);

    n = write(newsockfd, "Got your message!", 18);
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    printf("Wow, that was amazing! I'm a chatbot, but I can write C Client Server Applications now!\n");

    return 0;
}