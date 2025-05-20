//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: sophisticated
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
    int address_len;
} ClientInfo;

ClientInfo *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send a message to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle each client connection
void *handle_client(void *arg) {
    ClientInfo *client = (ClientInfo *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate received string
        printf("[Client %d] %s", client->socket, buffer);
        broadcast_message(buffer, client->socket);
    }

    close(client->socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket == client->socket) {
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        if ((new_client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len)) < 0) {
            perror("Accept failed");
            continue; // Move to next iteration on error
        }

        // Allocate and store client information
        ClientInfo *client_info = malloc(sizeof(ClientInfo));
        client_info->socket = new_client_socket;
        client_info->address = client_address;
        client_info->address_len = addr_len;

        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = client_info;
            printf("New connection: socket %d, IP: %s, PORT: %d\n", 
                   new_client_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        } else {
            printf("Maximum clients connected. Connection rejected for socket %d\n", new_client_socket);
            close(new_client_socket);
            free(client_info);
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread to handle the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)client_info) != 0) {
            perror("Thread creation failed");
            close(new_client_socket);
            free(client_info);
        }
    }

    close(server_socket);
    return 0;
}