//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

// Define the port number for the server
#define SERVER_PORT 6969

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum size of the message that can be sent or received by the server
#define MAX_MESSAGE_SIZE 1024

// Define the welcome message that will be sent to each client when they connect to the server
#define WELCOME_MESSAGE "Welcome to the Super Secret Server!\n"

// Define the goodbye message that will be sent to each client when they disconnect from the server
#define GOODBYE_MESSAGE "Goodbye and thanks for all the fish!\n"

// Define the function that will handle the client connections
void handle_client(int client_socket) {
    // Send the welcome message to the client
    send(client_socket, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE), 0);

    // Receive the client's message
    char message[MAX_MESSAGE_SIZE];
    int message_length = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);

    // Process the client's message
    if (message_length > 0) {
        // Echo the client's message back to them
        send(client_socket, message, message_length, 0);
    } else {
        // The client has disconnected, so send them the goodbye message
        send(client_socket, GOODBYE_MESSAGE, strlen(GOODBYE_MESSAGE), 0);
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return 1;
    }

    // Set the server socket to be reusable
    int reuse_addr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1) {
        perror("Error setting server socket to be reusable");
        return 1;
    }

    // Bind the server socket to the server port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket to server port");
        return 1;
    }

    // Listen for incoming client connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening for incoming client connections");
        return 1;
    }

    printf("Server is listening for incoming client connections on port %d\n", SERVER_PORT);

    while (1) {
        // Accept the next incoming client connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Error accepting incoming client connection");
            continue;
        }

        // Print the client's IP address and port number
        printf("Client connected from IP address %s and port number %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle the client connection in a separate thread
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, (void *) client_socket_ptr);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}