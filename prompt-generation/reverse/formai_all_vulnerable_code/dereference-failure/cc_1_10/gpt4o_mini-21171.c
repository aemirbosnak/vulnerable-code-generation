//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
} Client;

Client *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(const char *message, int exclude_socket);
void add_client(Client *client);
void remove_client(int socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        Client *new_client = (Client *)malloc(sizeof(Client));
        new_client->socket = new_socket;
        new_client->address = client_address;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)new_client);
    }

    return 0;
}

void *handle_client(void *arg) {
    Client *client = (Client *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Add new client to the list
    add_client(client);
    
    while ((read_size = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message: %s\n", buffer);
        
        // Broadcast the message to other clients
        broadcast_message(buffer, client->socket);
    }
    
    // Client disconnected
    remove_client(client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

void broadcast_message(const char *message, int exclude_socket) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != exclude_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_mutex);
}

void add_client(Client *client) {
    pthread_mutex_lock(&client_mutex);
    clients[client_count++] = client;
    pthread_mutex_unlock(&client_mutex);
}

void remove_client(int socket) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == socket) {
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
}