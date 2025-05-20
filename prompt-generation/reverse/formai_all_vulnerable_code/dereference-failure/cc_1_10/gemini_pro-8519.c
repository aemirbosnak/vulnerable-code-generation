//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int bind_status = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (bind_status < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    int listen_status = listen(sockfd, 5);
    if (listen_status < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept a connection
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    while ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) >= 0) {
        // Read the request from the client
        char request[1024];
        int bytes_received = recv(client_sockfd, request, sizeof(request), 0);
        if (bytes_received < 0) {
            perror("recv");
        } else if (bytes_received == 0) {
            // Client has closed the connection
            break;
        }

        // Parse the request
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Handle the request
        if (strcmp(method, "GET") == 0) {
            // Send a response to the client
            char response[1024];
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>");
            int bytes_sent = send(client_sockfd, response, strlen(response), 0);
            if (bytes_sent < 0) {
                perror("send");
            }
        } else {
            // Send a 405 Method Not Allowed response to the client
            char response[1024];
            sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html\r\n\r\n<h1>Method Not Allowed</h1>");
            int bytes_sent = send(client_sockfd, response, strlen(response), 0);
            if (bytes_sent < 0) {
                perror("send");
            }
        }

        // Close the client connection
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}