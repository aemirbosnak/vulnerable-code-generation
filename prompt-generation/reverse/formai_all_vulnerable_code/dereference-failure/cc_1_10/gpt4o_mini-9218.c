//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

// A structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    char name[32];
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle communication with a client
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cli = (client_t *)arg;
    int n;
    
    // Welcome message
    sprintf(buffer, "Welcome to the visionary chat server, %s!\n", cli->name);
    send(cli->socket, buffer, strlen(buffer), 0);

    while ((n = recv(cli->socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0'; // Ensure null termination

        // Broadcast message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] && clients[i]->socket != cli->socket) {
                char msg[BUFFER_SIZE];
                sprintf(msg, "%s: %s", cli->name, buffer);
                send(clients[i]->socket, msg, strlen(msg), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Remove client from the list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == cli) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    
    close(cli->socket);
    free(cli);
    return NULL;
}

// Main chat server function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    
    // Create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Visionary Chat Server is running on port %d...\n", PORT);

    // Accept incoming connections
    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue;
        }

        // Allocate memory for new client
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->socket = client_socket;
        client->address = client_addr;
        client->addr_len = addr_len;

        // Get client's name
        recv(client_socket, client->name, sizeof(client->name), 0);

        // Add client to the clients list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread for handling this client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, client) != 0) {
            perror("Thread creation failed");
            free(client);
        }
    }

    // Close server socket
    close(server_socket);
    return 0;
}