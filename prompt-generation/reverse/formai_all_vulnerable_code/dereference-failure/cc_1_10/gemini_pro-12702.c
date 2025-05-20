//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number
#define PORT 8080

// Create a socket
int create_socket() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return socket_fd;
}

// Bind the socket to an address
void bind_socket(int socket_fd, struct sockaddr_in *address) {
    int bind_result = bind(socket_fd, (struct sockaddr *)address, sizeof(*address));
    if (bind_result == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_for_connections(int socket_fd) {
    int listen_result = listen(socket_fd, SOMAXCONN);
    if (listen_result == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection
int accept_connection(int socket_fd) {
    int connection_fd = accept(socket_fd, NULL, NULL);
    if (connection_fd == -1) {
        perror("Failed to accept connection");
        exit(EXIT_FAILURE);
    }
    return connection_fd;
}

// Send data to a client
void send_data(int connection_fd, char *data) {
    int send_result = send(connection_fd, data, strlen(data), 0);
    if (send_result == -1) {
        perror("Failed to send data");
        exit(EXIT_FAILURE);
    }
}

// Receive data from a client
char *receive_data(int connection_fd) {
    char *buffer = malloc(1024);
    int receive_result = recv(connection_fd, buffer, 1024, 0);
    if (receive_result == -1) {
        perror("Failed to receive data");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Close a socket
void close_socket(int socket_fd) {
    int close_result = close(socket_fd);
    if (close_result == -1) {
        perror("Failed to close socket");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Create a socket
    int socket_fd = create_socket();

    // Bind the socket to an address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;
    bind_socket(socket_fd, &address);

    // Listen for incoming connections
    listen_for_connections(socket_fd);

    // Accept an incoming connection
    int connection_fd = accept_connection(socket_fd);

    // Send data to the client
    char *data = "Hello from the server!";
    send_data(connection_fd, data);

    // Receive data from the client
    char *buffer = receive_data(connection_fd);
    printf("Received data from the client: %s\n", buffer);

    // Close the sockets
    close_socket(connection_fd);
    close_socket(socket_fd);

    return 0;
}