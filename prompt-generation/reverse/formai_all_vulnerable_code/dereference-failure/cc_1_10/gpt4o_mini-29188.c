//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket);
void error(const char *msg);

int main() {
    int server_fd, new_socket, *client_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket failed");
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("Setsockopt failed");
    }
    
    // Define the type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Bind failed");
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        error("Listen failed");
    }

    printf("Server listening on port %d\n", PORT);

    // Main loop to accept clients
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            error("Accept failed");
        }
        
        printf("New connection accepted\n");

        client_socket = malloc(sizeof(int));
        *client_socket = new_socket;

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)client_socket) != 0) {
            error("Could not create thread");
        }

        // Detach the thread so that it can clean up after itself when done
        pthread_detach(tid);
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sock, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate string
        printf("Received: %s", buffer);

        // Simple echo back to client
        if (send(sock, buffer, bytes_read, 0) != bytes_read) {
            error("Error sending data");
        }
    }

    if (bytes_read == -1) {
        error("Read failed");
    }

    printf("Client disconnected\n");
    close(sock);
    return NULL;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}