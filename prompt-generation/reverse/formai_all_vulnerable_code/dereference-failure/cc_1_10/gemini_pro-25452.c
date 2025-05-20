//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

// Server configuration
struct server_config {
    int port;
    int backlog;
    char *ip_address;
};

// Client information
struct client_info {
    int socket;
    struct sockaddr_in address;
};

// Message structure
struct message {
    char *content;
    int size;
};

// Function prototypes
void *handle_client(void *arg);
struct message *create_message(char *content, int size);
void free_message(struct message *message);

// Global variables
struct server_config config;
struct client_info clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_lock;

int main(int argc, char **argv) {
    // Parse server configuration
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <port> <backlog> <ip_address>\n", argv[0]);
        return EXIT_FAILURE;
    }
    config.port = atoi(argv[1]);
    config.backlog = atoi(argv[2]);
    config.ip_address = argv[3];

    // Initialize mutex
    pthread_mutex_init(&clients_lock, NULL);

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind server socket to address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(config.port);
    server_address.sin_addr.s_addr = inet_addr(config.ip_address);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for client connections
    if (listen(server_socket, config.backlog) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept client connections in a loop
    while (1) {
        // Accept a client connection
        struct client_info client;
        socklen_t client_size = sizeof(client.address);
        client.socket = accept(server_socket, (struct sockaddr *)&client.address, &client_size);
        if (client.socket == -1) {
            perror("accept");
            continue;
        }

        // Add client to list of clients
        pthread_mutex_lock(&clients_lock);
        clients[num_clients++] = client;
        pthread_mutex_unlock(&clients_lock);

        // Create a thread to handle the client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, &client) != 0) {
            perror("pthread_create");
            close(client.socket);
            continue;
        }
    }

    // Close server socket
    close(server_socket);

    // Destroy mutex
    pthread_mutex_destroy(&clients_lock);

    return EXIT_SUCCESS;
}

void *handle_client(void *arg) {
    // Get client information
    struct client_info *client = (struct client_info *)arg;

    // Receive messages from client
    while (1) {
        // Receive message size
        int size;
        if (recv(client->socket, &size, sizeof(int), 0) == -1) {
            perror("recv");
            break;
        }

        // Receive message content
        char *content = malloc(size);
        if (recv(client->socket, content, size, 0) == -1) {
            perror("recv");
            break;
        }

        // Create message
        struct message *message = create_message(content, size);

        // Broadcast message to all clients
        pthread_mutex_lock(&clients_lock);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket != client->socket) {
                if (send(clients[i].socket, &message->size, sizeof(int), 0) == -1) {
                    perror("send");
                    continue;
                }
                if (send(clients[i].socket, message->content, message->size, 0) == -1) {
                    perror("send");
                    continue;
                }
            }
        }
        pthread_mutex_unlock(&clients_lock);

        // Free message
        free_message(message);
    }

    // Close client socket
    close(client->socket);

    // Remove client from list of clients
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket == client->socket) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_lock);

    return NULL;
}

struct message *create_message(char *content, int size) {
    // Allocate memory for message
    struct message *message = malloc(sizeof(struct message));

    // Copy content into message
    message->content = malloc(size);
    memcpy(message->content, content, size);

    // Set message size
    message->size = size;

    return message;
}

void free_message(struct message *message) {
    // Free message content
    free(message->content);

    // Free message struct
    free(message);
}