//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Struct to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];

// Function to broadcast message to all clients
void broadcast_message(const char *message, int exclude_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != exclude_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

void *client_handler(void *client_struct) {
    client_t *client = (client_t *)client_struct;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client says: %s\n", buffer);
        broadcast_message(buffer, client->socket);
    }

    printf("Client disconnected: %d\n", client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server started on port %d...\n", PORT);

    // Main server loop
    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %d\n", new_socket);

        // Create a new client structure
        client_t *new_client = malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = client_addr;

        // Add client to the client list
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = new_client;
                break;
            }
        }

        // Create a thread to handle the client
        if (pthread_create(&tid, NULL, client_handler, (void *)new_client) != 0) {
            perror("Thread creation failed");
            free(new_client);
        }

        // Detach the thread so that we don't need to join it later
        pthread_detach(tid);
    }

    close(server_socket);
    return 0;
}