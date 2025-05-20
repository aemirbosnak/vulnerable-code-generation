//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];

// Function to handle communication with a connected client
void *handle_client(void *arg) {
    client_t *client_info = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_info->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Client [%d]: %s\n", client_info->socket, buffer);

        // Echo the message to all connected clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != NULL && clients[i]->socket != client_info->socket) {
                send(clients[i]->socket, buffer, bytes_read, 0);
            }
        }
    }

    // Client disconnected, cleaning up
    printf("Client [%d] disconnected\n", client_info->socket);
    close(client_info->socket);
    free(client_info);
    return NULL;
}

// Function to add a client to the list of clients
void add_client(int client_socket, struct sockaddr_in address) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            client_t *new_client = (client_t *)malloc(sizeof(client_t));
            new_client->socket = client_socket;
            new_client->address = address;
            clients[i] = new_client;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)new_client);
            pthread_detach(thread_id);
            return;
        }
    }
    printf("Max clients connected. Refusing new client.\n");
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);

    // Initialize client list
    memset(clients, 0, sizeof(clients));

    // Create the socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Main loop to accept incoming clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("New client connected: %d\n", client_socket);
        add_client(client_socket, client_address);
    }

    // Cleanup before exiting
    close(server_socket);
    return 0;
}