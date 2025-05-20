//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Struct to hold information about each client
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a client to the clients list
void add_client(client_t *cl) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!clients[i]) {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to remove a client from the clients list
void remove_client(int sockfd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i]) {
            if (clients[i]->socket_fd == sockfd) {
                clients[i] = NULL;
                break;
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to broadcast messages to all connected clients
void broadcast_message(char *message, int sender_fd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i]) {
            if (clients[i]->socket_fd != sender_fd) {
                send(clients[i]->socket_fd, message, strlen(message), 0);
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle communication with a connected client
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(cli->socket_fd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %d: %s\n", cli->socket_fd, buffer);
        broadcast_message(buffer, cli->socket_fd);
    }
    
    // Handle client disconnection
    printf("Client %d disconnected\n", cli->socket_fd);
    remove_client(cli->socket_fd);
    close(cli->socket_fd);
    free(cli);
    return NULL;
}

// Main server function
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options for the socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Configure the socket address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        client_t *new_client = malloc(sizeof(client_t));
        new_socket = accept(server_fd, (struct sockaddr *)&new_client->address, (socklen_t *)&addrlen);

        if (new_socket < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        new_client->socket_fd = new_socket;
        add_client(new_client);

        // Create a thread to handle the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)new_client) != 0) {
            perror("Thread creation failed");
            free(new_client);
        }
        pthread_detach(tid);
    }

    return 0;
}