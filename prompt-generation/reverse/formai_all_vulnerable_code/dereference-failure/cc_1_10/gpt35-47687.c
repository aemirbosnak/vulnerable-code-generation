//FormAI DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_BUFFER_SIZE 1024

void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_descriptor, client_socket, client_length, *new_socket;
    struct sockaddr_in server_address, client_address;

    // Create socket
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1) {
        perror("Error creating socket.");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to port
    if (bind(socket_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(socket_descriptor, 3) == -1) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    puts("Waiting for incoming connections...");

    // Accept incoming connections
    client_length = sizeof(client_address);
    while ((client_socket = accept(socket_descriptor, (struct sockaddr *) &client_address, (socklen_t *) &client_length)) != -1) {
        puts("Connection accepted");

        new_socket = malloc(1);
        *new_socket = client_socket;

        pthread_t thread;
        if (pthread_create(&thread, NULL, connection_handler, (void *) new_socket) < 0) {
            perror("Could not create thread.");
            exit(EXIT_FAILURE);
        }
    }

    if (client_socket == -1) {
        perror("Accept failed.");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

void *connection_handler(void *socket_descriptor_pointer) {
    int socket_descriptor = *(int *) socket_descriptor_pointer;
    free(socket_descriptor_pointer);

    char request_buffer[MAX_BUFFER_SIZE] = {0};
    char response_buffer[MAX_BUFFER_SIZE] = {0};

    // Get HTTP request
    if (read(socket_descriptor, request_buffer, MAX_BUFFER_SIZE) == -1) {
        perror("Error reading from socket.");
        exit(EXIT_FAILURE);
    }

    // Create HTTP response
    sprintf(response_buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>");

    // Send HTTP response
    if (send(socket_descriptor, response_buffer, strlen(response_buffer), 0) == -1) {
        perror("Error sending response.");
        exit(EXIT_FAILURE);
    }

    // Close socket and exit thread
    close(socket_descriptor);
    puts("Connection closed");
    pthread_exit(NULL);
}