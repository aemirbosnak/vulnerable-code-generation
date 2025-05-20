//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} ClientInfo;

ClientInfo clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    ClientInfo *client_info = (ClientInfo *)arg;
    int sockfd = client_info->socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        
        printf("Client says: %s", buffer); // Display received message

        // Broadcast to other clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < client_count; ++i) {
            if (clients[i].socket != sockfd) {
                send(clients[i].socket, buffer, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Clean up
    close(sockfd);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; ++i) {
        if (clients[i].socket == sockfd) {
            clients[i] = clients[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(client_info);
    return NULL;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Create server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    // Begin listening for clients
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accepting failed");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            ClientInfo *client_info = malloc(sizeof(ClientInfo));
            client_info->socket = new_sock;
            client_info->address = client_addr;
            clients[client_count++] = *client_info;

            pthread_t tid;
            if (pthread_create(&tid, NULL, handle_client, client_info) != 0) {
                perror("Thread creation failed");
                free(client_info);
            }
        } else {
            printf("Maximum clients reached. Rejecting new connection.\n");
            close(new_sock);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Cleanup
    close(server_sock);
    return EXIT_SUCCESS;
}