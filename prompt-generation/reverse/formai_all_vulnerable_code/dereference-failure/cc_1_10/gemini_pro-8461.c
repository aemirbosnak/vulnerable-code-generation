//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// Create a client socket
int create_client_socket() {
    int client_socket;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was created successfully
    if (client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Return the client socket
    return client_socket;
}

// Connect to the server
int connect_to_server(int client_socket, const char *ip_address) {
    struct sockaddr_in server_address;

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Return the client socket
    return client_socket;
}

// Send a message to the server
void send_message(int client_socket, const char *message) {
    int message_length;

    // Get the length of the message
    message_length = strlen(message);

    // Send the message to the server
    if (send(client_socket, message, message_length, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the server
char *receive_message(int client_socket) {
    char *message;
    int message_length;

    // Allocate memory for the message
    message = malloc(MAX_MESSAGE_SIZE);

    // Receive the message from the server
    message_length = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);

    // Check if the message was received successfully
    if (message_length == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Return the message
    return message;
}

// Main function
int main(int argc, char *argv[]) {
    int client_socket;
    char *message;

    // Check if the user has provided the IP address of the server
    if (argc != 2) {
        printf("Usage: %s <IP address of the server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a client socket
    client_socket = create_client_socket();

    // Connect to the server
    client_socket = connect_to_server(client_socket, argv[1]);

    // Send a message to the server
    message = "Hello, world!";
    send_message(client_socket, message);

    // Receive a message from the server
    message = receive_message(client_socket);

    // Print the message received from the server
    printf("Message received from the server: %s\n", message);

    // Close the client socket
    close(client_socket);

    // Free the memory allocated for the message
    free(message);

    // Exit the program
    exit(EXIT_SUCCESS);
}