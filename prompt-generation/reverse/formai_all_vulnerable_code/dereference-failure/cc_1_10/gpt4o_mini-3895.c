//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: detailed
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
} Client;

// Function declarations
void *client_handler(void *arg);
void broadcast_message(const char *message, int sender_socket);

// Array to hold active clients
Client clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);
    
    while (1) {
        Client new_client;
        socklen_t addr_len = sizeof(new_client.address);
        
        // Accept new client connection
        if ((new_client.socket = accept(server_socket, (struct sockaddr *)&new_client.address, &addr_len)) < 0) {
            perror("Accept failed");
            continue; // Accept failed, continue listening
        }

        printf("New client connected: %d\n", new_client.socket);

        // Add new client to clients array
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_client;
        } else {
            printf("Max clients reached. Connection refused for socket: %d\n", new_client.socket);
            close(new_client.socket);
            pthread_mutex_unlock(&clients_mutex);
            continue;
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a new thread for the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_client) != 0) {
            perror("Thread creation failed");
            close(new_client.socket);
        }
    }

    close(server_socket);
    return 0;
}

// Function to handle client communication
void *client_handler(void *arg) {
    Client client = *(Client *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // Receive message from client
        if ((bytes_read = read(client.socket, buffer, BUFFER_SIZE - 1)) > 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the buffer
            printf("Message from client %d: %s", client.socket, buffer);
            broadcast_message(buffer, client.socket); // Broadcast message to other clients
        } else {
            printf("Client %d disconnected or an error occurred.\n", client.socket);
            break; // Exit loop if the client disconnected or an error occurred
        }
    }

    // Remove client from clients array
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == client.socket) {
            close(clients[i].socket);
            clients[i] = clients[--client_count]; // Remove client from array
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

// Function to broadcast messages to all clients except the sender
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_socket) {
            write(clients[i].socket, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}