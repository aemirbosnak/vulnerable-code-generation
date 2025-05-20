//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Create a socket for the server
int create_server_socket() {
    int server_socket;

    // Create a new socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

// Accept a connection from a client
int accept_client_connection(int server_socket) {
    int client_socket;

    // Accept a new connection
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
    if (client_socket == -1) {
        perror("Error accepting client connection");
        exit(EXIT_FAILURE);
    }

    return client_socket;
}

// Receive a message from a client
char *receive_message(int client_socket) {
    char *message;

    // Allocate memory for the message
    message = malloc(1024);
    if (message == NULL) {
        perror("Error allocating memory for message");
        exit(EXIT_FAILURE);
    }

    // Receive the message
    int length = recv(client_socket, message, 1024, 0);
    if (length == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    // Terminate the message with a null character
    message[length] = '\0';

    return message;
}

// Send a message to a client
void send_message(int client_socket, char *message) {
    // Send the message
    int length = send(client_socket, message, strlen(message), 0);
    if (length == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
}

// Close a socket
void close_socket(int socket) {
    // Close the socket
    if (close(socket) == -1) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Create the server socket
    int server_socket = create_server_socket();

    // Accept a connection from a client
    int client_socket = accept_client_connection(server_socket);

    // Receive a message from the client
    char *message = receive_message(client_socket);

    // Send a message to the client
    send_message(client_socket, "Hello, world!");

    // Close the sockets
    close_socket(client_socket);
    close_socket(server_socket);

    return 0;
}