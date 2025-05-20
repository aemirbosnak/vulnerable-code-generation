//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold information about each client
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

// Array to hold client sockets
client_t *clients[MAX_CLIENTS];

void *handle_client(void *arg);
void send_message_to_all(const char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("🌟 Welcome to the Happy Chat Server! Listening on port %d... 🌟\n", PORT);
    
    for (int i = 0; i < MAX_CLIENTS; i++) {
        socklen_t addrlen = sizeof(client_address);
        
        // Accept a new connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue to next iteration to accept more clients
        }

        // Allocate memory for the new client and store the client information
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = client_socket;
        new_client->address = client_address;
        clients[i] = new_client;

        // Create a new thread to handle communication with this client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, new_client) != 0) {
            perror("Could not create thread");
            free(new_client);
        } else {
            printf("🌈 New client connected! 🎉\n");
        }
    }

    close(server_socket);
    return 0;
}

// Function to handle communication with a specific client
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate string
        printf("💬 Client says: %s", buffer);
        send_message_to_all(buffer, client->socket);
    }

    printf("🎈 Client disconnected!\n");
    remove_client(client->socket);
    free(client);
    return NULL;
}

// Function to send a message from one client to all other clients
void send_message_to_all(const char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

// Function to remove a client from the array
void remove_client(int socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket == socket) {
            close(socket);
            free(clients[i]);
            clients[i] = NULL;
            printf("🌟 Client has been removed from the chat! 🌟\n");
            break;
        }
    }
}