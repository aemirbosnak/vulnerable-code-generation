//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handler(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [listening port] [destination port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse command line arguments
    int listening_port = atoi(argv[1]);
    int destination_port = atoi(argv[2]);

    // Create listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        error_handler("Error: Failed to create listening socket");
    }

    // Bind listening socket to listening port
    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_addr.s_addr = INADDR_ANY;
    listening_address.sin_port = htons(listening_port);
    if (bind(listening_socket, (struct sockaddr*) &listening_address, sizeof(listening_address)) == -1) {
        error_handler("Error: Failed to bind listening socket");
    }

    // Listen for incoming connections
    if (listen(listening_socket, 1) == -1) {
        error_handler("Error: Failed to listen for incoming connections");
    }

    while (1) {
        // Accept incoming connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            error_handler("Error: Failed to accept incoming connection");
        }

        // Create destination socket
        int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_socket == -1) {
            error_handler("Error: Failed to create destination socket");
        }

        // Connect destination socket to destination port
        struct sockaddr_in destination_address;
        memset(&destination_address, 0, sizeof(destination_address));
        destination_address.sin_family = AF_INET;
        destination_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        destination_address.sin_port = htons(destination_port);
        if (connect(destination_socket, (struct sockaddr*) &destination_address, sizeof(destination_address)) == -1) {
            error_handler("Error: Failed to connect destination socket");
        }

        // Forward data between client socket and destination socket
        char buffer[BUFFER_SIZE];
        int bytes_received;
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            send(destination_socket, buffer, bytes_received, 0);
            bytes_received = recv(destination_socket, buffer, BUFFER_SIZE, 0);
            send(client_socket, buffer, bytes_received, 0);
        }

        // Close sockets
        close(client_socket);
        close(destination_socket);
    }

    // Close listening socket
    close(listening_socket);

    // Exit program
    return 0;
}