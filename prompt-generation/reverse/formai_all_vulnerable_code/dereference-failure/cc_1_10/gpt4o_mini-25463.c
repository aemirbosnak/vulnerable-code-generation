//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Struct to hold client info
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info_t;

// Function to handle client connections
void *handle_client(void *arg) {
    client_info_t *client_info = (client_info_t *)arg;
    int client_socket = client_info->socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Loop to receive data from client
    while ((bytes_read = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the buffer
        printf("Received: %s", buffer);
        
        // Echo the message back to the client
        write(client_socket, buffer, bytes_read);
    }

    printf("Client disconnected: %d\n", client_socket);
    close(client_socket);
    free(client_info);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port %d\n", PORT);

    // Accept and handle clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %d\n", client_socket);

        // Allocate memory for client info
        client_info_t *client_info = malloc(sizeof(client_info_t));
        client_info->socket = client_socket;
        client_info->address = client_addr;

        // Create a thread for each client
        if (pthread_create(&thread_id, NULL, handle_client, client_info) != 0) {
            perror("Thread creation failed");
            free(client_info);
            close(client_socket);
        }
        
        pthread_detach(thread_id); // Detach the thread to prevent memory leaks
    }

    // Cleanup
    close(server_socket);
    return 0;
}