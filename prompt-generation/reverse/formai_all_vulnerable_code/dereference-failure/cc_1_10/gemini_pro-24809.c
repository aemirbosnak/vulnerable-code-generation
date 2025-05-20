//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: mathematical
// Server.c: A mathematical symphony of web server operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Max request size
#define MAX_REQ_LEN 1024

// HTTP response codes
#define HTTP_OK 200
#define HTTP_NOT_FOUND 404
#define HTTP_INTERNAL_SERVER_ERROR 500

// Handle client requests
void handle_request(int client_socket) {
    // Request buffer
    char request[MAX_REQ_LEN];

    // Read request
    int bytes_read = read(client_socket, request, MAX_REQ_LEN);
    if (bytes_read < 0) {
        perror("read");
        return;
    }

    // Parse request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Handle methods
    if (strcmp(method, "GET") == 0) {
        // Handle paths
        if (strcmp(path, "/") == 0) {
            // Home page
            char response[] = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my server!</h1></body></html>";
            write(client_socket, response, strlen(response));
        } else {
            // Not found
            char response[] = "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<html><body><h1>404 Not Found</h1></body></html>";
            write(client_socket, response, strlen(response));
        }
    } else {
        // Not implemented
        char response[] = "HTTP/1.1 500 Internal Server Error\nContent-Type: text/html\n\n<html><body><h1>500 Internal Server Error</h1></body></html>";
        write(client_socket, response, strlen(response));
    }

    // Close connection
    close(client_socket);
}

int main() {
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind socket
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept connections and handle requests
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        // Spin off a thread to handle the request
        int *pclient_socket = malloc(sizeof(int));
        *pclient_socket = client_socket;
        pthread_t tid;
        pthread_create(&tid, NULL, (void *(*)(void *))handle_request, pclient_socket);
    }

    // Close socket
    close(server_socket);

    return EXIT_SUCCESS;
}