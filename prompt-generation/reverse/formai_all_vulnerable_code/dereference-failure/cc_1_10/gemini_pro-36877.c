//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define MAX_MESSAGE_LENGTH 1024

// List of clients connected to the server
struct client {
    int socket;
    char *name;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

// Mutex to protect the client list
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    int client_socket = *((int *) arg);
    free(arg);

    char buffer[MAX_MESSAGE_LENGTH];
    int bytes_received;

    // Receive the client's name
    bytes_received = recv(client_socket, buffer, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received < 0) {
        perror("Error receiving client name");
        close(client_socket);
        pthread_exit(NULL);
    }

    // Add the client to the list of clients
    pthread_mutex_lock(&clients_mutex);
    clients[num_clients].socket = client_socket;
    clients[num_clients].name = malloc(strlen(buffer) + 1);
    strcpy(clients[num_clients].name, buffer);
    num_clients++;
    pthread_mutex_unlock(&clients_mutex);

    // Send a welcome message to the client
    send(client_socket, "Welcome to the chat server!\n", strlen("Welcome to the chat server!\n"), 0);

    // Loop to receive and broadcast messages from the client
    while ((bytes_received = recv(client_socket, buffer, MAX_MESSAGE_LENGTH, 0)) > 0) {
        // Broadcast the message to all other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket != client_socket) {
                send(clients[i].socket, buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Client has disconnected
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == client_socket) {
            // Remove the client from the list of clients
            free(clients[i].name);
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    pthread_t thread;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket to address");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    // Loop to handle client connections
    while ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size)) >= 0) {
        // Create a thread to handle the client connection
        pthread_create(&thread, NULL, handle_client, malloc(sizeof(int)));
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}