//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// A function to create a socket
int create_socket() {
    int socket_fd;

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// A function to bind a socket to a port
void bind_socket(int socket_fd, int port) {
    struct sockaddr_in server_address;

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

// A function to listen for incoming connections on a socket
void listen_socket(int socket_fd) {
    // Listen for incoming connections
    if (listen(socket_fd, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
}

// A function to accept an incoming connection on a socket
int accept_connection(int socket_fd) {
    int client_socket_fd;
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Accept an incoming connection
    client_socket_fd = accept(socket_fd, (struct sockaddr*)&client_address, &client_address_len);
    if (client_socket_fd == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    return client_socket_fd;
}

// A function to send a message to a socket
void send_message(int socket_fd, char* message) {
    // Send the message
    if (send(socket_fd, message, strlen(message), 0) == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
}

// A function to receive a message from a socket
void receive_message(int socket_fd, char* message) {
    // Receive the message
    if (recv(socket_fd, message, MAX_MESSAGE_SIZE, 0) == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
}

// A function to close a socket
void close_socket(int socket_fd) {
    // Close the socket
    if (close(socket_fd) == -1) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

// The main function
int main() {
    // Create a server socket
    int server_socket_fd = create_socket();

    // Bind the server socket to the port
    bind_socket(server_socket_fd, PORT);

    // Listen for incoming connections on the server socket
    listen_socket(server_socket_fd);

    // Accept an incoming connection on the server socket
    int client_socket_fd = accept_connection(server_socket_fd);

    // Send a message to the client
    char* message = "Hello, world!";
    send_message(client_socket_fd, message);

    // Receive a message from the client
    char* buffer = malloc(MAX_MESSAGE_SIZE);
    receive_message(client_socket_fd, buffer);

    // Print the message from the client
    printf("Received message: %s\n", buffer);

    // Free the buffer
    free(buffer);

    // Close the client socket
    close_socket(client_socket_fd);

    // Close the server socket
    close_socket(server_socket_fd);

    return 0;
}