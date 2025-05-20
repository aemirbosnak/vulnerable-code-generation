//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

void *client_handler(void *client_socket_ptr) {
    int client_socket = *(int *) client_socket_ptr;
    char buffer[1024] = {0};
    char request[1024] = {0};
    char response[8192] = {0};

    // Receive request from client
    recv(client_socket, buffer, 1024, 0);
    strcpy(request, buffer);

    // Parse request
    char method[16];
    char path[256];
    sscanf(request, "%s %s", method, path);

    // Open a connection to the remote server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    // Send request to remote server
    send(server_socket, request, strlen(request), 0);

    // Receive response from remote server
    int total_bytes = 0;
    while (1) {
        int bytes_received = recv(server_socket, response + total_bytes, 8192 - total_bytes, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }

    // Send response to client
    send(client_socket, response, total_bytes, 0);

    // Close sockets
    close(client_socket);
    close(server_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);
    pthread_t thread_id;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("Failed to listen for connections: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Proxy listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Failed to accept connection: %s\n", strerror(errno));
            continue;
        }
        printf("Accepted connection from %s:%d...\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Create a new thread to handle the connection
        if (pthread_create(&thread_id, NULL, client_handler, (void *) &client_socket) < 0) {
            printf("Failed to create thread: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }
    }

    return 0;
}