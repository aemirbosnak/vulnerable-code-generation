//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080               // Port where the server listens for incoming connections
#define MAX_CLIENTS 10          // Maximum number of clients that can connect
#define BUFFER_SIZE 1024         // Size of the buffer for messages

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast a message to all connected clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle incoming messages from clients
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int read_size;

    printf("Client connected: %s:%d\n", 
           inet_ntoa(cli->address.sin_addr), 
           ntohs(cli->address.sin_port));

    while ((read_size = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string

        printf("Received message from %s:%d - %s", 
               inet_ntoa(cli->address.sin_addr), 
               ntohs(cli->address.sin_port), 
               buffer);
        
        broadcast_message(buffer, cli->socket); // Broadcast the message to other clients
    }

    // Client disconnected
    close(cli->socket);
    printf("Client disconnected: %s:%d\n", 
           inet_ntoa(cli->address.sin_addr), 
           ntohs(cli->address.sin_port));

    free(cli);
    return NULL;
}

// Function to manage incoming clients
void *accept_clients(void *arg) {
    int server_socket = *(int *)arg;
    while (1) {
        client_t *cli = (client_t *)malloc(sizeof(client_t));
        cli->addr_len = sizeof(cli->address);
        cli->socket = accept(server_socket, (struct sockaddr *)&cli->address, 
                             (socklen_t *)&cli->addr_len);
        
        if (cli->socket < 0) {
            perror("Failed to accept client");
            free(cli);
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (!clients[i]) { // Find an empty slot for the new client
                clients[i] = cli;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, cli);
        pthread_detach(tid); // Auto clean up thread when done
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all IP addresses
    server_addr.sin_port = htons(PORT); // Port number

    // Bind the socket to the address specified
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen on socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Accept clients in a separate thread
    accept_clients((void *)&server_socket);

    close(server_socket);

    return 0;
}