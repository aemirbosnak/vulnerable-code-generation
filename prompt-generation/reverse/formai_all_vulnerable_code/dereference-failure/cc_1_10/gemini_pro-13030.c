//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Client data structure
typedef struct client {
    int socket;
    char username[32];
    pthread_t thread;
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t lock;

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client data
    client_t *client = (client_t *)arg;

    // Receive the username
    char username[32];
    recv(client->socket, username, sizeof(username), 0);

    // Add the client to the list of clients
    pthread_mutex_lock(&lock);
    clients[num_clients++] = *client;
    pthread_mutex_unlock(&lock);

    // Send a welcome message to the client
    char welcome_message[] = "Welcome to the chat server!\n";
    send(client->socket, welcome_message, strlen(welcome_message), 0);

    // Loop to receive and send messages
    while (1) {
        // Receive a message from the client
        char buffer[BUFFER_SIZE];
        int len = recv(client->socket, buffer, sizeof(buffer), 0);

        // If the client has disconnected, break out of the loop
        if (len == 0) {
            break;
        }

        // Otherwise, broadcast the message to all other clients
        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket != client->socket) {
                send(clients[i].socket, buffer, len, 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Remove the client from the list of clients
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == client->socket) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    // Close the client's socket
    close(client->socket);

    // Free the client data
    free(client);

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server socket to be reusable
    int reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the server socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        // Accept a connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new client thread
        client_t *client = malloc(sizeof(client_t));
        client->socket = client_socket;
        pthread_create(&client->thread, NULL, handle_client, client);
    }

    // Close the server socket
    close(server_socket);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return EXIT_SUCCESS;
}