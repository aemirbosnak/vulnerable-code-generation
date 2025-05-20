//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE 1024
#define PORT 53

int main() {
    struct sockaddr_in server_address;
    struct hostent *server;
    struct sockaddr_in* pSrvr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    char buffer[MAX_LINE];

    int sockfd, newsockfd, portno;
    socklen_t clilen;

    printf("Connecting to the server\n");
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    server = gethostbyname("google.com");
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);
    clilen = sizeof(server_address);
    if (connect(sockfd, (struct sockaddr *) &server_address, clilen) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }
    printf("Connected to the server\n");

    while (1) {
        bzero(buffer, MAX_LINE);
        newsockfd = accept(sockfd, (struct sockaddr *) pSrvr, &clilen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(0);
        }
        printf("New connection: %d\n", newsockfd);
        while (1) {
            bzero(buffer, MAX_LINE);
            if (recv(newsockfd, buffer, MAX_LINE, 0) < 0) {
                printf("Error receiving data\n");
                exit(0);
            }
            if (strcmp(buffer, "quit") == 0) {
                printf("Client disconnected\n");
                break;
            }
            printf("Received data: %s\n", buffer);
            send(newsockfd, buffer, MAX_LINE, 0);
        }
        close(newsockfd);
    }

    return 0;
}