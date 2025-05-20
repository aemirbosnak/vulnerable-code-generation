//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    return sock;
}

void communicate_with_server(int sock) {
    char buffer[BUFFER_SIZE];
    int n;

    // Getting the welcome message from the server
    n = read(sock, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        error("Failed to read from the server");
    }

    buffer[n] = '\0';  // Null-terminate the buffer
    printf("Server: %s", buffer);

    // Main loop for communication
    while (1) {
        printf("Enter command (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Send command to the server
        if (send(sock, buffer, strlen(buffer), 0) < 0) {
            error("Failed to send command to the server");
        }

        // Receive response from the server
        n = read(sock, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            error("Failed to read from the server");
        }

        buffer[n] = '\0';  // Null-terminate the buffer
        printf("Server: %s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sock = connect_to_server(hostname, port);
    communicate_with_server(sock);

    close(sock);
    return 0;
}