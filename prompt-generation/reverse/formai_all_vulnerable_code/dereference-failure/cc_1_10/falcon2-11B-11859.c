//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    char hostname[1024] = "example.com";
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        return 1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error in getting hostname information\n");
        return 1;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error in connecting to the server\n");
        return 1;
    }

    char request[1024] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error in sending request to the server\n");
        return 1;
    }

    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        printf("Error in receiving response from the server\n");
        return 1;
    }

    printf("Response from the server: %s\n", response);

    close(sockfd);
    return 0;
}