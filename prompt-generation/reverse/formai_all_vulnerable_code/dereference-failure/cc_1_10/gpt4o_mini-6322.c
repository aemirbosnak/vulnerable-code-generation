//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
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
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle communication with a connected client
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int received;

    while ((received = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[received] = '\0';
        printf("Client %d sent: %s\n", cli->socket, buffer);
        broadcast_message(buffer, cli->socket);
    }

    // Client disconnected
    close(cli->socket);
    free(cli);
    return NULL;
}

// Function to add client to the list of clients
void add_client(client_t *cli) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = cli;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to remove client from the list of clients
void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket == socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    pthread_t tid;

    // Initialize server_socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port %d...\n", PORT);
    
    while (1) {
        // Accept new client connections
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len);
        if (client_socket < 0) {
            perror("Accepting failed");
            continue;
        }

        printf("Client %d connected.\n", client_socket);

        // Create a new client instance
        client_t *cli = malloc(sizeof(client_t));
        cli->socket = client_socket;
        cli->address = client_address;
        cli->addr_len = addr_len;

        // Add client to the list
        add_client(cli);

        // Create a new thread to handle the client
        if (pthread_create(&tid, NULL, handle_client, (void *)cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
    }

    // Cleanup
    close(server_socket);
    return 0;
}