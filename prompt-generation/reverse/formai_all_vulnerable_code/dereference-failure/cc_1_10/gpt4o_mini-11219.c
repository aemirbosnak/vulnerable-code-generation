//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Array to hold client sockets
int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle each client
void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        
        if (bytes_read <= 0) {
            printf("Client disconnected!\n");
            break; // Exit the loop if client disconnects
        }
        
        // Display client message
        printf("Client says: %s", buffer);
        
        // Broadcast message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0) {
                if (client_sockets[i] != client_socket) {
                    send(client_sockets[i], buffer, strlen(buffer), 0);
                }
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Clean up on disconnect
    close(client_socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

int main() {
    printf("🌟 Welcome to the Cheerful Chat Server! 🌟\n");

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Setup server address
    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Start listening
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return 1;
    }

    printf("😊 Server is running on port %d! Ready to accept connections. 😊\n", PORT);

    // Accept clients
    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Move on to accept the next client
        }

        // Notify that a new client has connected
        printf("🎉 New client connected! 🎉\n");
        
        // Store the client socket
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Could not create thread");
        }
    }

    // Close the server socket when done
    close(server_socket);
    return 0;
}