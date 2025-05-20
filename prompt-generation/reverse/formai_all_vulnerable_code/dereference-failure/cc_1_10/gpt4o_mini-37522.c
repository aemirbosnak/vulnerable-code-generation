//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle clients
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int received_length;
    client_t *client = (client_t *)arg;

    printf("Client connected: %s:%d\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
    
    while ((received_length = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_length] = '\0';
        printf("Received from %s: %s", inet_ntoa(client->address.sin_addr), buffer);
        
        // Broadcasting the message
        broadcast_message(buffer, client->socket);
    }

    // Clean up
    close(client->socket);
    free(client);
    printf("Client disconnected: %s:%d\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
    
    return NULL;
}

// Main entry point for the server
int main() {
    int server_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);

    // Create the listening socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Set socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Initializing server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    printf("Chat server is listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->addr_len = sizeof(new_client->address);
        new_client->socket = accept(server_socket, (struct sockaddr*)&new_client->address, &new_client->addr_len);
        
        if (new_client->socket < 0) {
            perror("Client accept failed");
            free(new_client);
            continue;
        }

        // Store the client in the array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (!clients[i]) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a client handler thread
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void*) new_client) != 0) {
            perror("Failed to create thread");
            free(new_client);
        }
        pthread_detach(tid); // No need to join, detached threads
    }

    // Cleanup (not reached in normal execution)
    close(server_socket);
    return EXIT_SUCCESS;
}