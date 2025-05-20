//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);
void print_usage();

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d...\n", PORT);

    // Accept clients in a loop
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) >= 0) {
        printf("Client connected: %d\n", client_socket);
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients++] = client_socket;

            // Create a new thread for the client
            if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
                perror("Thread creation failed");
                close(client_socket);
                num_clients--;
            }
            pthread_detach(thread_id);
        } else {
            printf("Max clients reached. Connection rejected for client: %d\n", client_socket);
            close(client_socket);
        }
    }

    // Close server socket
    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, sizeof(buffer))) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received message: %s", buffer);
        broadcast_message(buffer, client_socket);
    }

    printf("Client disconnected: %d\n", client_socket);
    remove_client(client_socket);
    close(client_socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void remove_client(int socket) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[num_clients - 1];
            num_clients--;
            break;
        }
    }
}

void print_usage() {
    printf("Usage:\n");
    printf("Compile: gcc chat_server.c -o chat_server -lpthread\n");
    printf("Run: ./chat_server\n");
}