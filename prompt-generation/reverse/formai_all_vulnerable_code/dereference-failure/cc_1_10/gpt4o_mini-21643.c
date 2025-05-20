//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define CLIENT_QUEUE_SIZE 5

void *handle_client(void *sock) {
    int client_sock = *(int *)sock;
    free(sock);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Handle client communication
    while ((bytes_read = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        // Null terminate the received data
        buffer[bytes_read] = '\0';
        printf("Client says: %s\n", buffer);
        
        // Echo the same message back to client
        send(client_sock, buffer, bytes_read, 0);
    }

    // Close the client socket
    close(client_sock);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_sock, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_sock, CLIENT_QUEUE_SIZE) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections
    while (1) {
        int *client_sock = malloc(sizeof(int));
        if ((*client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            free(client_sock);
            continue;
        }

        printf("Connection accepted from %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread to handle the client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)client_sock) != 0) {
            perror("Thread creation failed");
            free(client_sock);
            close(*client_sock);
        }
        
        // Detach the thread as we do not need to join it later
        pthread_detach(client_thread);
    }

    // Clean up and close server socket (this part will never be reached in this example)
    close(server_sock);
    return 0;
}