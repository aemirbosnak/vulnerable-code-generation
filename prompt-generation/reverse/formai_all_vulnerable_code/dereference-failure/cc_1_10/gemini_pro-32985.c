//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct client_info {
    int socket;
    struct sockaddr_in addr;
} client_info;

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;
    char buffer[1024];
    int len;

    while ((len = recv(client->socket, buffer, sizeof(buffer), 0)) > 0) {
        // Process the received message from the client
        printf("Received message from client: %s\n", buffer);

        // Send a response back to the client
        len = send(client->socket, buffer, len, 0);
        if (len < 0) {
            perror("Error sending message to client");
            break;
        }
    }

    if (len == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Error receiving message from client");
    }

    close(client->socket);
    free(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t thread_id;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return -1;
    }

    // Set the server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        return -1;
    }

    // Listen for incoming client connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for client connections");
        return -1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept the incoming client connection
        client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Create a new thread to handle the client connection
        client_info *client = malloc(sizeof(client_info));
        client->socket = client_socket;
        client->addr = client_addr;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client) != 0) {
            perror("Error creating thread to handle client connection");
            close(client_socket);
            free(client);
            continue;
        }
    }

    close(server_socket);
    return 0;
}