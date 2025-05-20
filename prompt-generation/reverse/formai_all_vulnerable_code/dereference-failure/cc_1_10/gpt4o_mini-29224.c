//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: brave
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
    int addr_len;
    char name[30];
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a client to the clients array
void add_client(client_t *cl) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to remove a client from the clients array
void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket == socket) {
            free(clients[i]);
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to broadcast messages to all clients
void broadcast(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle each client connection
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int read_size;
    client_t *client = (client_t *)arg;

    // Welcome message
    snprintf(buffer, sizeof(buffer), "%s has joined the chat\n", client->name);
    broadcast(buffer, client->socket);

    // Communication loop
    while ((read_size = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the buffer
        printf("%s: %s", client->name, buffer); // Print to server console
        broadcast(buffer, client->socket); // Send message to other clients
    }

    // Cleanup when client disconnects
    remove_client(client->socket);
    snprintf(buffer, sizeof(buffer), "%s has left the chat\n", client->name);
    broadcast(buffer, client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

// Main function to start the server
int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket Creation Failed");
        return EXIT_FAILURE;
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding Failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Start listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listening Failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Chat Server started on port %d\n", PORT);

    // Accept clients indefinitely
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen))) {
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = client_addr;
        new_client->addr_len = addrlen;
        // Ask for a client name
        send(new_socket, "Enter your name: ", 17, 0);
        recv(new_socket, new_client->name, sizeof(new_client->name) - 1, 0);

        add_client(new_client);
        printf("%s connected.\n", new_client->name);

        // Create a thread for the new client
        if (pthread_create(&tid, NULL, handle_client, (void *)new_client) != 0) {
            perror("Failed to create thread");
        }
    }

    // Close server socket on exit
    close(server_socket);
    return EXIT_SUCCESS;
}