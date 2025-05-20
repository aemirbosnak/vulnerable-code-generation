//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void performSecurityCheck(int client_socket) {
    // Simulating a paranoid check
    char *suspiciousPatterns[] = {"exploit", "hack", "malware"};
    char buffer[BUFFER_SIZE];
    int readSize;

    // Check for malicious input
    if ((readSize = read(client_socket, buffer, BUFFER_SIZE - 1)) < 0) {
        handleError("Error reading from client socket");
    }
    buffer[readSize] = '\0';

    for (int i = 0; i < sizeof(suspiciousPatterns) / sizeof(suspiciousPatterns[0]); i++) {
        if (strstr(buffer, suspiciousPatterns[i]) != NULL) {
            fprintf(stderr, "Suspicious input detected: %s\n", buffer);
            close(client_socket);
            exit(EXIT_FAILURE);
        }
    }

    printf("Client input: %s\n", buffer);
}

void echoResponse(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while (1) {
        bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0) {
            handleError("Read error");
        } else if (bytes_read == 0) {
            break; // Client closed connection
        }

        buffer[bytes_read] = '\0';
        performSecurityCheck(client_socket);

        printf("Echoing back: %s", buffer);
        ssize_t bytes_sent = write(client_socket, buffer, bytes_read);
        if (bytes_sent < 0) {
            handleError("Write error");
        }
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Socket creation error");
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handleError("Bind error");
    }

    // Listen
    if (listen(server_socket, 3) < 0) {
        handleError("Listen error");
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept client connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue; // Accept the next connection
        }

        printf("Accepted connection from client\n");
        echoResponse(client_socket); // Handle client communication
        close(client_socket); // Close after handling
        printf("Closed client connection\n");
    }

    // Close server socket (never reached)
    close(server_socket);
    return 0;
}