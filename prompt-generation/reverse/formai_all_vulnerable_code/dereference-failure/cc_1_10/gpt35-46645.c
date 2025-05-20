//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    int read_size;
    char buffer[BUFFER_SIZE];

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message from client %d: %s\n", client_socket, buffer);
        
        // Echo message back to client
        send(client_socket, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
    }

    // Client disconnected
    printf("Client %d disconnected\n", client_socket);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = -1;
            break;
        }
    }

    num_clients--;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port>\n");
        return 1;
    }

    int port = atoi(argv[1]);
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[BUFFER_SIZE];

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating server socket\n");
        return 1;
    }

    // Bind socket to address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket to address\n");
        return 1;
    }

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);
    printf("Server started on port %d\n", port);

    while (1) {
        // Look for incoming connections
        socklen_t client_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_size);

        if (client_socket == -1) {
            printf("Error accepting incoming connection\n");
            continue;
        }

        // Add client socket to array
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients++] = client_socket;
        } else {
            printf("Max clients reached, closing incoming connection\n");
            close(client_socket);
            continue;
        }

        // Send welcome message to client
        sprintf(message, "Welcome, you are client %d\n", client_socket);
        send(client_socket, message, strlen(message), 0);

        // Handle client in separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}