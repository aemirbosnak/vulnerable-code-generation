//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// Global array to hold client sockets and a count of clients
int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate buffer
        printf("Client said: %s", buffer);
        
        // Broadcast to all clients
        pthread_mutex_lock(&count_mutex);
        for (int i = 0; i < client_count; ++i) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&count_mutex);
    }

    // Remove client from the set of connected clients
    close(sock);
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < client_count; ++i) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[client_count - 1];
            break;
        }
    }
    client_count--;
    pthread_mutex_unlock(&count_mutex);
    printf("Client disconnected\n");
    free(client_socket);
    return 0;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread;

    // Initialize the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Set socket options error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %d\n", new_socket);

        pthread_mutex_lock(&count_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
        } else {
            printf("Maximum client limit reached. Connection refused: %d\n", new_socket);
            close(new_socket);
            pthread_mutex_unlock(&count_mutex);
            continue;
        }
        pthread_mutex_unlock(&count_mutex);

        // Create a new thread for the client
        int *new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread, NULL, handle_client, (void *)new_sock) != 0) {
            perror("Could not create thread");
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread); // Automatically reclaim thread when it exits
    }

    // Clean up (will never reach here in this example)
    close(server_fd);
    return 0;
}