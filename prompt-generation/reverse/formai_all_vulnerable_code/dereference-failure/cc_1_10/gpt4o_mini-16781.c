//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_socket);
        return NULL;
    }

    buffer[bytes_read] = '\0'; // null-terminate the string
    printf("Received request:\n%s\n", buffer);

    // Respond to GET requests
    if (strncmp(buffer, "GET", 3) == 0) {
        // Simple HTTP response
        char *response_header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        char *response_body = "<html><body><h1>Hello, World!</h1></body></html>";
        send(client_socket, response_header, strlen(response_header), 0);
        send(client_socket, response_body, strlen(response_body), 0);
    } else {
        // Handle unsupported methods
        char *response_header = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        send(client_socket, response_header, strlen(response_header), 0);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, *client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        client_socket = malloc(sizeof(int)); // Allocate memory for client socket
        if ((*client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept failed");
            free(client_socket);
            continue; // Do not exit, keep listening for connections
        }

        // Create a new thread to handle the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, client_socket) != 0) {
            perror("pthread_create failed");
            close(*client_socket);
            free(client_socket);
        } else {
            pthread_detach(thread_id); // Detach the thread to avoid memory leaks
        }
    }

    close(server_socket);
    return 0;
}