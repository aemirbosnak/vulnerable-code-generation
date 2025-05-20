//GPT-4o-mini DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int client_id;
    int socket_fd;
} client_t;

client_t clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Simulate a client connection
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    
    // Welcome message
    snprintf(buffer, sizeof(buffer), "Client %d connected.\n", client->client_id);
    printf("%s", buffer);
    
    // Client interaction loop
    while (1) {
        strcpy(buffer, "Type 'exit' to disconnect.\n");
        printf("%s", buffer);
        
        // Simulate receiving a message from the client
        sleep(2);  // Simulating network delay
        snprintf(buffer, BUFFER_SIZE, "Message from client %d: Hello!\n", client->client_id);
        printf("%s", buffer);
        
        if (client->client_id % 2 == 0) {
            snprintf(buffer, BUFFER_SIZE, "Client %d says: Goodbye!\n", client->client_id);
            printf("%s", buffer);
            break;  // Exit the loop for even client ids
        }
    }
    
    // Cleanup and exit
    printf("Client %d disconnected.\n", client->client_id);
    pthread_mutex_lock(&clients_mutex);
    client_count--;
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

// Main server function
int main() {
    pthread_t threads[MAX_CLIENTS];
    
    // Simulate accepting clients
    while (client_count < MAX_CLIENTS) {
        pthread_mutex_lock(&clients_mutex);
        
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->client_id = client_count + 1;
        new_client->socket_fd = client_count;  // Mock socket fd
        
        if (pthread_create(&threads[client_count], NULL, handle_client, (void *)new_client) != 0) {
            perror("Failed to create thread");
            free(new_client);
            pthread_mutex_unlock(&clients_mutex);
            break;
        }
        
        client_count++;
        pthread_mutex_unlock(&clients_mutex);
        
        // Sleep a bit to simulate time between connections
        sleep(1);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < client_count; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All clients have been disconnected. Server shutting down...\n");
    return 0;
}