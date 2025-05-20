//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Client arguments
typedef struct {
    int socket_fd;
    char name[50];
} client_t;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
void log_message(char *message);

// Array to keep track of active clients
client_t *clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for clients...\n");

    while (1) {
        // Accept new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new client instance
        client_t *new_client = (client_t *)malloc(sizeof(client_t));
        new_client->socket_fd = new_socket;
        printf("New client connected: Socket FD %d\n", new_socket);
        
        // Prompt for client's name
        send(new_socket, "Enter your name: ", 17, 0);
        recv(new_socket, new_client->name, sizeof(new_client->name), 0);
        new_client->name[strcspn(new_client->name, "\n")] = 0; // Remove newline character

        // Log connection
        printf("%s has joined the chat.\n", new_client->name);
        log_message(new_client->name);

        // Add new client to the list
        clients[client_count++] = new_client;

        // Create a new thread to handle the client
        pthread_create(&tid, NULL, handle_client, (void *)new_client);
    }

    return 0;
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client->socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null terminate the buffer
        char message[BUFFER_SIZE];
        snprintf(message, sizeof(message), "%s: %s", client->name, buffer);
        broadcast_message(message, client->socket_fd);
    }

    // Client disconnected
    printf("%s has left the chat.\n", client->name);
    log_message(client->name);
    close(client->socket_fd);
    free(client);
 
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->socket_fd != sender_socket) {
            send(clients[i]->socket_fd, message, strlen(message), 0);
        }
    }
}

void log_message(char *message) {
    FILE *log_file = fopen("chat_log.txt", "a");
    if (log_file) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] %s\n", ctime(&now), message);
        fclose(log_file);
    }
}