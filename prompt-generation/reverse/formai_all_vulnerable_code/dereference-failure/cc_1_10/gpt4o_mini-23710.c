//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client data
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle communication with clients
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client->socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client %d: %s", client->socket, buffer);
        
        // Broadcast message to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != NULL && clients[i]->socket != client->socket) {
                write(clients[i]->socket, buffer, bytes_read);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(client->socket);
    free(client);
    return NULL;
}

// Function for accepting clients and spawning threads
void *accept_clients(void *server_socket) {
    int sock = *(int *)server_socket;
    while (1) {
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->addr_len = sizeof(client->address);
        client->socket = accept(sock, (struct sockaddr *)&client->address, (socklen_t *)&client->addr_len);

        if (client->socket < 0) {
            perror("accept");
            free(client);
            continue;
        }

        printf("New client connected: %d\n", client->socket);

        // Add client to the clients array
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for the new client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("pthread_create");
        }
        pthread_detach(thread_id);
    }
    return NULL;
}

// Main function to set up the server
int main() {
    int server_socket;
    struct sockaddr_in server_address;

    // Initialize clients array
    memset(clients, 0, sizeof(clients));

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Start accepting clients
    accept_clients((void *)&server_socket);

    // Clean up
    close(server_socket);
    return 0;
}