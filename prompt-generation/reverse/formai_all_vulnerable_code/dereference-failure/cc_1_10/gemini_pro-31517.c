//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_SIZE 1024

// Send an HTTP response to the client
void send_response(int client_socket, int status_code, char *content_type, char *content) {
    char buffer[MAX_SIZE];

    // Create the HTTP response header
    sprintf(buffer, "HTTP/1.1 %d %s\r\n", status_code, status_code == 200 ? "OK" : "Not Found");
    send(client_socket, buffer, strlen(buffer), 0);

    // Add the Content-Type header
    sprintf(buffer, "Content-Type: %s\r\n", content_type);
    send(client_socket, buffer, strlen(buffer), 0);

    // Add the Content-Length header
    sprintf(buffer, "Content-Length: %d\r\n", strlen(content));
    send(client_socket, buffer, strlen(buffer), 0);

    // Add an empty line to terminate the headers
    send(client_socket, "\r\n", 2, 0);

    // Send the content
    send(client_socket, content, strlen(content), 0);
}

// Handle a client request
void handle_request(int client_socket) {
    char buffer[MAX_SIZE];

    // Receive the request from the client
    recv(client_socket, buffer, MAX_SIZE, 0);

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
        send_response(client_socket, 405, "text/plain", "Method Not Allowed");
        return;
    }

    if (strcmp(path, "/") == 0) {
        path = "/index.html";
    }

    // Open the requested file
    FILE *file = fopen(path, "r");

    // Check if the file exists
    if (file == NULL) {
        send_response(client_socket, 404, "text/plain", "Not Found");
        return;
    }

    // Read the file contents
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *content = malloc(file_size + 1);
    fread(content, 1, file_size, file);
    content[file_size] = '\0';

    fclose(file);

    // Send the response to the client
    send_response(client_socket, 200, "text/html", content);

    // Free the allocated memory
    free(content);
}

// Start the server
void start_server() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);

        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the client request
        handle_request(client_socket);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);
}

int main() {
    start_server();

    return 0;
}