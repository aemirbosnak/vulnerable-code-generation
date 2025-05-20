//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFSIZE 4096

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[BUFSIZE];
    int n;

    // Read request from client
    n = recv(client_socket, buffer, BUFSIZE, 0);
    if (n < 0) {
        perror("Error reading from socket");
        return;
    }

    // Extract method, URL, and HTTP version from request
    char *token;
    char *method;
    char *url;
    char *http_version;

    token = strtok(buffer, " \r\n");
    method = token;

    token = strtok(NULL, " \r\n");
    url = token;

    token = strtok(NULL, " \r\n");
    http_version = token;

    // Check if method is GET
    if (strcmp(method, "GET") != 0) {
        const char *response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
        return;
    }

    // Parse URL to get hostname and path
    char *hostname;
    char *path;

    if (strstr(url, "http://") == url) {
        url += strlen("http://");
    }

    hostname = strtok(url, "/");
    path = strtok(NULL, "");

    // Connect to web server
    struct addrinfo hints, *result;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, "80", &hints, &result) != 0) {
        perror("Error resolving hostname");
        return;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd < 0) {
        perror("Error creating socket");
        return;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) < 0) {
        perror("Error connecting to server");
        return;
    }

    // Construct request to send to web server
    char request[BUFSIZE];
    int size = snprintf(request, BUFSIZE, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    // Send request to web server
    if (write(sockfd, request, size) < 0) {
        perror("Error writing to socket");
        return;
    }

    // Read response from web server
    while ((n = read(sockfd, buffer, BUFSIZE)) > 0) {
        if (send(client_socket, buffer, n, 0) < 0) {
            perror("Error sending response to client");
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int port = 8080;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind server socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    printf("Proxy server running on port %d...\n", port);

    while (1) {
        // Accept client connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
        if (client_socket < 0) {
            perror("Error accepting connection from client");
            continue;
        }

        // Handle client request
        handle_client(client_socket);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}