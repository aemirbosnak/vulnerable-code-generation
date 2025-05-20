//GEMINI-pro DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the message buffer size
#define MESSAGE_BUFFER_SIZE 1024

// Define the thread function
void *client_thread(void *arg);

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) ==-1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    int client_sockets[MAX_CLIENTS];
    int num_clients = 0;
    while (num_clients < MAX_CLIENTS) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Add the client socket to the array of client sockets
        client_sockets[num_clients] = client_socket;
        num_clients++;

        // Create a new thread for the client
        pthread_t thread;
        if (pthread_create(&thread, NULL, client_thread, (void *)client_socket) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
    }

    // Close the server socket
    close(server_socket);

    // Exit the program
    return 0;
}

// Define the client thread function
void *client_thread(void *arg) {
    // Get the client socket
    int client_socket = (int)arg;

    // Receive messages from the client
    char message_buffer[MESSAGE_BUFFER_SIZE];
    while (1) {
        memset(message_buffer, 0, MESSAGE_BUFFER_SIZE);
        int num_bytes = recv(client_socket, message_buffer, MESSAGE_BUFFER_SIZE, 0);
        if (num_bytes == -1) {
            perror("recv");
            break;
        } else if (num_bytes == 0) {
            // The client has closed the connection
            break;
        }

        // Print the message to the console
        printf("Received message from client: %s\n", message_buffer);

        // Send a message back to the client
        memset(message_buffer, 0, MESSAGE_BUFFER_SIZE);
        strcpy(message_buffer, "Hello from the server!");
        if (send(client_socket, message_buffer, strlen(message_buffer), 0) == -1) {
            perror("send");
            break;
        }
    }

    // Close the client socket
    close(client_socket);

    // Exit the thread
    pthread_exit(NULL);
}