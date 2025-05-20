//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Structure to hold client data
struct client {
    int socket;
    struct sockaddr_in address;
    int addr_len;
};

// Global variables
struct client clients[MAX_CLIENTS];
int client_count = 0;

// Mutex for thread safety
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client communications
void* handle_client(void* arg) {
    struct client* cli = (struct client*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        bytes_read = recv(cli->socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read <= 0) {
            break;
        }
        buffer[bytes_read] = '\0';
        
        // Process received data
        printf("Received from client: %s\n", buffer);
        send(cli->socket, buffer, bytes_read, 0); // Echo back to client
    }

    // Remove and close client socket
    close(cli->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == cli->socket) {
            clients[i] = clients[client_count - 1]; // Replace with last client
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    return NULL;
}

// Main function
int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((new_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Handle new client
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            struct client* new_client = (struct client*)malloc(sizeof(struct client));
            new_client->socket = new_socket;
            new_client->address = address;
            new_client->addr_len = addrlen;

            clients[client_count++] = *new_client; // Add new client to the array
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, new_client);
            pthread_detach(tid); // Detach thread
        } else {
            printf("Max clients reached. Connection rejected.\n");
            close(new_socket);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Clean up and close server socket
    close(server_socket);
    return 0;
}