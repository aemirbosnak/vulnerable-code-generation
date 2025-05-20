//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Defines
#define PORT 2525
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

// Data structures
typedef struct client {
    int sockfd;
    char username[MAX_BUFFER_SIZE];
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;

// Function declarations
void *handle_client(void *arg);
void broadcast_message(char *message);

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_sockfd;
        if (pthread_create(&thread, NULL, handle_client, (void *)arg) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            continue;
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client socket file descriptor
    int client_sockfd = *(int *)arg;
    free(arg);

    // Get the client username
    char username[MAX_BUFFER_SIZE];
    if (recv(client_sockfd, username, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        close(client_sockfd);
        return NULL;
    }

    // Add the client to the list of clients
    clients[num_clients].sockfd = client_sockfd;
    strcpy(clients[num_clients].username, username);
    num_clients++;

    // Broadcast a message to all clients
    char message[MAX_BUFFER_SIZE];
    sprintf(message, "%s has joined the chat", username);
    broadcast_message(message);

    // Handle client messages
    while (1) {
        // Receive a message from the client
        char message[MAX_BUFFER_SIZE];
        if (recv(client_sockfd, message, MAX_BUFFER_SIZE, 0) == -1) {
            perror("recv");
            close(client_sockfd);
            return NULL;
        }

        // Broadcast the message to all clients
        broadcast_message(message);
    }

    // Close the client socket file descriptor
    close(client_sockfd);

    return NULL;
}

// Function to broadcast a message to all clients
void broadcast_message(char *message) {
    for (int i = 0; i < num_clients; i++) {
        if (send(clients[i].sockfd, message, strlen(message), 0) == -1) {
            perror("send");
            close(clients[i].sockfd);
        }
    }
}