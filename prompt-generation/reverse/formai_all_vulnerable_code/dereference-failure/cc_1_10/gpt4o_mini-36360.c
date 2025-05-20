//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send a message to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client communication
void *client_handler(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Client %d: %s", cli->socket, buffer);
        
        // Broadcast the message to other clients
        broadcast_message(buffer, cli->socket);
    }

    // Remove the client from the active list and close the socket
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(cli->socket);
    free(cli);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }
    
    printf("Chat server started on port %d\n", PORT);
    
    // Main accept loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Skip to the next iteration
        }

        printf("Client connected: %d\n", client_socket);
        
        // Allocate memory for the new client
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = client_socket;
        new_client->address = client_addr;
        new_client->addr_len = client_addr_len;

        // Add the new client to the clients list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
        
        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void *)new_client) != 0) {
            perror("Thread creation failed");
            free(new_client);
        }
    }
    
    // Close the server socket
    close(server_socket);
    return EXIT_SUCCESS;
}