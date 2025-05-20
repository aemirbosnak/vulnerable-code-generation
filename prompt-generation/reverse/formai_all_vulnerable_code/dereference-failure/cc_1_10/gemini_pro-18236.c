//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MESSAGE_LENGTH 1024
#define PORT 8080

// Structure to store client information
typedef struct client {
    int socket;
    char name[MAX_MESSAGE_LENGTH];
} client;

// Array to store connected clients
client clients[MAX_CLIENTS];

// Mutex to protect the clients array
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send a message to all connected clients
void broadcast_message(char *message) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket != -1) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

// Function to handle a new client connection
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char message[MAX_MESSAGE_LENGTH];

    // Receive the client's name
    recv(client_socket, message, sizeof(message), 0);
    strcpy(clients[client_socket].name, message);

    // Send a welcome message to the client
    sprintf(message, "Welcome to the chat server, %s!", clients[client_socket].name);
    send(client_socket, message, strlen(message), 0);

    // Broadcast the new client's name to all other clients
    sprintf(message, "%s has joined the chat!", clients[client_socket].name);
    broadcast_message(message);

    // Receive messages from the client and broadcast them to all other clients
    while (1) {
        memset(message, 0, sizeof(message));
        recv(client_socket, message, sizeof(message), 0);

        if (strcmp(message, "exit") == 0) {
            // Client has requested to exit
            break;
        }

        // Broadcast the message to all other clients
        sprintf(message, "%s: %s", clients[client_socket].name, message);
        broadcast_message(message);
    }

    // Remove the client from the list of connected clients
    pthread_mutex_lock(&clients_mutex);
    clients[client_socket].socket = -1;
    pthread_mutex_unlock(&clients_mutex);

    // Broadcast the client's departure to all other clients
    sprintf(message, "%s has left the chat!", clients[client_socket].name);
    broadcast_message(message);

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    pthread_t client_thread;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create server socket");
        return 1;
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Could not bind server socket to address");
        return 1;
    }

    // Listen for incoming client connections
    if (listen(server_socket, 5) == -1) {
        perror("Could not listen for incoming client connections");
        return 1;
    }

    printf("Chat server is now running on port %d\n", PORT);

    // Main loop: accept client connections and create a new thread for each client
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Could not accept client connection");
            continue;
        }

        // Create a new thread to handle the client
        pthread_create(&client_thread, NULL, handle_client, &client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}