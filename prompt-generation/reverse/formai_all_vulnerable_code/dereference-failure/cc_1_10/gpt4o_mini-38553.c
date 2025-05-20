//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFF_SIZE 1024

// A structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

// Global variable to keep track of clients
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function declarations
void *handle_client(void *arg);
void send_message_to_all_clients(const char *message, int sender_socket);
void add_client(client_t *client);
void remove_client(int client_socket);
void log_message(const char *msg);

int main() {
    // Enable paranoia: Check for errors everywhere! 
    int server_socket, opt = 1;
    struct sockaddr_in server_address;

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        log_message("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    // Binding the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        log_message("Failed to set socket options!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        log_message("Binding failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        log_message("Listening failed!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    log_message("Server listening...");

    while (1) {
        int addr_len = sizeof(server_address);
        client_t *new_client = malloc(sizeof(client_t));

        // Accepting client connection
        if ((new_client->socket = accept(server_socket, (struct sockaddr *)&new_client->address, (socklen_t*)&addr_len)) < 0) {
            log_message("Accepting connection failed!");
            free(new_client);
            continue;
        }

        log_message("Client connected");
        add_client(new_client);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_client) != 0) {
            log_message("Failed to create a thread!");
            close(new_client->socket);
            free(new_client);
        }
        pthread_detach(thread_id);
    }

    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFF_SIZE];
    int bytes_read;
    
    while ((bytes_read = read(client->socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        if (strcmp(buffer, "/quit\n") == 0) {
            log_message("Client requested to quit.");
            break;
        }
        log_message("Received message");
        send_message_to_all_clients(buffer, client->socket);
    }

    // Cleanup
    log_message("Client disconnected");
    remove_client(client->socket);
    close(client->socket);
    free(client);
    return NULL;
}

void send_message_to_all_clients(const char *message, int sender_socket) {
    int i;
    pthread_mutex_lock(&clients_mutex);
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket != sender_socket) {
            write(clients[i]->socket, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void add_client(client_t *client) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (!clients[i]) {
            clients[i] = client;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int client_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] && clients[i]->socket == client_socket) {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void log_message(const char *msg) {
    fprintf(stderr, "[INFO] %s\n", msg);
}