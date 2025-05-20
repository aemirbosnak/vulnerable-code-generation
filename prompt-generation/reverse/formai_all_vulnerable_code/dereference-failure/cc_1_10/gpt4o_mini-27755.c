//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *arg);

typedef struct {
    int socket;
    struct sockaddr address;
} client_info;

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        client_info *client = malloc(sizeof(client_info));
        client->socket = accept(server_fd, &client->address, (socklen_t*)&addrlen);
        if (client->socket < 0) {
            perror("Accept failed");
            free(client);
            continue;
        }
        
        printf("New client connected\n");

        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, client) != 0) {
            perror("Could not create thread");
            free(client);
            close(client->socket);
        }
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client->socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client: %s\n", buffer);
        send(client->socket, buffer, read_size, 0); // Echo back to client
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Recv failed");
    }

    close(client->socket);
    free(client);
    return NULL;
}