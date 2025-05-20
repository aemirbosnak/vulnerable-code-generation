//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

// Function to create a TCP/IP socket
int createSocket(int port) {
    int sockfd;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to accept a client connection
void acceptConnection(int sockfd) {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    int clientSockfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientAddrLen);

    if (clientSockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected: %s\n", inet_ntoa(clientAddr.sin_addr));
}

// Function to handle client requests
void handleRequest(int sockfd) {
    char buffer[1024];
    int n;

    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        printf("Received request: %s\n", buffer);

        if (strcmp(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n") == 0) {
            printf("Sending response\n");

            // Replace with your actual server response code, content type, and content

            send(sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"), 0);
            send(sockfd, "<html><body><h1>Hello, world!</h1></body></html>", strlen("<html><body><h1>Hello, world!</h1></body></html>"), 0);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    int port = atoi(argv[1]);
    int sockfd = createSocket(port);

    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    acceptConnection(sockfd);

    while (1) {
        int clientSockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);

        if (clientSockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        handleRequest(clientSockfd);
    }

    return 0;
}