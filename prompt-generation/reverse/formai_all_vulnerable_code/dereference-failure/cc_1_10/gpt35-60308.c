//FormAI DATASET v1.0 Category: Client Server Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8000

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Server socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Server socket bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 5) == -1) {
        perror("Server socket listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running and listening on port %d\n", PORT);

    // Accept client connections
    int client_fd;
    socklen_t address_length = sizeof(address);
    while ((client_fd = accept(server_fd, (struct sockaddr *)&address, &address_length))) {
        printf("Client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Create child process to handle client
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {  // Child process
            close(server_fd); // Close server socket in child process

            char message[1024] = {0};
            ssize_t bytes_received;
            while ((bytes_received = recv(client_fd, message, sizeof(message), 0)) > 0) {
                printf("Received message: %s", message);
                send(client_fd, message, bytes_received, 0);
                memset(message, 0, sizeof(message));
            }

            if (bytes_received == 0) {  // Connection closed by client
                printf("Client disconnected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            } else {  // Error occurred
                printf("Receive failed: %s\n", strerror(errno));
            }

            close(client_fd);  // Close client socket in child process
            exit(EXIT_SUCCESS);
        } else {  // Parent process
            close(client_fd);  // Close client socket in parent process
        }
    }

    if (client_fd == -1) {
        perror("Server socket accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}