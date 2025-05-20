//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    // Create a listening socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to an address and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return 1;
    }

    // Start listening for connections
    if (listen(listenfd, 10) == -1) {
        perror("listen");
        return 1;
    }

    // Accept connections from clients
    while (1) {
        int connfd = accept(listenfd, NULL, NULL);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        // Read the request from the client
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        int n = recv(connfd, buffer, BUFFER_SIZE - 1, 0);
        if (n == -1) {
            perror("recv");
            close(connfd);
            continue;
        }

        // Parse the request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            send(connfd, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"), 0);
            close(connfd);
            continue;
        }

        // Send a response to the client
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!\n";
        send(connfd, response, strlen(response), 0);

        // Close the connection with the client
        close(connfd);
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}