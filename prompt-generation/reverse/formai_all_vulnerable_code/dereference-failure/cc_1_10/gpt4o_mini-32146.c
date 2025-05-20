//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: configurable
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
} client_t;

// Function to handle each client
void *handle_client(void *arg) {
    client_t *client_info = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int recv_size;

    printf("Client connected: %s:%d\n", inet_ntoa(client_info->address.sin_addr), ntohs(client_info->address.sin_port));

    while ((recv_size = recv(client_info->socket, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[recv_size] = '\0';
        printf("Client %s:%d says: %s\n", inet_ntoa(client_info->address.sin_addr), ntohs(client_info->address.sin_port), buffer);
        // Echo the message back to the client
        send(client_info->socket, buffer, recv_size, 0);
    }

    close(client_info->socket);
    free(client_info);
    printf("Client disconnected: %s:%d\n", inet_ntoa(client_info->address.sin_addr), ntohs(client_info->address.sin_port));
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Handle the next client
        }

        client_t *client_info = malloc(sizeof(client_t));
        client_info->socket = client_socket;
        client_info->address = client_addr;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)client_info) != 0) {
            perror("Thread creation failed");
            free(client_info);
        }

        pthread_detach(tid); // Detach to avoid memory leaks
    }

    close(server_socket);
    return 0;
}