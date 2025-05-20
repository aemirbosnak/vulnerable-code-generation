//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: detailed
// Simple C Socket Programming Example: Multithreaded Echo Server

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <pthread.h> 
#include <unistd.h>

// Port number for the server
#define PORT 8080 

// Maximum number of client connections that can be handled simultaneously
#define MAX_CONNECTIONS 10

// Thread structure to store client connection details
typedef struct client_info {
    int socket_fd;
    struct sockaddr_in client_address;
    int client_address_len;
} client_info_t;

// Function to handle client requests
void* handle_client(void* arg) {
    // Get the client information from the argument
    client_info_t* client_info = (client_info_t*) arg;

    // Create a buffer to receive data from the client
    char buffer[1024];

    // Receive data from the client
    int bytes_received = recv(client_info->socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        perror("Error receiving data from client");
        close(client_info->socket_fd);
        pthread_exit(NULL);
    }

    // Echo the data back to the client
    int bytes_sent = send(client_info->socket_fd, buffer, bytes_received, 0);
    if (bytes_sent <= 0) {
        perror("Error sending data to client");
        close(client_info->socket_fd);
        pthread_exit(NULL);
    }

    // Close the client socket
    close(client_info->socket_fd);
    pthread_exit(NULL);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options to allow multiple connections
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Error setting socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    // Create a thread pool to handle client requests
    pthread_t thread_pool[MAX_CONNECTIONS];
    int thread_count = 0;

    // Continuously accept and handle client connections
    while (1) {
        // Accept a new client connection
        client_info_t client_info;
        client_info.client_address_len = sizeof(client_info.client_address);
        client_info.socket_fd = accept(server_socket, (struct sockaddr*) &client_info.client_address, &client_info.client_address_len);
        if (client_info.socket_fd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Create a new thread to handle the client request
        if (pthread_create(&thread_pool[thread_count++], NULL, handle_client, (void*) &client_info) != 0) {
            perror("Error creating thread");
            close(client_info.socket_fd);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}