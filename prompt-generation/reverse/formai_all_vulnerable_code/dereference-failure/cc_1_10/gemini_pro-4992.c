//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Structure to hold client data
typedef struct Client {
    int socket_fd;
    char name[256];
} Client;

// Array to hold all connected clients
Client clients[100];
int num_clients = 0;

// Mutex to protect the clients array
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client requests
void* handle_client(void* arg) {
    Client* client = (Client*)arg;

    // Buffer to hold client messages
    char buffer[256];
    while (1) {
        // Receive message from client
        int bytes_received = recv(client->socket_fd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            // Client disconnected
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].socket_fd == client->socket_fd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        }

        // Process client message
        buffer[bytes_received] = '\0';
        printf("Client %s: %s\n", client->name, buffer);

        // Send message to all other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket_fd != client->socket_fd) {
                send(clients[i].socket_fd, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Close client socket
    close(client->socket_fd);
    free(client);

    return NULL;
}

int main() {
    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Set server socket to be reusable
    int reuseaddr_opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_opt, sizeof(reuseaddr_opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Bind server socket to port 8080
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(1);
    }

    // Main server loop
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Read client name
        char name[256];
        int bytes_received = recv(client_socket, name, sizeof(name), 0);
        if (bytes_received <= 0) {
            // Client disconnected
            close(client_socket);
            continue;
        }

        // Add client to list of clients
        pthread_mutex_lock(&clients_mutex);
        Client* client = (Client*)malloc(sizeof(Client));
        client->socket_fd = client_socket;
        strcpy(client->name, name);
        clients[num_clients++] = *client;
        pthread_mutex_unlock(&clients_mutex);

        // Create thread to handle client requests
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void*)client);
        pthread_detach(thread);
    }

    // Close server socket
    close(server_socket);

    return 0;
}