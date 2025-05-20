//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr) {
    int client_socket = *((int *)client_socket_ptr);
    free(client_socket_ptr);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the received string
        printf("Received from client: %s\n", buffer);
        send(client_socket, buffer, bytes_read, 0); // Echo back to client
    }

    if (bytes_read == -1) {
        perror("recv");
    } else {
        printf("Client disconnected.\n");
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("accept");
            continue; // Continue to accept other clients
        }

        printf("New client connected.\n");

        // Allocate memory for the client socket in the thread
        int *new_sock = malloc(sizeof(int));
        *new_sock = client_socket;

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock); // Free allocated memory in case of error
            close(client_socket);
        }
        pthread_detach(client_thread); // Detach the thread to clean up automatically
    }

    close(server_fd);
    return 0;
}