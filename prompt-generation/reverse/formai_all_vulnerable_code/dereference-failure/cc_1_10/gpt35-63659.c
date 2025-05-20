//FormAI DATASET v1.0 Category: Client Server Application ; Style: authentic
// This is an example C Client Server application program which allows the clients to communicate with the server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }
    int port = atoi(argv[1]);

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Failed to create socket\n");
        return -1;
    }

    // Bind to address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Failed to bind to port %d\n", port);
        return -1;
    }

    // Start listening for connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        printf("Failed to start listening for connections\n");
        return -1;
    }

    // Wait for clients to connect
    printf("Waiting for clients to connect...\n");
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            printf("Failed to accept client connection\n");
            continue;
        }
        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client requests
        memset(buffer, 0, BUFFER_SIZE);
        int num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
        while (num_bytes > 0) {
            printf("Client %s:%d says: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
            send(client_fd, buffer, num_bytes, 0);
            memset(buffer, 0, BUFFER_SIZE);
            num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
        }

        // Client disconnected
        printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(client_fd);
    }

    return 0;
}