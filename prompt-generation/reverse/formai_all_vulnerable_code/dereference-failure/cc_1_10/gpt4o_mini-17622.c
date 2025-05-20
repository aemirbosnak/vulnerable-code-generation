//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to pass client socket to thread
struct client_info {
    int socket_fd;
    int client_number;
};

// Array to hold client sockets
int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const char* message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void* handle_client(void* arg) {
    struct client_info* client = (struct client_info*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client->socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the string
        printf("Client %d: %s\n", client->client_number, buffer);
        broadcast_message(buffer, client->socket_fd);
    }

    // Handle client disconnection
    close(client->socket_fd);
    pthread_mutex_lock(&clients_mutex);
    client_sockets[client->client_number] = 0;
    pthread_mutex_unlock(&clients_mutex);
    free(client);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Setup address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        int client_number = -1;
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                client_number = i;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (client_number == -1) {
            printf("Max clients reached. Connection rejected.\n");
            close(new_socket);
            continue;
        }

        // Create a new thread for the client
        struct client_info* client = malloc(sizeof(struct client_info));
        client->socket_fd = new_socket;
        client->client_number = client_number;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client) != 0) {
            perror("Thread creation failed");
            close(new_socket);
            free(client);
        }
    }

    close(server_fd);
    return 0;
}