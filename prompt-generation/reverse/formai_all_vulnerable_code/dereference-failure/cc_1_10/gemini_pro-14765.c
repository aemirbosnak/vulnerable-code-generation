//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// Maximum buffer size
#define MAX_BUFFER_SIZE 1024

// Thread arguments struct
typedef struct thread_args {
    int client_socket;
    struct sockaddr_in client_address;
    int server_socket;
    struct sockaddr_in server_address;
} thread_args;

// Thread function
void *thread_func(void *args) {
    // Extract thread arguments
    thread_args *arg = (thread_args *)args;

    // Buffer for request and response
    char request[MAX_BUFFER_SIZE];
    char response[MAX_BUFFER_SIZE];

    // Infinite loop to handle multiple requests from the same client
    while (true) {
        // Receive request from client
        int recv_size = recv(arg->client_socket, request, MAX_BUFFER_SIZE, 0);
        if (recv_size == 0) {
            // Client closed connection, exit thread
            break;
        } else if (recv_size < 0) {
            perror("Error receiving request");
            break;
        }

        // Parse request line
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        // Check if request is valid
        if (method == NULL || path == NULL || http_version == NULL) {
            // Invalid request, send 400 Bad Request
            sprintf(response, "HTTP/1.1 400 Bad Request\r\n\r\n");
            send(arg->client_socket, response, strlen(response), 0);
            continue;
        }

        // Connect to server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            perror("Error creating server socket");
            break;
        }

        if (connect(server_socket, (struct sockaddr *)&arg->server_address, sizeof(arg->server_address)) < 0) {
            perror("Error connecting to server");
            break;
        }

        // Send request to server
        send(server_socket, request, recv_size, 0);

        // Receive response from server
        int resp_size = recv(server_socket, response, MAX_BUFFER_SIZE, 0);
        if (resp_size == 0) {
            // Server closed connection, close client connection
            close(server_socket);
            break;
        } else if (resp_size < 0) {
            perror("Error receiving response");
            break;
        }

        // Send response to client
        send(arg->client_socket, response, resp_size, 0);

        // Close server socket
        close(server_socket);
    }

    // Close client socket
    close(arg->client_socket);

    // Free thread arguments
    free(arg);

    return NULL;
}

int main() {
    // Server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return 1;
    }

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket to address");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Error listening for incoming connections");
        return 1;
    }

    // Infinite loop to handle multiple client connections
    while (true) {
        // Accept client connection
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
        if (client_socket == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Create thread arguments
        thread_args *args = malloc(sizeof(thread_args));
        args->client_socket = client_socket;
        args->client_address = client_address;
        args->server_socket = server_socket;
        args->server_address = server_address;

        // Create thread to handle client connection
        pthread_t thread;
        if (pthread_create(&thread, NULL, thread_func, args) != 0) {
            perror("Error creating thread");
            free(args);
            continue;
        }

        // Detach thread so it can run independently
        pthread_detach(thread);
    }

    // Close server socket
    close(server_socket);

    return 0;
}