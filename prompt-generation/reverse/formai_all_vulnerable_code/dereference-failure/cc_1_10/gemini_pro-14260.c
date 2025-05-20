//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <err.h>

#define MAX_BUFFER 1024

// This function sends a request to a remote server and returns the response.
char *send_request(char *host, char *port, char *request) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        err(1, "socket");
    }

    // Connect to the remote server.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        err(1, "connect");
    }

    // Send the request to the remote server.
    if (write(sockfd, request, strlen(request)) == -1) {
        err(1, "write");
    }

    // Read the response from the remote server.
    char *response = malloc(MAX_BUFFER);
    int bytes_read = read(sockfd, response, MAX_BUFFER);
    if (bytes_read == -1) {
        err(1, "read");
    }

    // Close the socket.
    close(sockfd);

    // Return the response.
    return response;
}

// This function starts an HTTP proxy server on a specified port.
void start_proxy_server(char *port) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        err(1, "socket");
    }

    // Bind the socket to the specified port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        err(1, "bind");
    }

    // Listen for incoming connections.
    if (listen(sockfd, 5) == -1) {
        err(1, "listen");
    }

    // Accept incoming connections.
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            err(1, "accept");
        }

        // Read the request from the client.
        char *request = malloc(MAX_BUFFER);
        int bytes_read = read(client_sockfd, request, MAX_BUFFER);
        if (bytes_read == -1) {
            err(1, "read");
        }

        // Parse the request.
        char *host = strtok(request, " ");
        char *port = strtok(NULL, " ");
        char *path = strtok(NULL, "\r\n");

        // Send the request to the remote server.
        char *response = send_request(host, port, request);

        // Write the response to the client.
        if (write(client_sockfd, response, strlen(response)) == -1) {
            err(1, "write");
        }

        // Close the client socket.
        close(client_sockfd);

        // Free the memory allocated for the request and response.
        free(request);
        free(response);
    }
}

// This is the main function.
int main(int argc, char *argv[]) {
    // Check if the user has specified a port number.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Start the proxy server.
    start_proxy_server(argv[1]);

    return 0;
}