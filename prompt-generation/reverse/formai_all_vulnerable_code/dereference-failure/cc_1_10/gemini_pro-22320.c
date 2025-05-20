//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define MAX_BUFFER_SIZE 1024
#define MAX_REQUEST_SIZE 4096
#define DEFAULT_PORT 8080

// Function prototypes
int create_server_socket(int port);
int accept_client_connection(int server_socket);
int handle_client_request(int client_socket);
void forward_request(int client_socket, int server_socket);
void receive_response(int client_socket, int server_socket);
void close_sockets(int client_socket, int server_socket);

int main(int argc, char **argv) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the port number to an integer
    int port = atoi(argv[1]);
    if (port <= 0) {
        fprintf(stderr, "Invalid port number: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create the server socket
    int server_socket = create_server_socket(port);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return EXIT_FAILURE;
    }

    // Listen for client connections
    while (1) {
        // Accept a client connection
        int client_socket = accept_client_connection(server_socket);
        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        // Handle the client request
        int status = handle_client_request(client_socket);
        if (status == -1) {
            perror("Failed to handle client request");
            close(client_socket);
            continue;
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}

int create_server_socket(int port) {
    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        return -1;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        close(server_socket);
        return -1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        close(server_socket);
        return -1;
    }

    // Listen for client connections
    if (listen(server_socket, 5) == -1) {
        close(server_socket);
        return -1;
    }

    return server_socket;
}

int accept_client_connection(int server_socket) {
    // Accept a client connection
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket == -1) {
        return -1;
    }

    return client_socket;
}

int handle_client_request(int client_socket) {
    // Receive the request from the client
    char request[MAX_REQUEST_SIZE];
    int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
    if (bytes_received == -1) {
        return -1;
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (method == NULL || path == NULL || http_version == NULL) {
        return -1;
    }

    // Print the request
    printf("Received request:\n");
    printf("Method: %s\n", method);
    printf("Path: %s\n", path);
    printf("HTTP version: %s\n", http_version);

    // Forward the request to the server
    int server_socket = create_server_socket(80);
    if (server_socket == -1) {
        return -1;
    }

    forward_request(client_socket, server_socket);

    // Receive the response from the server
    receive_response(client_socket, server_socket);

    // Close the server socket
    close(server_socket);

    return 0;
}

void forward_request(int client_socket, int server_socket) {
    // Send the request to the server
    char request[MAX_REQUEST_SIZE];
    int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive request from client");
        return;
    }

    int bytes_sent = send(server_socket, request, bytes_received, 0);
    if (bytes_sent == -1) {
        perror("Failed to send request to server");
        return;
    }
}

void receive_response(int client_socket, int server_socket) {
    // Receive the response from the server
    char response[MAX_BUFFER_SIZE];
    int bytes_received = recv(server_socket, response, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response from server");
        return;
    }

    // Send the response to the client
    int bytes_sent = send(client_socket, response, bytes_received, 0);
    if (bytes_sent == -1) {
        perror("Failed to send response to client");
        return;
    }
}

void close_sockets(int client_socket, int server_socket) {
    // Close the client socket
    close(client_socket);

    // Close the server socket
    close(server_socket);
}