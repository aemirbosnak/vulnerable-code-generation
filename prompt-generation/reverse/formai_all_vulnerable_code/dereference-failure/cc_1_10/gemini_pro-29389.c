//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    char *request;
    char *host;
    char *path;
    int host_len;
    int path_len;
    int n;

    // Create a socket for listening
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Start listening for connections
    if (listen(listenfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept a connection
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        // Receive the HTTP request
        n = recv(connfd, buffer, MAX_BUFFER_SIZE, 0);
        if (n == -1) {
            perror("recv");
            close(connfd);
            continue;
        }

        // Parse the request
        request = strtok(buffer, " ");
        host = strtok(NULL, " ");
        path = strtok(NULL, " ");

        // Get the length of the host and path
        host_len = strlen(host);
        path_len = strlen(path);

        // Send the HTTP request to the server
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            close(connfd);
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr(host);

        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            close(connfd);
            continue;
        }

        char request_buffer[MAX_BUFFER_SIZE];
        sprintf(request_buffer, "%s %s HTTP/1.1\r\nHost: %s\r\n\r\n", request, path, host);
        send(sockfd, request_buffer, strlen(request_buffer), 0);

        // Receive the HTTP response from the server
        char response_buffer[MAX_BUFFER_SIZE];
        int bytes_received = recv(sockfd, response_buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            close(sockfd);
            close(connfd);
            continue;
        }

        // Send the HTTP response to the client
        send(connfd, response_buffer, bytes_received, 0);

        close(sockfd);
        close(connfd);
    }

    close(listenfd);

    return 0;
}