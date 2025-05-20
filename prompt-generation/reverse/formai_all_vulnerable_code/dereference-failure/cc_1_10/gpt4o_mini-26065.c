//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Struct to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_info;

// Array to hold client sockets
client_info *clients[MAX_CLIENTS];
int client_count = 0;

// Function to send message to all clients
void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

// Function to handle client communication
void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Receive messages from the client
    while ((bytes_read = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Client [%d]: %s", client->socket, buffer);

        // Broadcast the received message
        char message[BUFFER_SIZE + 50];
        snprintf(message, sizeof(message), "Client [%d]: %s", client->socket, buffer);
        broadcast_message(message, client->socket);
    }

    // Clean up client socket on disconnection
    printf("Client [%d] disconnected.\n", client->socket);
    close(client->socket);
    free(client);
    
    // Remove client from the array
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == client->socket) {
            for (int j = i; j < client_count - 1; j++) {
                clients[j] = clients[j + 1];
            }
            client_count--;
            break;
        }
    }

    pthread_exit(NULL);
}

// Function to start the server
void start_server() {
    int server_socket;
    struct sockaddr_in server_address;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        client_info *new_client = malloc(sizeof(client_info));
        new_client->addr_len = sizeof(new_client->address);
        new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, (socklen_t *)&new_client->addr_len);
        
        if (new_client->socket < 0) {
            perror("Client accept failed");
            free(new_client);
            continue;
        }

        printf("Client [%d] connected.\n", new_client->socket);
        
        // Store the client in the clients array
        clients[client_count++] = new_client;

        // Create a thread for the new client
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
    }
}

int main() {
    start_server();
    return 0;
}