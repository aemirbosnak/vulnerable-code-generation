//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 100

// Client structure
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} Client;

// Global array to hold client sockets
Client* clients[MAX_CLIENTS];
int client_count = 0;

// Function to handle each client
void* handle_client(void* arg) {
    Client* client = (Client*)arg;
    char buffer[BUFFER_SIZE];
    int len;

    printf("Client connected: %s:%d\n", 
           inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));

    while ((len = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[len] = '\0'; // Null-terminate the received string

        printf("Message from %s:%d: %s\n", 
               inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port), buffer);

        // Broadcast the message to other clients
        for (int i = 0; i < client_count; i++) {
            if (clients[i]->socket != client->socket) {
                send(clients[i]->socket, buffer, len, 0);
            }
        }
    }

    // Client disconnected
    printf("Client disconnected: %s:%d\n", 
           inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
    close(client->socket);
    free(client);
    return NULL;
}

// Main function to start the server
int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started! Listening on port %d\n", PORT);

    while (1) {
        // Accept new client connections
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, 
                                 (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Check if max clients reached
        if (client_count < MAX_CLIENTS) {
            Client* new_client = (Client*)malloc(sizeof(Client));
            new_client->socket = new_socket;
            new_client->address = address;
            new_client->addr_len = addrlen;

            clients[client_count++] = new_client;

            // Create a new thread for the client
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, new_client);
            pthread_detach(tid); // Detach so it can clean up when finished
        } else {
            printf("Max client limit reached! Rejecting new client...\n");
            close(new_socket);
        }
    }

    return 0;
}