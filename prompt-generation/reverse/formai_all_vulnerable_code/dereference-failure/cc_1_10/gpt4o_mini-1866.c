//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    free(client_socket);

    char buffer[BUFFER_SIZE];
    read(sock, buffer, sizeof(buffer) - 1);

    // Simple HTTP response
    const char *http_response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
                                "<html><body><h1>Hello from Simple Web Server!</h1>"
                                "<p>You requested: </p><pre>%s</pre></body></html>";
    
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response), http_response, buffer);
    
    write(sock, response, strlen(response));
    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    // Main loop to accept connections
    while (1) {
        int *new_sock = malloc(sizeof(int));
        if ((*new_sock = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            free(new_sock);
            continue;
        }

        printf("Connection accepted!\n");

        // Create a thread to handle the client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, new_sock) != 0) {
            perror("Could not create thread");
            free(new_sock);
            close(*new_sock);
        } else {
            pthread_detach(thread_id); // Detach the thread to avoid memory leaks
        }
    }

    close(server_fd);
    return 0;
}