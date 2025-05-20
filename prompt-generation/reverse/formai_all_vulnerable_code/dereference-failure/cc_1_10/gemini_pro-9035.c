//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of a message from a client
#define MAX_MESSAGE_SIZE 1024

// Create a socket for the server to listen on
int create_server_socket() {
    int server_socket;
    struct sockaddr_in server_address;

    // Create a socket for the server to listen on
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

// Accept a connection from a client
int accept_client(int server_socket) {
    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_size;

    // Accept a connection from a client
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
    if (client_socket == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return client_socket;
}

// Send a message to a client
void send_message(int client_socket, char *message) {
    // Send the message to the client
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a client
char *receive_message(int client_socket) {
    char *message;
    int message_size;

    // Receive the message from the client
    message_size = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);
    if (message_size == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the message
    message = malloc(message_size + 1);
    if (message == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy the message into the allocated memory
    memcpy(message, message, message_size);

    // Null-terminate the message
    message[message_size] = '\0';

    return message;
}

// Close a connection with a client
void close_connection(int client_socket) {
    // Close the connection with the client
    if (close(client_socket) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    int server_socket, client_socket;
    char *message;

    // Create a socket for the server to listen on
    server_socket = create_server_socket();

    // Loop forever, accepting connections from clients and sending and receiving messages
    while (1) {
        // Accept a connection from a client
        client_socket = accept_client(server_socket);

        // Receive a message from the client
        message = receive_message(client_socket);

        // Send a message to the client
        send_message(client_socket, message);

        // Close the connection with the client
        close_connection(client_socket);

        // Free the memory allocated for the message
        free(message);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}