//FormAI DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

void *client_handler(void *);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port, opt = 1;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];
    pthread_t tid;

    // Creating socket file descriptor
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting server address parameters
    port = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Binding the server socket with server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and listening on port %d\n", port);

    while (1) {
        int address_length = sizeof(client_address);

        // Accepting incoming connections
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t*) &address_length);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Creating a new thread to handle each client
        if (pthread_create(&tid, NULL, client_handler, (void *) &client_socket) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }

        printf("Thread created to handle client connection\n");
    }

    return 0;
}

void *client_handler(void *socket_desc) {
    int client_socket = *(int*) socket_desc;
    char buffer[1024];
    int read_size;

    // Communicating with the connected client
    while ((read_size = recv(client_socket, buffer, 1024, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received from client: %s\n", buffer);

        // Echoing back the message to the client
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Recv failed");
    }

    close(client_socket);

    pthread_exit(NULL);
}