//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of clients that can be connected to the server
#define MAX_CLIENTS 10

// Define the buffer size for the data that will be sent to and received from clients
#define BUFFER_SIZE 1024

// Define the structure of a client
typedef struct client {
    int socket_fd;
    struct sockaddr_in address;
    pthread_t thread_id;
} client_t;

// Define the structure of the server
typedef struct server {
    int socket_fd;
    struct sockaddr_in address;
    client_t clients[MAX_CLIENTS];
    int num_clients;
} server_t;

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client structure from the argument
    client_t *client = (client_t *)arg;

    // Receive the data from the client
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client->socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        // The client has disconnected
        printf("Client disconnected: %s\n", inet_ntoa(client->address.sin_addr));
        close(client->socket_fd);
        free(client);
        return NULL;
    }

    // Send the data back to the client
    int bytes_sent = send(client->socket_fd, buffer, bytes_received, 0);
    if (bytes_sent <= 0) {
        // The client has disconnected
        printf("Client disconnected: %s\n", inet_ntoa(client->address.sin_addr));
        close(client->socket_fd);
        free(client);
        return NULL;
    }

    // Close the client socket
    close(client->socket_fd);

    // Free the client structure
    free(client);

    return NULL;
}

// Function to start the server
void start_server(server_t *server) {
    // Create the server socket
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server->socket_fd, (struct sockaddr *)&server->address, sizeof(server->address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server->socket_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming client connections
    while (1) {
        // Accept a new client connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket_fd = accept(server->socket_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket_fd == -1) {
            perror("accept");
            continue;
        }

        // Create a new client structure
        client_t *client = malloc(sizeof(client_t));
        client->socket_fd = client_socket_fd;
        client->address = client_address;

        // Add the new client to the server
        server->clients[server->num_clients++] = *client;

        // Create a new thread to handle the client connection
        pthread_create(&client->thread_id, NULL, handle_client, client);
    }

    // Close the server socket
    close(server->socket_fd);
}

// Main function
int main() {
    // Create the server
    server_t server;

    // Start the server
    start_server(&server);

    return 0;
}