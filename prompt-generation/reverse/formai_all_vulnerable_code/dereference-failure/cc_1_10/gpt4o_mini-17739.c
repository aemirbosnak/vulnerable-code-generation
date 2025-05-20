//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

// Default server port
#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr address;
    int addr_len;
} client_t;

// Array to hold active clients and a mutex for threading
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to log messages with timestamps
void log_message(const char *message) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline
    printf("[%s] %s\n", timestamp, message);
}

// Function to handle client communication
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;

    // Welcome message
    log_message("New client connected");
    snprintf(buffer, sizeof(buffer), "Welcome to the Futuristic Chat Server!\n");
    send(client->socket, buffer, strlen(buffer), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE - 1, 0);

        if (bytes_received <= 0) {
            // Client disconnected
            break;
        }

        // Print and broadcast message
        buffer[bytes_received] = '\0'; // Null-terminate the string
        log_message(buffer);

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != client->socket) {
                send(clients[i]->socket, buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Cleanup on disconnect
    close(client->socket);
    free(client);
    log_message("Client disconnected");
    return NULL;
}

// Function to set up server socket
int setup_server_socket() {
    int server_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

// Function to accept new client connections
void accept_clients(int server_socket) {
    while (1) {
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->addr_len = sizeof(client->address);
        client->socket = accept(server_socket, &client->address, (socklen_t *)&client->addr_len);

        if (client->socket < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }

        // Add client to the pool
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (!clients[i]) {
                clients[i] = client;
                pthread_t tid;
                pthread_create(&tid, NULL, handle_client, (void *)client);
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
}

int main() {
    log_message("Futuristic Chat Server is starting...");
    int server_socket = setup_server_socket();
    log_message("Server setup complete. Waiting for clients...");

    accept_clients(server_socket);

    // Cleanup and close server socket
    close(server_socket);
    log_message("Server terminated.");
    return 0;
}