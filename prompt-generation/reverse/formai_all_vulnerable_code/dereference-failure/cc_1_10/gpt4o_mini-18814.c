//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a client to the list
void add_client(client_t *cli) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!clients[i]) {
            clients[i] = cli;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to remove a client from the list
void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

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

// Function to handle client communication
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;

    while (1) {
        int bytes_received = recv(cli->socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected: %d\n", cli->socket);
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d: %s", cli->socket, buffer);
        broadcast_message(buffer, cli->socket);
    }

    close(cli->socket);
    remove_client(cli->socket);
    free(cli);
    return NULL;
}

// Function to start the server
void start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int address_length = sizeof(client_address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server started on port %d\n", PORT);

    while (1) {
        // Accept a new client
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length);
        if (client_socket < 0) {
            perror("Client acceptance failed");
            continue;
        }

        printf("New client connected: %d\n", client_socket);

        // Create a client structure and spawn a new thread for the client
        client_t *cli = malloc(sizeof(client_t));
        cli->socket = client_socket;
        cli->address = client_address;
        add_client(cli);
        
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
        pthread_detach(tid);
    }
}

int main() {
    start_server();
    return 0;
}