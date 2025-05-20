//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

// Maximum size of the request buffer
#define REQUEST_BUFFER_SIZE 4096

// Maximum size of the response buffer
#define RESPONSE_BUFFER_SIZE 8192

// HTTP proxy port
#define PROXY_PORT 8080

// HTTP server port
#define SERVER_PORT 80

// Forward declaration of functions
int handle_client(int client_socket);
int handle_server(int client_socket, int server_socket);
void send_request(int server_socket, char *request);
void receive_response(int server_socket, char *response);

int main() {
    // Create a socket for listening to client connections
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating client socket");
        exit(1);
    }

    // Configure the socket address for the client socket
    struct sockaddr_in client_address;
    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = INADDR_ANY;
    client_address.sin_port = htons(PROXY_PORT);

    // Bind the socket to the client address
    if (bind(client_socket, (struct sockaddr *) &client_address, sizeof(client_address)) < 0) {
        perror("Error binding client socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(client_socket, 5) < 0) {
        perror("Error listening for client connections");
        exit(1);
    }

    // Main loop: accept client connections and handle them
    while (1) {
        // Accept a client connection
        int client_fd = accept(client_socket, NULL, NULL);
        if (client_fd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Create a new thread to handle the client connection
        int *client_fd_ptr = malloc(sizeof(int));
        *client_fd_ptr = client_fd;
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, (void *) client_fd_ptr);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}

// Function to handle a client connection
int handle_client(int client_socket) {
    // Read the HTTP request from the client
    char request[REQUEST_BUFFER_SIZE];
    int request_length = read(client_socket, request, sizeof(request) - 1);
    if (request_length < 0) {
        perror("Error reading HTTP request");
        close(client_socket);
        return 1;
    }

    // Parse the HTTP request
    char *host = NULL;
    char *path = NULL;
    int port = SERVER_PORT;
    if (sscanf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n", path, host) != 2) {
        printf("Error parsing HTTP request: %s", request);
        close(client_socket);
        return 1;
    }

    // Create a socket for connecting to the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        close(client_socket);
        return 1;
    }

    // Configure the socket address for the server socket
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(host);
    server_address.sin_port = htons(port);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        close(server_socket);
        return 1;
    }

    // Forward the HTTP request to the server
    send_request(server_socket, request);

    // Receive the HTTP response from the server
    char response[RESPONSE_BUFFER_SIZE];
    receive_response(server_socket, response);

    // Send the HTTP response to the client
    write(client_socket, response, strlen(response));

    // Close the client socket
    close(client_socket);

    // Close the server socket
    close(server_socket);

    return 0;
}

// Function to send an HTTP request to the server
void send_request(int server_socket, char *request) {
    // Send the HTTP request to the server
    write(server_socket, request, strlen(request));
}

// Function to receive an HTTP response from the server
void receive_response(int server_socket, char *response) {
    // Receive the HTTP response from the server
    int response_length = read(server_socket, response, sizeof(response) - 1);
    if (response_length < 0) {
        perror("Error reading HTTP response");
        return;
    }

    // Null-terminate the response
    response[response_length] = '\0';
}