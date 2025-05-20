//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

// Recursive function to parse and process HTTP requests
void handle_request(int sockfd, char* request) {
    // Split the request into components: method, path, and HTTP version
    char* method = strtok(request, " ");
    char* path = strtok(NULL, " ");
    char* version = strtok(NULL, "\r\n");

    // Check the request method and version
    if (strcmp(method, "GET") != 0) {
        // Not a GET request, send an error response
        char* error_response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        send(sockfd, error_response, strlen(error_response), 0);
        return;
    } else if (strcmp(version, "HTTP/1.1") != 0) {
        // Not HTTP/1.1, send an error response
        char* error_response = "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n";
        send(sockfd, error_response, strlen(error_response), 0);
        return;
    }

    // Check the request path and generate a response
    char* response = NULL;
    int response_length = 0;
    if (strcmp(path, "/") == 0) {
        // Index page
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to my website!</h1>";
        response_length = strlen(response);
    } else if (strcmp(path, "/about") == 0) {
        // About page
        response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>About Me</h1><p>I am a web developer and I love to code!</p>";
        response_length = strlen(response);
    } else {
        // Not a valid path, send an error response
        char* error_response = "HTTP/1.1 404 Not Found\r\n\r\n";
        response = error_response;
        response_length = strlen(error_response);
    }

    // Send the response to the client
    send(sockfd, response, response_length, 0);

    // Close the socket
    close(sockfd);
}

// Recursive function to accept incoming connections and handle client requests
void handle_connections(int server_sockfd) {
    // Accept an incoming connection
    int client_sockfd = accept(server_sockfd, NULL, NULL);
    if (client_sockfd < 0) {
        perror("accept");
        return;
    }

    // Receive the request from the client
    char request[1024];
    int recv_len = recv(client_sockfd, request, sizeof(request), 0);
    if (recv_len < 0) {
        perror("recv");
        close(client_sockfd);
        return;
    }

    // Handle the request
    handle_request(client_sockfd, request);

    // Recursively handle the next incoming connection
    handle_connections(server_sockfd);
}

int main() {
    // Create a server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options: SO_REUSEADDR allows the socket to be reused even if it is in a TIME_WAIT state
    int opt = 1;
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        close(server_sockfd);
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sockfd);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) < 0) {
        perror("listen");
        close(server_sockfd);
        return EXIT_FAILURE;
    }

    // Recursively handle incoming connections
    handle_connections(server_sockfd);

    // Close the server socket
    close(server_sockfd);

    return EXIT_SUCCESS;
}