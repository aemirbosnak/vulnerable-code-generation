//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 8192
#define PORT 8080

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[16], url[256], protocol[16];
    
    // Read the HTTP request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        perror("Failed to receive data");
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0';
    printf("Request received:\n%s\n", buffer);

    // Parse the request
    sscanf(buffer, "%s %s %s", method, url, protocol);
    
    // If we only support GET requests for simplicity
    if (strcasecmp(method, "GET") != 0) {
        printf("Only GET requests are supported.\n");
        const char *response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
        return;
    }

    // Extract the hostname from the URL
    char host[256];
    int port = 80; // Default HTTP port
    char *url_copy = strdup(url);
    char *path = strchr(url_copy + 7, '/'); // Skipping "http://"
    
    if (path) {
        *path = '\0';
        strcpy(host, url_copy + 7); // Copy hostname
    } else {
        strcpy(host, url_copy + 7);
        path = "/";
    }

    // Check for a port number in the host
    char *port_position = strchr(host, ':');
    if (port_position) {
        *port_position = '\0';
        port = atoi(port_position + 1);
    }

    printf("Connecting to %s:%d\n", host, port);
    free(url_copy);

    // Create a socket for the destination server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to the server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the destination server
    send(server_socket, buffer, bytes_received, 0);

    // Read the response from the server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        send(client_socket, buffer, bytes_received, 0);
    }

    printf("Response sent back to the client.\n");

    // Clean up the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Binding socket failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy Server started on port %d!\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Accepting connection failed");
            continue;
        }

        printf("Client connected!\n");
        // Handle client requests
        handle_client(client_socket);
    }

    // Clean up and close the server socket
    close(server_socket);
    return 0;
}