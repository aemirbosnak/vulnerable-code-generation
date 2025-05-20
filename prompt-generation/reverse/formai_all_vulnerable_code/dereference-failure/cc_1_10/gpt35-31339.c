//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

// Function to handle each client connection
void handle_client(int client_socket) {
    // Set up a buffer for reading from the client
    char buffer[BUFFER_SIZE];

    // Read the request from the client
    ssize_t bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);

    if (bytes_read < 0) {
        perror("Error reading from client");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the request string
    buffer[bytes_read] = '\0';

    // Parse the request string to determine the requested hostname and port
    char *hostname_start = strstr(buffer, "Host: ") + 6;
    char *hostname_end = strstr(hostname_start, "\r\n");
    char *port_start = strstr(hostname_start, ":");
    char *port_end = strstr(hostname_start, "\r\n");
    int port = 80;

    if (port_start != NULL) {
        port_start++;
        port_end = strstr(port_start, "\r\n");
        port = atoi(port_start);
    }

    // Open a connection to the requested hostname and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    // Convert the hostname string to an IP address
    struct in_addr *address = malloc(sizeof(struct in_addr));
    inet_pton(AF_INET, hostname_start, address);
    server_address.sin_addr = *address;

    // Create a new socket for communication with the remote server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the remote server using the newly created socket
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Forward the client's request to the remote server
    int bytes_sent = send(server_socket, buffer, bytes_read, 0);

    if (bytes_sent < 0) {
        perror("Error sending request to server");
        exit(EXIT_FAILURE);
    }

    // Forward the server's response back to the client
    char server_buffer[BUFFER_SIZE];

    while ((bytes_read = read(server_socket, server_buffer, BUFFER_SIZE - 1)) > 0) {
        bytes_sent = send(client_socket, server_buffer, bytes_read, 0);

        if (bytes_sent < 0) {
            perror("Error sending response to client");
            exit(EXIT_FAILURE);
        }

        memset(server_buffer, 0, BUFFER_SIZE);
    }

    // Close the sockets
    close(client_socket);
    close(server_socket);
    free(address);
}

int main(int argc, char *argv[]) {
    // Parse command line arguments to determine the listening port
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int listening_port = atoi(argv[1]);

    // Set up a socket for listening for incoming client connections
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("Error creating listening socket");
        exit(EXIT_FAILURE);
    }

    // Bind the listening socket to the specified port
    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(listening_port);
    listening_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listening_socket, (struct sockaddr *)&listening_address, sizeof(listening_address)) < 0) {
        perror("Error binding listening socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if (listen(listening_socket, 10) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on port %d...\n", listening_port);

    while (1) {
        // Accept incoming client connections
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(listening_socket, (struct sockaddr *)&client_address, &client_address_length);

        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Handle the client connection in a separate thread
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error forking child process");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            // We're in the child process
            handle_client(client_socket);
            exit(EXIT_SUCCESS);
        }
        else {
            // We're in the parent process
            close(client_socket);
        }
    }
}