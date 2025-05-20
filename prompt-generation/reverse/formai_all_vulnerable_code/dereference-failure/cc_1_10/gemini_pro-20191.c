//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

struct client_data {
    int socket;
    char name[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size;
};

struct server_data {
    int socket;
    struct client_data clients[MAX_CLIENTS];
    int num_clients;
    pthread_mutex_t mutex;
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *)arg;
    struct server_data *server_data = (struct server_data *)client_data->socket;

    // Receive the client's name
    int recv_size = recv(client_data->socket, client_data->name, MAX_BUFFER_SIZE, 0);
    if (recv_size <= 0) {
        printf("Error receiving client name\n");
        pthread_exit(NULL);
    }

    // Lock the mutex to protect the server data
    pthread_mutex_lock(&server_data->mutex);

    // Add the client to the list of clients
    server_data->clients[server_data->num_clients++] = *client_data;

    // Unlock the mutex
    pthread_mutex_unlock(&server_data->mutex);

    // Send a welcome message to the client
    char welcome_message[] = "Welcome to the chat server!\n";
    send(client_data->socket, welcome_message, strlen(welcome_message), 0);

    // Loop until the client disconnects
    while (1) {
        // Receive a message from the client
        recv_size = recv(client_data->socket, client_data->buffer, MAX_BUFFER_SIZE, 0);
        if (recv_size <= 0) {
            break;
        }

        // Lock the mutex to protect the server data
        pthread_mutex_lock(&server_data->mutex);

        // Broadcast the message to all clients
        for (int i = 0; i < server_data->num_clients; i++) {
            if (server_data->clients[i].socket != client_data->socket) {
                send(server_data->clients[i].socket, client_data->buffer, recv_size, 0);
            }
        }

        // Unlock the mutex
        pthread_mutex_unlock(&server_data->mutex);
    }

    // Lock the mutex to protect the server data
    pthread_mutex_lock(&server_data->mutex);

    // Remove the client from the list of clients
    for (int i = 0; i < server_data->num_clients; i++) {
        if (server_data->clients[i].socket == client_data->socket) {
            server_data->clients[i] = server_data->clients[server_data->num_clients - 1];
            server_data->num_clients--;
            break;
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&server_data->mutex);

    // Close the client's socket
    close(client_data->socket);

    // Free the client data
    free(client_data);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating server socket\n");
        return -1;
    }

    // Set the server socket to be reusable
    int reuse_addr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) < 0) {
        printf("Error setting server socket to be reusable\n");
        return -1;
    }

    // Bind the server socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket to port\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening for incoming connections\n");
        return -1;
    }

    // Initialize the server data
    struct server_data server_data;
    server_data.socket = server_socket;
    server_data.num_clients = 0;
    pthread_mutex_init(&server_data.mutex, NULL);

    // Main loop
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            printf("Error accepting incoming connection\n");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t client_thread;
        struct client_data *client_data = (struct client_data *)malloc(sizeof(struct client_data));
        client_data->socket = client_socket;
        pthread_create(&client_thread, NULL, handle_client, (void *)client_data);
    }

    // Close the server socket
    close(server_socket);

    // Destroy the mutex
    pthread_mutex_destroy(&server_data.mutex);

    return 0;
}