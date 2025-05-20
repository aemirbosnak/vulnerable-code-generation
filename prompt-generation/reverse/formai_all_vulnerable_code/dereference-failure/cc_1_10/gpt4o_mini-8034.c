//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char client_message[BUFFER_SIZE];
    int read_size;

    // Receive a message from client
    while ((read_size = recv(sock, client_message, BUFFER_SIZE, 0)) > 0) {
        // Null-terminate the received message
        client_message[read_size] = '\0';
        printf("Client: %s\n", client_message);

        // Send the message back to client
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    // Clean up the socket
    free(socket_desc);
    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket, *new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        return 1;
    }
    printf("Socket created successfully.\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    printf("Binded to port %d.\n", PORT);

    // Listen for incoming connections
    listen(server_fd, MAX_CLIENTS);
    printf("Waiting for connections...\n");

    // Accept clients
    while ((new_socket = accept(server_fd, (struct sockaddr *)&client, &client_len))) {
        printf("Connection accepted.\n");

        // Allocate memory for new socket descriptor
        new_sock = malloc(1);
        *new_sock = new_socket;

        // Create a new thread for the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }
        printf("Handler assigned.\n");
    }

    if (new_socket < 0) {
        perror("Accept failed");
        return 1;
    }

    // Clean up the server socket
    close(server_fd);
    return 0;
}