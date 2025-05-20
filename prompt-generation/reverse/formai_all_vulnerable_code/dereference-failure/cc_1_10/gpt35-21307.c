//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        error("Usage: ./proxy <ip> <port>");
    }

    int client_fd, server_fd;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error("Failed to create socket");
    }

    // Set socket address for the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Failed to bind socket to address");
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        error("Failed to listen for connections");
    }

    printf("Proxy server started on %s:%s\n", argv[1], argv[2]);

    while (1) {
        // Accept incoming connection
        socklen_t client_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            error("Failed to accept client connection");
        }

        // Fork a new process to handle the connection
        int pid = fork();
        if (pid < 0) {
            error("Failed to fork process");
        } else if (pid == 0) { // Child process
            close(server_fd);

            printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            // Create a socket for the server
            if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
                error("Failed to create socket");
            }

            // Set socket address for the server
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
            server_addr.sin_port = htons(80);

            // Connect to server
            if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                error("Failed to connect to server");
            }

            // Relay client request to server
            int bytes;
            while ((bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
                if (send(server_fd, buffer, bytes, 0) < 0) {
                    error("Failed to relay request to server");
                }
            }

            // Close sockets and exit child process
            close(client_fd);
            close(server_fd);
            exit(EXIT_SUCCESS);

        } else { // Parent process
            close(client_fd);
        }
    }

    return 0;
}