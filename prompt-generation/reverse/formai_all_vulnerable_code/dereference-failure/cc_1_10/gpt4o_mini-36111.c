//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int sockfd;
    struct sockaddr_in address;
    int addr_len;
    char username[50];
} client_t;

client_t *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to send a message to all clients
void broadcast_message(char *message, int sender_sockfd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->sockfd != sender_sockfd) {
            send(clients[i]->sockfd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to handle client communication
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 50];

    // Receive username
    recv(cli->sockfd, cli->username, sizeof(cli->username), 0);
    sprintf(message, "%s has joined the chat\n", cli->username);
    broadcast_message(message, cli->sockfd);

    // Listen for messages
    while (1) {
        int bytes_received = recv(cli->sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // Client has disconnected
        }
        buffer[bytes_received] = '\0';
        sprintf(message, "%s: %s", cli->username, buffer);
        broadcast_message(message, cli->sockfd);
    }

    // Clean up when a client disconnects
    close(cli->sockfd);
    sprintf(message, "%s has left the chat\n", cli->username);
    broadcast_message(message, cli->sockfd);
    
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->sockfd == cli->sockfd) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    free(cli);
    return NULL;
}

int main() {
    int server_sockfd, new_sockfd;
    struct sockaddr_in server_address, client_address;

    // Create socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 3) < 0) {
        perror("Listen failed");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        cli->addr_len = sizeof(cli->address);
        cli->sockfd = accept(server_sockfd, (struct sockaddr *)&cli->address, (socklen_t *)&cli->addr_len);
        if (cli->sockfd < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = cli;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t tid;
        if (pthread_create(&tid, NULL, &handle_client, (void *)cli) != 0) {
            perror("Thread creation failed");
            continue;
        }
    }

    // Close server socket
    close(server_sockfd);
    return 0;
}