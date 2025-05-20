//FormAI DATASET v1.0 Category: Networking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

void *client_handler(void *);

int main() {
    int server_fd, client_socket, *new_socket;
    struct sockaddr_in server_address, client_address;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding address to socket
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and running on port %d\n", PORT);

    int addrlen = sizeof(server_address);

    while (1) {
        // Accepting new client connections
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        puts("Connection accepted");

        // Creating new thread for client connection
        pthread_t thread_id;
        new_socket = malloc(1);
        *new_socket = client_socket;

        if (pthread_create(&thread_id, NULL, client_handler, (void *)new_socket) < 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        pthread_detach(thread_id);
    }

    return 0;
}

void *client_handler(void *socket) {
    int client_socket = *(int *)socket;
    char buffer[1024] = {0};
    char *hello = "Hello from the server";

    while(1) {
        // Receiving message from client
        if (read(client_socket, buffer, 1024) == 0) {
            puts("Client disconnected");
            break;
        }

        printf("Client message: %s\n", buffer);

        // Sending message to client
        send(client_socket, hello, strlen(hello), 0);

        memset(buffer, 0, 1024);
    }

    free(socket);

    close(client_socket);
    pthread_exit(NULL);
}