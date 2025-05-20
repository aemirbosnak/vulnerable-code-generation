//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int client_socket;
    struct sockaddr_in client_addr;
} client_info_t;

client_info_t clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* arg) {
    client_info_t client_info = *((client_info_t*)arg);
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = read(client_info.client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate buffer
        
        // Broadcast to all clients
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            if (clients[i].client_socket != client_info.client_socket) {
                write(clients[i].client_socket, buffer, bytes_read);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    // Remove client from the list and close the socket
    close(client_info.client_socket);
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i].client_socket == client_info.client_socket) {
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
    
    return NULL;
}

int main() {
    int server_socket, enable = 1;
    struct sockaddr_in server_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Enable address reuse
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
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

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_info_t* new_client = malloc(sizeof(client_info_t));
        socklen_t addr_len = sizeof(new_client->client_addr);
        
        // Accept new incoming connections
        if ((new_client->client_socket = accept(server_socket, (struct sockaddr*)&new_client->client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            free(new_client);
            continue;
        }

        // Adding new client to the client array
        pthread_mutex_lock(&client_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = *new_client;
            printf("New client connected: %s:%d\n", inet_ntoa(new_client->client_addr.sin_addr), ntohs(new_client->client_addr.sin_port));
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, new_client);
            pthread_detach(thread_id); // Detach the thread
        } else {
            printf("Max clients reached. Connection refused: %s:%d\n", inet_ntoa(new_client->client_addr.sin_addr), ntohs(new_client->client_addr.sin_port));
            close(new_client->client_socket);
            free(new_client);
        }
        pthread_mutex_unlock(&client_mutex);
    }

    close(server_socket);
    return 0;
}