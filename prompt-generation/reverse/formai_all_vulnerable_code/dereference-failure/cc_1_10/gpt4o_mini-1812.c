//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080                   // Server port
#define MAX_CLIENTS 10              // Maximum clients
#define BUFFER_SIZE 1024            // Buffer size for messages

// Global variables to track stats
int message_count = 0;
pthread_mutex_t lock;

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Function prototypes
void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
void print_stats();

// Main function
int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Initialize server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    pthread_mutex_init(&lock, NULL);
    
    // Create a new thread for statistics
    pthread_t stats_thread;
    pthread_create(&stats_thread, NULL, (void *)print_stats, NULL);

    // Accept clients
    while (1) {
        client_t *client = malloc(sizeof(client_t));
        client->addr_len = addr_len;
        if ((client->socket = accept(server_socket, (struct sockaddr *)&client->address, &client->addr_len)) < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }

        printf("New client connected: socket fd %d\n", client->socket);

        // Create a new thread for the client
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void *)client);
    }

    close(server_socket);
    pthread_mutex_destroy(&lock);
    return 0;
}

// Function to handle individual client communication
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Loop for receiving messages
    while ((read_size = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message: %s\n", buffer);
        
        // Lock and increment message count
        pthread_mutex_lock(&lock);
        message_count++;
        pthread_mutex_unlock(&lock);
        
        // Broadcast the message to all connected clients
        broadcast_message(buffer, client->socket);
    }

    if (read_size == 0) {
        printf("Client disconnected: socket fd %d\n", client->socket);
        fflush(stdout);
    } else {
        perror("Receive failed");
    }

    close(client->socket);
    free(client);
    return NULL;
}

// Function to broadcast messages to all clients
void broadcast_message(char *message, int sender_socket) {
    // In a real application, we would need to keep track of all client sockets
    // Here we would broadcast to all existing clients (pseudocode)
    // send(client_socket, message, strlen(message), 0); 
}

// Function to print statistics every 5 seconds
void print_stats() {
    while (1) {
        sleep(5);
        pthread_mutex_lock(&lock);
        printf("\nStatistics: Total messages exchanged: %d \n", message_count);
        pthread_mutex_unlock(&lock);
    }
}