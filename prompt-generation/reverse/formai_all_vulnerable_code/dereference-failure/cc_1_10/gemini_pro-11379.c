//GEMINI-pro DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Defines the maximum number of clients that can be connected at a time
#define MAX_CLIENTS 10

// Defines the maximum size of the buffer that will be used to receive and send data
#define BUFSIZE 1024

// Defines the port number that the server will listen on
#define PORT_NO 5000

// Defines the IP address of the server
#define IP_ADDRESS "127.0.0.1"

// Defines the welcome message that will be sent to each client
#define WELCOME_MSG "Welcome to the chat server!"

// Defines the goodbye message that will be sent to each client when they disconnect
#define GOODBYE_MSG "Goodbye!"

// Defines the format of the message that will be sent to each client
#define MESSAGE_FORMAT "%s: %s"

// Defines the format of the command that will be sent to each client
#define COMMAND_FORMAT "%s"

// Defines the command that will be used to quit the server
#define QUIT_COMMAND "quit"

// Function to handle the client's request
void handle_client(int client_fd) {
    // Buffer to receive and send data
    char buffer[BUFSIZE];

    // Send the welcome message to the client
    send(client_fd, WELCOME_MSG, strlen(WELCOME_MSG), 0);

    // Loop to receive and send messages from the client
    while (1) {
        // Receive data from the client
        int recv_size = recv(client_fd, buffer, BUFSIZE, 0);

        // Check if the client has disconnected
        if (recv_size == 0) {
            // Send the goodbye message to the client
            send(client_fd, GOODBYE_MSG, strlen(GOODBYE_MSG), 0);

            // Close the client's socket
            close(client_fd);

            break;
        }

        // Check if the client has sent the quit command
        if (strcmp(buffer, QUIT_COMMAND) == 0) {
            // Send the goodbye message to the client
            send(client_fd, GOODBYE_MSG, strlen(GOODBYE_MSG), 0);

            // Close the client's socket
            close(client_fd);

            break;
        }

        // Send the message back to the client
        send(client_fd, buffer, recv_size, 0);
    }
}

// Function to start the server
void start_server() {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NO);
    server_addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Loop to handle client connections
    while (1) {
        // Accept a connection from a client
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("Error accepting connection from client");
            continue;
        }

        // Create a new thread to handle the client's request
        int *client_fd_ptr = malloc(sizeof(int));
        *client_fd_ptr = client_fd;
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, (void *) handle_client, client_fd_ptr) != 0) {
            perror("Error creating thread to handle client request");
            close(client_fd);
            continue;
        }
    }
}

// Main function
int main() {
    // Start the server
    start_server();

    return 0;
}