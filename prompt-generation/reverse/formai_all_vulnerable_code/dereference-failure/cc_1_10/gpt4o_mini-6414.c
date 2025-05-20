//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    recv(client_socket, buffer, sizeof(buffer), 0);

    char *method = strtok(buffer, " ");
    char *url = strtok(NULL, " ");
    
    if (method == NULL || url == NULL) {
        perror("HTTP request format error");
        close(client_socket);
        return;
    }

    printf("Received request: %s %s\n", method, url);

    // Extract the hostname and port from the URL
    char hostname[256];
    int port = 80;  // Default port for HTTP
    sscanf(url, "http://%255[^:/]:%d", hostname, &port);
    if (port == 0) {
        sscanf(url, "http://%255[^/]", hostname);
    }

    // Create a new socket to connect to the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Server socket creation failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the original request to the server
    send(server_socket, buffer, strlen(buffer), 0);

    // Buffer for reply from server
    int bytes_received;
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        // Send the server response back to the client
        send(client_socket, buffer, bytes_received, 0);
    }

    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy Server is running on port %d...\n", port);
    
    while (1) {
        // Accept a new connection from a client
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Client connection failed");
            continue; // Keep the server going
        }

        // Handle the client in a new function
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}