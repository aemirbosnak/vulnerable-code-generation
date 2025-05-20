//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 8080
#define CLIENT_PORT 8888
#define BUFFER_SIZE 4096

/* 
 * Simple HTTP proxy example program written in C. This program receives 
 * an HTTP request from a client and forwards it to an HTTP server. It 
 * then receives the response from the server and forwards it back to 
 * the client. This program is for educational purposes only and should 
 * not be used in production environments.
 */

int main() {
    int sockfd, clientfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];

    // Create a socket for the proxy server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Bind the socket to the server address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);

    if(bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for incoming connections
    if(listen(sockfd, 10) < 0) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server started on port %d\n", SERVER_PORT);

    // Continuously serve incoming connections
    while(1) {
        socklen_t clilen = sizeof(cliaddr);
        bzero(&cliaddr, clilen);

        // Accept incoming connection from client
        clientfd = accept(sockfd, (struct sockaddr *) &cliaddr, &clilen);
        if(clientfd < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Accepted connection from client %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        bzero(&buffer, BUFFER_SIZE);

        // Receive HTTP request from client
        recv(clientfd, buffer, BUFFER_SIZE, 0);
        printf("Received HTTP request:\n%s\n", buffer);

        // Create a socket for the HTTP server
        int serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if(serverfd < 0) {
            printf("Error creating socket: %s\n", strerror(errno));
            continue;
        }

        // Connect to the HTTP server
        struct sockaddr_in servaddr_server;
        bzero(&servaddr_server, sizeof(servaddr_server));
        servaddr_server.sin_family = AF_INET;
        servaddr_server.sin_port = htons(CLIENT_PORT);
        servaddr_server.sin_addr.s_addr = inet_addr("127.0.0.1");

        if(connect(serverfd, (struct sockaddr *) &servaddr_server, sizeof(servaddr_server)) < 0) {
            printf("Error connecting to server: %s\n", strerror(errno));
            continue;
        }

        printf("Connected to server\n");

        // Forward HTTP request to server
        send(serverfd, buffer, strlen(buffer), 0);
        printf("Forwarded HTTP request to server\n");

        bzero(&buffer, BUFFER_SIZE);

        // Receive HTTP response from server
        recv(serverfd, buffer, BUFFER_SIZE, 0);
        printf("Received HTTP response from server:\n%s\n", buffer);

        // Forward HTTP response to client
        send(clientfd, buffer, strlen(buffer), 0);
        printf("Forwarded HTTP response to client\n");

        // Close the client and server sockets
        close(clientfd);
        close(serverfd);
    }

    return 0;
}