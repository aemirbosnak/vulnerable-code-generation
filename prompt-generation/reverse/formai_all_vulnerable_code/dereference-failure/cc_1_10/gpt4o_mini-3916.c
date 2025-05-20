//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);

int main() {
    int server_fd, new_socket, *client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);
    
    while (1) {
        // Accept new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                printf("Client connected: %d\n", new_socket);
                
                client_socket = malloc(1);
                *client_socket = new_socket;
                pthread_t tid;
                pthread_create(&tid, NULL, handle_client, (void *)client_socket);
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    return 0;
}

void *handle_client(void *arg) {
    int sock = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Client %d: %s\n", sock, buffer);
        
        // Broadcast to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] > 0 && client_sockets[i] != sock) {
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    // Remove the client from the list
    close(sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = 0;
            printf("Client disconnected: %d\n", sock);
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(arg);
    return NULL;
}