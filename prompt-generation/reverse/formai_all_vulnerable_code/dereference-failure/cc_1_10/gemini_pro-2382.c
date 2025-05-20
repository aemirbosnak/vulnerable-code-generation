//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// Global variables
int server_socket;
int client_sockets[MAX_CLIENTS];
pthread_t client_threads[MAX_CLIENTS];

// Client thread function
void* client_thread(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[1024];

    while (1) {
        // Receive message from client
        int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);

        // Check if client disconnected
        if (recv_size <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            break;
        }

        // Process client message
        char* message = buffer;
        if (strcmp(message, "hello") == 0) {
            strcpy(buffer, "Hello from server");
        } else if (strcmp(message, "goodbye") == 0) {
            strcpy(buffer, "Goodbye from server");
            close(client_socket);
            break;
        } else {
            strcpy(buffer, "Unknown command");
        }

        // Send message back to client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    free(arg);
    return NULL;
}

int main() {
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for client connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept client connections
    int client_count = 0;
    while (1) {
        // Accept client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);

        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }

        // Add client socket to array
        client_sockets[client_count] = client_socket;
        client_count++;

        // Spawn client thread
        pthread_t* client_thread_ptr = malloc(sizeof(pthread_t));
        if (pthread_create(client_thread_ptr, NULL, client_thread, (void*)&client_socket) != 0) {
            perror("Pthread creation failed");
            close(client_socket);
            continue;
        }

        // Add client thread to array
        client_threads[client_count - 1] = *client_thread_ptr;
    }

    // Join client threads
    for (int i = 0; i < client_count; i++) {
        pthread_join(client_threads[i], NULL);
    }

    // Close server socket
    close(server_socket);

    return 0;
}