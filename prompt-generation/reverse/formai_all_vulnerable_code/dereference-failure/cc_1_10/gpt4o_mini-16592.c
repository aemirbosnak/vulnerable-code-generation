//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define QUEUE_SIZE 10

// Function to handle client requests
void *handle_client(void *client_socket) {
    int sock = *((int *)client_socket);
    free(client_socket);
    char buffer[BUFFER_SIZE];
    
    // Receive the request
    recv(sock, buffer, BUFFER_SIZE, 0);
    
    // Print the received request
    printf("Received request:\n%s\n", buffer);
    
    // Crafting a simple HTTP response
    const char *http_response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n\r\n"
        "<html><body><h1>Welcome to My C Web Server!</h1></body></html>";

    // Send the response
    send(sock, http_response, strlen(http_response), 0);
    close(sock);
    return NULL;
}

// Main function
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting options for socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setting socket options failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, QUEUE_SIZE) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Surprise! Server running on port %d\n", PORT);
    
    // Server loop to accept connections
    while (1) {
        printf("Waiting for new connection...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting connection failed");
            continue;
        }
        
        printf("A new connection has arrived!\n");

        // Creating a thread to handle the client
        pthread_t thread_id;
        int *client_sock = malloc(sizeof(int));
        *client_sock = new_socket;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)client_sock) != 0) {
            perror("Thread creation failed");
            free(client_sock);
            close(new_socket);
        }

        // Detaching the thread
        pthread_detach(thread_id);
    }

    // Closing the server socket (though this point is never reached in this loop)
    close(server_fd);
    return 0;
}