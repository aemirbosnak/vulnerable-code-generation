//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 5
#define MAX_REQUEST_SIZE 1024

int create_socket(int port);

int main(int argc, char const *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[MAX_REQUEST_SIZE];

    if (argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create server socket
    server_socket = create_socket(atoi(argv[1]));

    // Listen for connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server running on port %s...\n", argv[1]);

    while (1) {
        // Accept incoming connections
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);

        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from client
        memset(buffer, 0, MAX_REQUEST_SIZE);
        recv(client_socket, buffer, MAX_REQUEST_SIZE, 0);

        // Respond to client
        char *response = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, World!";
        send(client_socket, response, strlen(response), 0);

        // Close client socket
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

int create_socket(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}