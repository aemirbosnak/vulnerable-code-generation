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

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    char username[30];
} client_t;

// Global variables
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
void add_client(client_t *cl);
void remove_client(int socket);
void send_private_message(char *message, char *receiver);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Defining server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, 
                                  (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new client structure
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket = new_socket;
        new_client->address = address;
        new_client->addr_len = addrlen;
        snprintf(new_client->username, sizeof(new_client->username), "User%d", new_socket);

        // Add client to the list
        add_client(new_client);
        printf("%s joined the chat\n", new_client->username);

        // Create a thread for the new client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void*)new_client) != 0) {
            perror("Thread creation failed");
        }
    }
    return 0;
}

// Function to handle communication with clients
void *handle_client(void *arg) {
    client_t *cli = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while (1) {
        n = recv(cli->socket, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("%s has disconnected\n", cli->username);
            break;
        }

        buffer[n] = '\0';  // Null-terminate the received string
        if (buffer[0] == '@') { // Check for private message
            char *recipient = strtok(buffer + 1, " ");
            char *message = strtok(NULL, "\0"); // Get the rest of the message
            send_private_message(message, recipient);
        } else {
            broadcast_message(buffer, cli->socket);
        }
    }

    close(cli->socket);
    remove_client(cli->socket);
    free(cli);
    return NULL;
}

// Broadcast message to all clients
void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != sender_socket) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Add client to the client array
void add_client(client_t *cl) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

// Remove client from the client array
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

// Send private message to a specific user
void send_private_message(char *message, char *receiver) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && strcmp(clients[i]->username, receiver) == 0) {
            send(clients[i]->socket, message, strlen(message), 0);
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}