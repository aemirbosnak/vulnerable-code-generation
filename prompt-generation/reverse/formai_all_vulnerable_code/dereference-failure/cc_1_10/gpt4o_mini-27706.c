//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024
#define BACKLOG 10

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUF_SIZE];
    int bytes_read;

    // Freeing the allocated memory for the socket descriptor
    free(arg);

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Received: %s", buffer);
        send(client_socket, buffer, bytes_read, 0); // Echoing back to client
    }
    
    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv");
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, *new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid;

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    server_addr.sin_port = htons(PORT); // Port number

    // Binding socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        new_client_socket = malloc(sizeof(int));
        if ((*new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            free(new_client_socket);
            continue;
        }

        printf("New client connected: %s:%d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread for each client
        if (pthread_create(&tid, NULL, handle_client, new_client_socket) != 0) {
            perror("Thread creation failed");
            close(*new_client_socket);
            free(new_client_socket);
        }
        pthread_detach(tid); // Automatically reclaim resources once the thread terminates
    }

    // Close server socket (won't be executed in infinite loop)
    close(server_socket);
    return 0;
}