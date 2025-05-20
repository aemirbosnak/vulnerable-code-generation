//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno;
    int maxi;
    int clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host.\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    while (1) {
        bzero(buffer, 256);
        fgets(buffer, 256, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "/quit") == 0)
            break;
        bzero(buffer, 256);
        recv(sockfd, buffer, 256, 0);
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}