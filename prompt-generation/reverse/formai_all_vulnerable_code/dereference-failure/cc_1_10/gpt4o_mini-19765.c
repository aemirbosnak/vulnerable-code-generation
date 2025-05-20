//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read the client's request
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        error_handling("Failed to read from client");
    }
    
    buffer[bytes_read] = '\0'; // Null terminate the buffer

    // Extract the requested host and port from the HTTP request
    char method[8], url[256], protocol[16];
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Prepare the server address
    char *host = strtok(url, "/");
    int port = 80; // Default HTTP port
    char *port_ptr = strchr(host, ':');
    if (port_ptr) {
        *port_ptr++ = '\0';
        port = atoi(port_ptr);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Create a socket to connect to the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error_handling("Failed to create socket");
    }

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Failed to connect to server");
    }

    // Send the client's request to the server
    send(server_socket, buffer, bytes_read, 0);

    // Read the server's response and send it back to the client
    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    // Close sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    // Create a socket for the proxy server
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        error_handling("Failed to create proxy socket");
    }

    // Set up the address structure
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error_handling("Failed to bind socket");
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        error_handling("Failed to listen on socket");
    }

    printf("HTTP Proxy Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming client connections
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            error_handling("Failed to accept connection");
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the proxy socket
    close(proxy_socket);
    return 0;
}