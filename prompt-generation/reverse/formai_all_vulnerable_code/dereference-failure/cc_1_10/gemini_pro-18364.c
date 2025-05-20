//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    // Create a socket.
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket options.
    int reuse_addr = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the server address.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections.
    if (listen(socket_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept an incoming connection.
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    client_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    // Read the HTTP request from the client.
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read = recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_read < 0) {
        perror("recv");
        exit(1);
    }

    // Parse the HTTP request.
    char *request_line = strtok(buffer, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Check if the request is valid.
    if (strcmp(method, "GET") != 0) {
        // Send an error response.
        char *error_response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
        send(client_fd, error_response, strlen(error_response), 0);
        close(client_fd);
        exit(1);
    }

    if (strcmp(path, "/") != 0) {
        // Send a 404 Not Found response.
        char *not_found_response = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
        send(client_fd, not_found_response, strlen(not_found_response), 0);
        close(client_fd);
        exit(1);
    }

    // Send a 200 OK response.
    char *ok_response = "HTTP/1.1 200 OK\r\nContent-Length: 11\r\n\r\nHello world!";
    send(client_fd, ok_response, strlen(ok_response), 0);

    // Close the connection.
    close(client_fd);
    close(socket_fd);

    return 0;
}