//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client %d: %s\n", sock, buffer);
        
        // Broadcast the message to all clients
        pthread_mutex_lock(&mutex);
        for(int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    
    if (read_size == 0) {
        printf("Client %d disconnected\n", sock);
    }
    
    // Remove the socket from the list
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    
    close(sock);
    free(socket_desc);
    return 0;
}

int main() {
    int server_sock, client_sock, *new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return 1;
    }
    
    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return 1;
    }
    
    // Listen for connections
    listen(server_sock, 3);
    printf("Waiting for incoming connections...\n");
    
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            return 1;
        }
        
        // Add client to clients list
        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_sock;
            printf("Client %d connected\n", client_sock);
        
            new_sock = malloc(1);
            *new_sock = client_sock;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)new_sock);
        } else {
            printf("Max clients reached. Connection refused for socket: %d\n", client_sock);
            close(client_sock);
        }
        pthread_mutex_unlock(&mutex);
    }
    
    // Clean up and close the server socket (unreachable code)
    close(server_sock);
    return 0;
}