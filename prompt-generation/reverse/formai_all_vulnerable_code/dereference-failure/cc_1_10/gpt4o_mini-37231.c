//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void* handle_client(void* client_socket);

int main() {
    int server_socket, new_socket, *client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    printf("✅ Socket created successfully.\n");
    
    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("🔗 Bind successful on port %d.\n", PORT);
    
    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("👂 Listening for connections...\n");

    while (1) {
        // Accept incoming connections
        new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed!");
            continue; // Move on to the next iteration
        }
        
        printf("🎉 New connection accepted!\n");
        
        // Create a thread for the new client
        client_socket = malloc(1);
        *client_socket = new_socket;
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)client_socket) < 0) {
            perror("Could not create thread!");
            free(client_socket);
        }
        pthread_detach(thread_id); // Don't need to join
    }

    // Close the socket in case of server shutdown – unreachable in practice
    close(server_socket);
    return 0;
}

// Function to handle client communication
void* handle_client(void* client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Welcome message
    char* welcome_msg = "👋 Welcome to the Chat Server!\nType a message and hit enter:\n";
    send(sock, welcome_msg, strlen(welcome_msg), 0);

    // Chat loop
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string
        printf("🗨️ Message received: %s", buffer);
        
        // Echo the message back to client
        send(sock, buffer, read_size, 0);
    }

    // Client disconnected
    if (read_size == 0) {
        printf("🚪 Client disconnected.\n");
    } else {
        perror("recv failed!");
    }

    free(client_socket); // Free dynamically allocated memory
    close(sock); // Close the socket
    return NULL;
}