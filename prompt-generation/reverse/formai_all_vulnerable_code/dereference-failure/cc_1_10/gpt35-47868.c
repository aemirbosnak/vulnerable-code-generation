//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr,"ERROR, no hostname provided\n");
        exit(0);
    }

    portno = PORT;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr))) < 0) {
        error("ERROR on accept");
    }

    bzero(buffer, BUFFER_SIZE);

    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        if (write(newsockfd, buffer, n) < 0)
            error("ERROR writing to socket");
        bzero(buffer, BUFFER_SIZE);
    }

    if (n < 0)
        error("ERROR reading from socket");

    close(sockfd);
    close(newsockfd);
    return 0;
}