//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 4096
#define PORT 8080

int main() {
    int sockfd, valread;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char ip[INET_ADDRSTRLEN];
    char *hostname;
    struct hostent *server;
    struct hostent *client;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");
    fflush(stdout);

    while (1) {
        valread = read(sockfd, buffer, MAXLINE);
        if (valread <= 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }
        printf("%s", buffer);
        fflush(stdout);
    }

    return 0;
}