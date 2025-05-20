//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *socket_desc);
void send_message_to_all_clients(char *message, int sender_socket);
int client_sockets[MAX_CLIENTS];

int main() {
    int server_socket, new_socket, *new_sock;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(client_address);
    
    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Preparing the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Binding the server socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d...\n", PORT);
    
    int client_count = 0;

    while (1) {
        // Accepting new client connections
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length))) {
            printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));
            
            // Add new socket to client_sockets array
            client_sockets[client_count++] = new_socket;

            // Creating a new thread for each client
            pthread_t thread_id;
            new_sock = malloc(1);
            *new_sock = new_socket;
            if (pthread_create(&thread_id, NULL, client_handler, (void *)new_sock) < 0) {
                perror("Couldn't create thread");
                free(new_sock);
                close(new_socket);
                continue;
            }
        }
    }
    
    // Closing server socket
    close(server_socket);
    return 0;
}

void *client_handler(void *socket_desc) {
    int socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        send_message_to_all_clients(buffer, socket);
    }
    
    // Cleanup
    close(socket);
    free(socket_desc);
    printf("Client disconnected.\n");
    return 0;
}

void send_message_to_all_clients(char *message, int sender_socket) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}