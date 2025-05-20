//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 5

void *handle_client(void *client_socket);
void exit_with_error(const char *msg);

int main() {
    int server_fd, new_socket, *client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        exit_with_error("Socket failed");

    server_addr.sin_family = AF_INET;          // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any address
    server_addr.sin_port = htons(PORT);        // Port

    // Bind socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        exit_with_error("Bind failed");

    // Start listening for incoming connections
    if (listen(server_fd, BACKLOG) < 0)
        exit_with_error("Listen failed");

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0)
            exit_with_error("Accept failed");

        printf("New connection established.\n");
        
        // Allocate memory for client socket descriptor
        client_socket = malloc(1);
        *client_socket = new_socket;

        // Create a new thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client_socket) != 0)
            exit_with_error("Failed to create thread");

        pthread_detach(thread_id); // Detach thread to free resources
    }

    close(server_fd);
    return 0;
}

// Function to handle client interaction
void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication loop
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate received data
        printf("Client: %s\n", buffer);

        // Echo back the received message
        send(sock, buffer, read_size, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size == -1) {
        perror("Receive failed");
    }

    close(sock);
    return NULL;
}

// Function to exit with error message
void exit_with_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}