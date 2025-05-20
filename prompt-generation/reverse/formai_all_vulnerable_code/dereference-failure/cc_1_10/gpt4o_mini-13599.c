//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client structure
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
    int addr_len;
    char name[32];
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a client to the list
void add_client(client_t *client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = client;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to remove a client from the list
void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket_fd == socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket_fd != sender_socket) {
            send(clients[i]->socket_fd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Handler function for each client
void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 32];
    
    client_t *cli = (client_t *)arg;
    int recv_len;

    printf("Client connected: %s:%d\n", inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port));

    while ((recv_len = recv(cli->socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[recv_len] = '\0';
        snprintf(message, sizeof(message), "[%s]: %s", cli->name, buffer);
        printf("%s", message);
        broadcast_message(message, cli->socket_fd);
    }

    printf("Client disconnected: %s:%d\n", inet_ntoa(cli->address.sin_addr), ntohs(cli->address.sin_port));
    remove_client(cli->socket_fd);
    close(cli->socket_fd);
    free(cli);
    pthread_exit(NULL);
}

// Main function to initialize server and accept clients
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options error");
        return EXIT_FAILURE;
    }

    // Define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_t *cli = malloc(sizeof(client_t));
        cli->addr_len = sizeof(cli->address);
        cli->socket_fd = accept(server_fd, (struct sockaddr *)&cli->address, (socklen_t *)&cli->addr_len);
        if (cli->socket_fd < 0) {
            perror("Accept failed");
            free(cli);
            continue;
        }

        // Get client name
        printf("Enter your name: ");
        fgets(cli->name, sizeof(cli->name), stdin);
        cli->name[strcspn(cli->name, "\n")] = 0;  // Remove newline character

        add_client(cli);

        // Create a thread for the client
        if (pthread_create(&tid, NULL, handle_client, cli) != 0) {
            perror("Thread creation failed");
            free(cli);
        }
    }

    return EXIT_SUCCESS;
}