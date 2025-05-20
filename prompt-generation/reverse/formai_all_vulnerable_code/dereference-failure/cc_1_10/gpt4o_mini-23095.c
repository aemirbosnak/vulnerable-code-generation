//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} ClientInfo;

ClientInfo *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle incoming messages from clients
void *handle_client(void *arg) {
    ClientInfo *client_info = (ClientInfo *)arg;
    int n;
    char buffer[BUFFER_SIZE];
    
    while ((n = recv(client_info->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %d: %s", client_info->socket, buffer);
        // Broadcast message to all connected clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != client_info->socket) {
                send(clients[i]->socket, buffer, n, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Remove client from the list when they disconnect
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == client_info->socket) {
            free(clients[i]);
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client_info->socket);
    free(client_info);
    return NULL;
}

// Function to accept new clients
void *accept_clients(void *arg) {
    int server_socket = *(int *)arg;
    while (1) {
        ClientInfo *client_info = (ClientInfo *)malloc(sizeof(ClientInfo));
        socklen_t addr_len = sizeof(client_info->address);
        client_info->socket = accept(server_socket, (struct sockaddr *)&client_info->address, &addr_len);
        
        if (client_info->socket >= 0) {
            // Add new client to the list
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == NULL) {
                    clients[i] = client_info;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            printf("Client %d connected!\n", client_info->socket);
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, client_info);
            pthread_detach(tid);  // Detach the thread
        } else {
            perror("Accept failed");
            free(client_info);
        }
    }
    return NULL;
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    // Bind socket to the specified port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d. Waiting for clients...\n", PORT);

    pthread_t tid;
    pthread_create(&tid, NULL, accept_clients, &server_socket);

    while (1) {
        // Main thread can handle server commands if required
        sleep(1);
    }

    close(server_socket);
    return EXIT_SUCCESS;
}