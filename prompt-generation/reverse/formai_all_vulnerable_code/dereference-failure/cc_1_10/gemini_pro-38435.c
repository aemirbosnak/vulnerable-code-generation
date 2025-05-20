//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to handle client connections
void handle_client(int socket) {
    // Receive message from client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(socket);
        return;
    }

    // Print received message
    printf("Received from client: %s\n", buffer);

    // Send response to client
    char *response = "Hello from server!";
    int bytes_sent = send(socket, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        close(socket);
        return;
    }

    // Close client socket
    close(socket);
}

int main() {
    // Create TCP socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind socket to address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Accept client connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        // Handle client connection in a separate thread
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        pthread_create(&thread, NULL, handle_client, arg);
        pthread_detach(thread);
    }

    // Close server socket
    close(server_socket);

    return 0;
}