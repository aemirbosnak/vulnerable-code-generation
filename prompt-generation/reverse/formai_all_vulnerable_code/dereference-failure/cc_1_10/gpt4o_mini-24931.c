//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} client_t;

client_t *clients[MAX_CLIENTS];

void *handle_client(void *arg);
void broadcast_message(const char *message, int exclude_sock);
void add_client(client_t *cl);
void remove_client(int sock);

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        client_t *cl = malloc(sizeof(client_t));
        cl->socket = new_client_socket;
        cl->address = client_addr;
        cl->addr_len = addr_len;

        add_client(cl);
        pthread_create(&tid, NULL, handle_client, (void *)cl);
    }

    close(server_socket);
    return 0;
}

void add_client(client_t *cl) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == NULL) {
            clients[i] = cl;
            printf("Client connected: %d\n", cl->socket);
            return;
        }
    }
    free(cl); // No space available, free the client
    printf("Max clients connected. Connection rejected: %d\n", cl->socket);
}

void remove_client(int sock) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket == sock) {
            printf("Client disconnected: %d\n", sock);
            free(clients[i]);
            clients[i] = NULL;
            return;
        }
    }
}

void broadcast_message(const char *message, int exclude_sock) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] != NULL && clients[i]->socket != exclude_sock) {
            send(clients[i]->socket, message, strlen(message), 0);
        }
    }
}

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    client_t *cl = (client_t *)arg;
    int recv_size;

    while ((recv_size = recv(cl->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[recv_size] = '\0'; // Null-terminate the message
        printf("Message from %d: %s", cl->socket, buffer);
        broadcast_message(buffer, cl->socket); // Broadcast to all clients except sender
    }

    remove_client(cl->socket);
    close(cl->socket);
    free(cl);
    return NULL;
}