//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Claude Shannon
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
    int addr_len;
} client_t;

// Array to store active clients
client_t *clients[MAX_CLIENTS];

// Function for adding clients to the array
void add_client(client_t *client) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!clients[i]) {
            clients[i] = client;
            return;
        }
    }
    free(client);
    printf("Max clients reached. Connection rejected.\n");
}

// Function for removing clients from the array
void remove_client(int socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == socket) {
            free(clients[i]);
            clients[i] = NULL;
            return;
        }
    }
}

// Broadcast message to all connected clients
void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

// Function to handle client communication
void *client_handler(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client [%s:%d]: %s", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port), buffer);
        broadcast_message(buffer, client->socket);
    }

    printf("Client [%s:%d] disconnected.\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
    remove_client(client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

// Main server function
int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Zero out the clients array
    memset(clients, 0, sizeof(clients));

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->addr_len = sizeof(new_client->address);
        new_client->socket = accept(server_fd, (struct sockaddr *)&new_client->address, &new_client->addr_len);
        
        if (new_client->socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        printf("New client connected: [%s:%d]\n", inet_ntoa(new_client->address.sin_addr), ntohs(new_client->address.sin_port));
        add_client(new_client);

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, (void *)new_client) != 0) {
            perror("Thread creation failed");
            close(new_client->socket);
            free(new_client);
        }
    }

    close(server_fd);
    return 0;
}