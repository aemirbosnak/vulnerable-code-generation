//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *client_handler(void *client_socket);
void error(const char *msg);

int main() {
    int server_fd, new_socket, *client_sock;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("Set socket options failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Binding failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        error("Listening failed");
    }
    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accepting new connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            error("Accepting connection failed");
        }
        printf("New connection accepted\n");

        pthread_t thread_id;
        client_sock = malloc(1);
        *client_sock = new_socket;

        // Create a thread for handling the client
        if (pthread_create(&thread_id, NULL, client_handler, (void*)client_sock) < 0) {
            error("Could not create thread");
        }
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *client_socket) {
    int sock = *(int*)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communicating with client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // null terminate string
        printf("Client: %s\n", buffer);
        // Echo back the message
        send(sock, buffer, read_size, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Receive failed");
    }

    close(sock);
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}