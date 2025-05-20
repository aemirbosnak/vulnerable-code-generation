//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client details
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];

// Mutex for managing client connections
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client connection
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int read_size;
    client_t *client = (client_t *)arg;

    while ((read_size = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the message
        printf("Client %d: %s", client->socket, buffer);
        broadcast_message(buffer, client->socket);
    }

    // Remove client from the list on disconnect
    close(client->socket);
    free(client);
    pthread_exit(NULL);
}

// Function to accept client connections
void accept_clients(int server_socket) {
    struct sockaddr_in client_address;
    int addr_len = sizeof(client_address);
    while (1) {
        int new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Create client struct and add to list
        client_t *new_client = malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = client_address;
        new_client->addr_len = addr_len;

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        printf("New client connected: %d\n", new_socket);

        // Create a thread to handle the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_client) != 0) {
            perror("Thread creation failed");
            free(new_client);
        }
    }
}

int main() {
    // Initialize the server socket
    int server_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);
    accept_clients(server_socket);

    // Cleanup
    close(server_socket);
    return 0;
}