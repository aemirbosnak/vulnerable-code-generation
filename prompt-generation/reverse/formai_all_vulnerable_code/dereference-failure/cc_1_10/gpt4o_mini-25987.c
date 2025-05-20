//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void* handle_client(void* arg);

// Global variable to keep track of client sockets
int client_sockets[MAX_CLIENTS];
int client_count = 0;

// Function to handle incoming client connections
void accept_client(int server_fd) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int new_socket;

    // Accept incoming connection
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (new_socket < 0) {
        perror("Accept failed");
        return;
    }

    printf("New client connected: %d\n", new_socket);
    
    // Store the socket in the global array
    if (client_count < MAX_CLIENTS) {
        client_sockets[client_count++] = new_socket;
        
        // Create a new thread to handle this client
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &new_socket);

        // Recursive call to accept more clients
        accept_client(server_fd);
    } else {
        printf("Max clients reached. Connection refused for socket: %d\n", new_socket);
        close(new_socket);
    }
}

// Function to handle client communication
void* handle_client(void* arg) {
    int socket_fd = *((int*)arg);
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(socket_fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            printf("Client disconnected: %d\n", socket_fd);
            close(socket_fd);
            return NULL;
        }

        printf("Received from %d: %s", socket_fd, buffer);

        // Send message to all connected clients
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != socket_fd) { // Do not send the message back to the sender
                write(client_sockets[i], buffer, bytes_read);
            }
        }
    }
}

// Main function to set up the server
int main() {
    int server_fd, opt = 1;
    struct sockaddr_in server_addr;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Start accepting clients recursively
    accept_client(server_fd);

    // Clean up (never reached in this example)
    close(server_fd);
    return 0;
}