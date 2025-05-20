//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: mathematical
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Bind the socket to the address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept connections
    int len = sizeof(cliaddr);
    while (1) {
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        // Handle the connection
        char buffer[4096];
        int n;
        while ((n = recv(connfd, buffer, sizeof(buffer), 0)) > 0) {
            // Parse the request
            char *request = strtok(buffer, "\r\n");
            if (strcmp(request, "GET / HTTP/1.1") == 0) {
                // Send the response
                char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
                send(connfd, response, strlen(response), 0);
            } else {
                // Send a 404 error
                char *response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
                send(connfd, response, strlen(response), 0);
            }
        }

        // Close the connection
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}