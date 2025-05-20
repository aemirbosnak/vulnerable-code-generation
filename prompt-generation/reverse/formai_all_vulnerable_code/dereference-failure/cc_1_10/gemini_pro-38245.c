//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the server's address and port
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080

// Define the maximum size of the message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// Create a new socket
int create_socket() {
    // Create a new socket using the TCP protocol
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// Connect to the server
void connect_to_server(int socket_fd) {
    // Create the server's address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_aton(SERVER_ADDRESS, &server_address.sin_addr);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
}

// Send a message to the server
void send_message(int socket_fd, char *message) {
    // Send the message to the server
    if (send(socket_fd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the server
char *receive_message(int socket_fd) {
    // Receive the message from the server
    char *message = malloc(MAX_MESSAGE_SIZE);
    if (recv(socket_fd, message, MAX_MESSAGE_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    return message;
}

// Close the socket
void close_socket(int socket_fd) {
    // Close the socket
    if (close(socket_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new socket
    int socket_fd = create_socket();

    // Connect to the server
    connect_to_server(socket_fd);

    // Send a message to the server
    send_message(socket_fd, "Hello, world!");

    // Receive a message from the server
    char *message = receive_message(socket_fd);
    printf("Message from server: %s\n", message);

    // Close the socket
    close_socket(socket_fd);

    return EXIT_SUCCESS;
}