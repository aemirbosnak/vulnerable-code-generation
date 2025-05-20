//GEMINI-pro DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of a message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// Create a socket and bind it to the specified port
int create_server_socket(int port) {
    int server_socket;
    struct sockaddr_in server_address;

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error: Unable to create socket");
        exit(1);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error: Unable to bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error: Unable to listen for connections");
        exit(1);
    }

    return server_socket;
}

// Accept a connection from a client
int accept_client_connection(int server_socket) {
    int client_socket;
    struct sockaddr_in client_address;
    socklen_t client_address_size;

    // Accept a connection from a client
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
    if (client_socket == -1) {
        perror("Error: Unable to accept client connection");
        exit(1);
    }

    return client_socket;
}

// Send a message to a client
void send_message_to_client(int client_socket, char *message) {
    int message_length;

    // Get the length of the message
    message_length = strlen(message);

    // Send the message to the client
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("Error: Unable to send message to client");
        exit(1);
    }
}

// Receive a message from a client
char *receive_message_from_client(int client_socket) {
    char *message;
    int message_length;

    // Receive the message from the client
    message_length = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);
    if (message_length == -1) {
        perror("Error: Unable to receive message from client");
        exit(1);
    }

    // Null-terminate the message
    message[message_length] = '\0';

    return message;
}

// Close a client connection
void close_client_connection(int client_socket) {
    // Close the client connection
    if (close(client_socket) == -1) {
        perror("Error: Unable to close client connection");
        exit(1);
    }
}

// Main function
int main() {
    int server_socket, client_socket;
    char *message;

    // Create a server socket
    server_socket = create_server_socket(PORT);

    // Accept a connection from a client
    client_socket = accept_client_connection(server_socket);

    // Send a message to the client
    message = "Hello, client!";
    send_message_to_client(client_socket, message);

    // Receive a message from the client
    message = receive_message_from_client(client_socket);
    printf("Message from client: %s\n", message);

    // Close the client connection
    close_client_connection(client_socket);

    // Close the server socket
    if (close(server_socket) == -1) {
        perror("Error: Unable to close server socket");
        exit(1);
    }

    return 0;
}