//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

void *handle_client(void *client_socket);
void broadcast_message(const char *message, int sender_socket);

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_lock;

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Initialize clients array and mutex
    memset(clients, 0, sizeof(clients));
    pthread_mutex_init(&client_lock, NULL);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address structure
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
    
    printf("🎉 Chat Server Started on PORT %d 🎉\n", PORT);
    
    // Accept clients
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) >= 0) {
        pthread_t tid;
        
        // Add new client to the clients array
        pthread_mutex_lock(&client_lock);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_socket;
            printf("✨ New Client Connected! (Client %d) ✨\n", client_count);
            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
        } else {
            printf("🚫 Rejected Client Connection: Server Full 🚫\n");
            close(new_socket);
        }
        pthread_mutex_unlock(&client_lock);
    }
    
    // Cleanup
    close(server_socket);
    pthread_mutex_destroy(&client_lock);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("📬 Message Received: %s\n", buffer);
        broadcast_message(buffer, sock);
    }
    
    // Client disconnected
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == sock) {
            clients[i] = clients[--client_count]; // Remove client
            printf("❌ Client Disconnected! (Remaining Clients: %d) ❌\n", client_count);
            break;
        }
    }
    close(sock);
    pthread_mutex_unlock(&client_lock);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < client_count; i++) {
        // Send message to all clients except the sender
        if (clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_lock);
}