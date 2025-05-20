//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define MAX_CLIENTS 10

void *client_handler(void *socket_desc);
void broadcast_message(char *message, int current_client);
void print_welcome_message(int client_socket);

int clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket, new_socket, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Unable to create socket");
        exit(1);
    }
    printf("[SERVER] Socket created.\n");

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT); 

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }
    printf("[SERVER] Bind successful.\n");

    // Listen for incoming connections
    listen(server_socket, 3);
    printf("[SERVER] Listening for connections on port %d...\n", PORT);
    
    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("[SERVER] New connection accepted.\n");
        
        // Add new client to the list
        clients[client_count++] = new_socket;

        // Create a new thread for the new client
        new_sock = malloc(1);
        *new_sock = new_socket;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }
        
        pthread_detach(thread_id); // Detach to allow auto-cleanup
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(1);
    }

    close(server_socket);
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char message[BUFFER_SIZE];
    
    print_welcome_message(sock);
    
    while (1) {
        memset(message, 0, BUFFER_SIZE);
        
        // Receive message from client
        int read_size = recv(sock, message, BUFFER_SIZE - 1, 0);
        if (read_size <= 0) {
            printf("[SERVER] Client disconnected.\n");
            break;
        }

        // Broadcast message to other clients
        broadcast_message(message, sock);
    }

    close(sock);
    free(socket_desc);
    return 0;
}

void print_welcome_message(int client_socket) {
    char *welcome_msg = "[SYSTEM] Welcome to the post-apocalyptic chat server. Share your thoughts and wait for others to respond!\n";
    send(client_socket, welcome_msg, strlen(welcome_msg), 0);
}

void broadcast_message(char *message, int current_client) {
    printf("[SERVER] Broadcasting message: %s\n", message);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != current_client) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}