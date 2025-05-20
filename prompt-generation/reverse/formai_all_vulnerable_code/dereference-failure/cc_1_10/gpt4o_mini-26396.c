//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: mind-bending
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
} client_info;

// Function prototypes
void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_info *new_client = malloc(sizeof(client_info));
        new_client->addr_len = sizeof(new_client->address);
        // Accept a new client
        if ((new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, (socklen_t*)&new_client->addr_len)) == -1) {
            perror("Client acceptance failed");
            free(new_client);
            continue;
        }

        // Manage a new client
        printf("New client connected: %d\n", new_client->socket);
        client_sockets[client_count++] = new_client->socket;
        
        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_client) != 0) {
            perror("Thread creation failed");
            close(new_client->socket);
            free(new_client);
        }
    }

    // Close server socket, never reaches here
    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client->socket, buffer);
        broadcast_message(buffer, client->socket);
    }

    // Remove client from the list
    for (int i = 0; i < client_count; ++i) {
        if (client_sockets[i] == client->socket) {
            client_sockets[i] = client_sockets[--client_count]; // Remove and replace with last
            break;
        }
    }

    printf("Client %d disconnected\n", client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}