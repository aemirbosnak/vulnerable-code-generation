//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    char name[30];
} client_t;

client_t *clients[MAX_CLIENTS]; // Array to hold connected clients
int client_count = 0; // Count of connected clients
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client messages
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(client->socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        buffer[bytes_received] = '\0';
        
        // Broadcasting the received message
        char message[BUFFER_SIZE + 30];
        snprintf(message, sizeof(message), "%s: %s", client->name, buffer);
        broadcast_message(message, client->socket);
    }

    // Clean up and remove client
    close(client->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == client->socket) {
            free(clients[i]);
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

// Main function to set up the server
int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started on port %d\n", PORT);

    while (1) {
        // Accept new client
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Creating a new client structure
        client_t *client = malloc(sizeof(client_t));
        client->socket = new_socket;
        client->address = client_addr;
        client->addr_len = addrlen;
        strcpy(client->name, "Anonymous");

        // Add client to the clients array
        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = client;
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for the client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, client);
        pthread_detach(tid); // Detach thread to not keep track of it
    }

    close(server_fd);
    return 0;
}