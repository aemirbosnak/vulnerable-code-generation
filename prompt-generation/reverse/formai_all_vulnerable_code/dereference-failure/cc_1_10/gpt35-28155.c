//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define BUFFER_SIZE 4096

// Forward declarations
void handle_error(const char *error_message);

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: ./proxy <port> <destination>\n");
        printf("Example: ./proxy 8080 www.google.com\n");
        exit(EXIT_FAILURE);
    }

    // Parse port number
    int port = atoi(argv[1]);

    // Create socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        handle_error("Unable to create listening socket.");
    }

    // Bind socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(listening_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        handle_error("Unable to bind listening socket.");
    }

    // Listen for incoming connections
    if (listen(listening_socket, 10) == -1) {
        handle_error("Unable to start listening on socket.");
    }

    // Accept incoming connections
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);
    int client_socket;

    while(1) {
        client_socket = accept(listening_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            handle_error("Unable to accept incoming connection.");
        }

        // Create new child process to handle connection
        pid_t pid = fork();
        if (pid == -1) {
            handle_error("Unable to create child process.");
        }

        if (pid == 0) {
            close(listening_socket);

            // Connect to destination server
            int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (destination_socket == -1) {
                handle_error("Unable to create destination socket.");
            }

            struct sockaddr_in destination_address;
            destination_address.sin_family = AF_INET;
            destination_address.sin_addr.s_addr = inet_addr(argv[2]);
            destination_address.sin_port = htons(80);

            if (connect(destination_socket, (struct sockaddr *)&destination_address, sizeof(destination_address)) == -1) {
                handle_error("Unable to connect to destination server.");
            }

            // Read request from client
            char buffer[BUFFER_SIZE];
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1) {
                handle_error("Unable to read request from client.");
            }

            // Forward request to destination server
            if (send(destination_socket, buffer, bytes_received, 0) == -1) {
                handle_error("Unable to forward request to destination server.");
            }

            // Read response from destination server
            bytes_received = recv(destination_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1) {
                handle_error("Unable to read response from destination server.");
            }

            // Forward response to client
            if (send(client_socket, buffer, bytes_received, 0) == -1) {
                handle_error("Unable to forward response to client.");
            }

            close(client_socket);
            close(destination_socket);
            exit(EXIT_SUCCESS);
        }

        close(client_socket);
    }

    close(listening_socket);

    return 0;
}

void handle_error(const char *error_message) {
    perror(error_message);
    exit(EXIT_FAILURE); 
}