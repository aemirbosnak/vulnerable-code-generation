//FormAI DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024 // Maximum buffer size for messages
#define PORT 8888 // Default port number

int server_socket; // Server socket descriptor
struct sockaddr_in server_address; // Server address struct
pthread_t tid[10]; // Thread IDs for client handling
int client_count = 0; // Number of connected clients

/** Handle client connections **/
void *handle_client(void *arg) {
    int client_socket = *((int*) arg); // Get client socket descriptor
    char message[BUFFER_SIZE]; // Buffer to hold incoming messages
    int read_size;

    while ((read_size = recv(client_socket, message, BUFFER_SIZE, 0)) > 0) {
        message[read_size] = '\0'; // Add null terminator
        printf("Client %d sent message: %s\n", client_socket, message);

        /** Handle client commands **/
        char *input = strtok(message, " "); // Split message by spaces
        if (strcmp(input, "quit") == 0) { // Client wants to quit
            printf("Client %d disconnected\n", client_socket);
            close(client_socket);
            client_count--;
            break;
        } else { // Echo message back to client
            char response[BUFFER_SIZE];
            sprintf(response, "You said: %s", message);
            send(client_socket, response, strlen(response), 0);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("Starting chat server...\n");

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Loop to handle incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_size = sizeof(client_address);
        int client_socket;

        // Accept incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_size)) == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Start new thread to handle client
        if (pthread_create(&tid[client_count], NULL, handle_client, &client_socket) != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }

        client_count++;
        printf("Client %d connected\n", client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}