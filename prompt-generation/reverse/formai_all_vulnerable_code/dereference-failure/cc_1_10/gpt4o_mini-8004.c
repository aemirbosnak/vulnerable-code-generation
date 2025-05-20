//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Struct to manage client data
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client communication
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;
    int received;

    while ((received = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[received] = '\0'; // Null terminate the received message
        printf("Client %d sent: %s\n", client->socket, buffer);
        
        // Broadcast to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != client->socket) {
                send(clients[i]->socket, buffer, received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Remove client upon disconnection
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == client->socket) {
            free(clients[i]);
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client->socket);
    printf("Client %d disconnected.\n", client->socket);
    free(client);
    return NULL;
}

// Main function to start the server
int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Initialize socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_t *client = malloc(sizeof(client_t));
        socklen_t addrlen = sizeof(client->address);

        // Accept a new client connection
        client->socket = accept(server_socket, (struct sockaddr *)&client->address, &addrlen);
        if (client->socket < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }

        printf("New client connected: %d\n", client->socket);

        // Add client to the list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for each client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, client) != 0) {
            perror("Thread creation failed");
            close(client->socket);
            free(client);
        }
        pthread_detach(thread); // Detach the thread to reclaim resources on exit
    }

    // Clean-up
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i]) {
            close(clients[i]->socket);
            free(clients[i]);
        }
    }
    close(server_socket);
    return EXIT_SUCCESS;
}