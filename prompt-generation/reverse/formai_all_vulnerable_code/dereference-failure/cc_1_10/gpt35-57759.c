//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, port, clientlen, n;
    char buffer[BUFFER_SIZE], host[BUFFER_SIZE], path[BUFFER_SIZE];
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *server;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons((unsigned short)port);

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);

    printf("Proxy started on port %d\n", port);

    while (1) {
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }
        
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        sscanf(buffer, "GET http://%[^/]%s HTTP/1.0", host, path);
        server = gethostbyname(host);
        if (server == NULL) {
            printf("ERROR, no such host: %s\n", host);
            close(newsockfd);
            continue;
        }
        
        bzero(buffer, BUFFER_SIZE);
        sprintf(buffer, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
        
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            error("ERROR opening socket");
        }

        struct sockaddr_in serveraddr2;
        bzero((char *)&serveraddr2, sizeof(serveraddr2));
        serveraddr2.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serveraddr2.sin_addr.s_addr, server->h_length);
        serveraddr2.sin_port = htons(80);
        if (connect(server_sockfd, (struct sockaddr *)&serveraddr2, sizeof(serveraddr2)) < 0) {
            error("ERROR connecting");
        }
        
        n = write(server_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        bzero(buffer, BUFFER_SIZE);
        while ((n = read(server_sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
            write(newsockfd, buffer, n);
            bzero(buffer, BUFFER_SIZE);
        }
        if (n < 0) {
            error("ERROR reading from socket");
        }
        
        close(newsockfd);
        close(server_sockfd);
    }
    
    close(sockfd);
    return 0;
}