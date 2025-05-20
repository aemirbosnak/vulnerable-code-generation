//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// A structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function prototypes
void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);
void init_server();

int main() {
    init_server();
    return 0;
}

void init_server() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Chat server started on port %d\n", PORT);

    // Accept clients
    while (1) {
        socklen_t addrlen = sizeof(client_address);
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new client object
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = client_address;

        // Add client to the clients' list
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == NULL) {
                clients[i] = new_client;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread to handle the client
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)new_client);
    }

    close(server_socket);
}

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *client = (client_t *)arg;

    // Client greeting message
    snprintf(buffer, sizeof(buffer), "Welcome to the chat! Your socket ID: %d\n", client->socket);
    send(client->socket, buffer, strlen(buffer), 0);

    // Loop to receive messages from the client
    while (1) {
        int bytes_received = recv(client->socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the message
        printf("Client [%d]: %s", client->socket, buffer);
        broadcast_message(buffer, client->socket);
    }

    // Cleanup when client disconnects
    close(client->socket);
    remove_client(client->socket);
    free(client);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket == socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}