//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: complex
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
    int socket_fd;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS]; // Array to hold connected clients

// Function prototypes
void *handle_client(void *arg);
void broadcast_message(char *message, int sender_sock);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port and IP
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Store the client information
        client_t *client = malloc(sizeof(client_t));
        client->socket_fd = new_socket;
        client->address = address;

        // Add client to the clients array
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                break;
            }
        }

        // Create a new thread for the connected client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("Thread creation failed");
            close(new_socket);
            free(client);
        } else {
            pthread_detach(thread_id);
        }
    }

    // Close the server socket
    close(server_fd);
    return 0;
}

// Function to handle client communication
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client->socket_fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the string
        printf("Message from client: %s\n", buffer);
        broadcast_message(buffer, client->socket_fd);
    }

    // Remove the client and close the socket
    close(client->socket_fd);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == client) {
            clients[i] = NULL;
            break;
        }
    }
    free(client);
    return NULL;
}

// Function to broadcast messages to all clients
void broadcast_message(char *message, int sender_sock) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket_fd != sender_sock) {
            send(clients[i]->socket_fd, message, strlen(message), 0);
        }
    }
}