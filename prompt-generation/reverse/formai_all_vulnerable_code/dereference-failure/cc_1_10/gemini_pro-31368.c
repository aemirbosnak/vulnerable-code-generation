//GEMINI-pro DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of clients that can be connected
#define MAX_CLIENTS 10

// Define the maximum size of a message
#define MAX_MESSAGE_SIZE 1024

// Define the port number that the server will listen on
#define PORT_NUMBER 5000

// Define the thread function that will handle each client
void *handle_client(void *arg) {
    // Get the socket descriptor for the client
    int socket_descriptor = *(int *)arg;

    // Send a welcome message to the client
    char welcome_message[] = "Welcome to the server!\n";
    send(socket_descriptor, welcome_message, strlen(welcome_message), 0);

    // Loop until the client sends a message indicating that they are finished
    while (1) {
        // Receive a message from the client
        char message[MAX_MESSAGE_SIZE];
        int message_length = recv(socket_descriptor, message, MAX_MESSAGE_SIZE, 0);

        // If the client has sent a message indicating that they are finished, then close the socket and exit the thread
        if (strcmp(message, "exit\n") == 0) {
            close(socket_descriptor);
            pthread_exit(NULL);
        }

        // Otherwise, send the message back to the client
        send(socket_descriptor, message, message_length, 0);
    }

    // Free the memory allocated for the socket descriptor
    free(arg);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int yes = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port number
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Loop until the server is terminated
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread;
        int *socket_descriptor = malloc(sizeof(int));
        *socket_descriptor = client_socket;
        if (pthread_create(&thread, NULL, handle_client, socket_descriptor) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }

        // Detach the thread so that it can run independently of the main thread
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_socket);

    // Exit the program
    exit(EXIT_SUCCESS);
}