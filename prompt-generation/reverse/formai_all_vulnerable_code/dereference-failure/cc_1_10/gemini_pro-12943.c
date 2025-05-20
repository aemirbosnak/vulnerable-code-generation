//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MSG_SIZE 1024

// Client struct
typedef struct client {
    int sockfd;
    struct sockaddr_in addr;
    char username[100];
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t lock;

// Function to handle client connections
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[MAX_MSG_SIZE];

    // Send welcome message
    snprintf(buffer, MAX_MSG_SIZE, "Welcome to the chat server, %s!\n", client->username);
    send(client->sockfd, buffer, strlen(buffer), 0);

    // Receive messages from client
    while (1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int len = recv(client->sockfd, buffer, MAX_MSG_SIZE, 0);
        if (len <= 0) {
            // Client disconnected
            pthread_mutex_lock(&lock);
            clients[num_clients - 1] = *client;
            num_clients--;
            pthread_mutex_unlock(&lock);
            break;
        }

        // Broadcast message to all other clients
        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != client->sockfd) {
                snprintf(buffer, MAX_MSG_SIZE, "%s: %s", client->username, buffer);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Close client socket
    close(client->sockfd);

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 3) {
        printf("Usage: %s <port> <username>\n", argv[0]);
        return 1;
    }

    // Initialize global variables
    memset(clients, 0, sizeof(clients));
    memset(threads, 0, sizeof(threads));
    pthread_mutex_init(&lock, NULL);

    // Create server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind server socket to port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and handle them in separate threads
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        // Get client username
        char username[100];
        memset(username, 0, sizeof(username));
        recv(client_sockfd, username, sizeof(username), 0);

        // Create client struct and add it to the list of clients
        client_t client;
        client.sockfd = client_sockfd;
        client.addr = client_addr;
        strcpy(client.username, username);
        pthread_mutex_lock(&lock);
        clients[num_clients++] = client;
        pthread_mutex_unlock(&lock);

        // Create thread to handle client
        if (pthread_create(&threads[num_clients - 1], NULL, handle_client, &client) < 0) {
            perror("pthread_create");
            continue;
        }
    }

    // Close server socket
    close(server_sockfd);

    // Wait for all threads to finish
    for (int i = 0; i < num_clients; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}