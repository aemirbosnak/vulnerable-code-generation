//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BACKLOG 10

// Function to create and set up the server
int setup_server(int port) {
    int server_fd;
    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    return server_fd;
}

// Function to handle client connection
void handle_client(int client_socket) {
    char buffer[256];
    int bytes_read;

    bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Read error");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Received: %s\n", buffer);

    // Echo the message back to the client
    write(client_socket, buffer, bytes_read);
    close(client_socket);
}

// Client code to connect to server and send message
void start_client(const char *hostname, int port) {
    int client_fd;
    struct sockaddr_in server_addr;
    char *message = "Hello from client!";
    
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    write(client_fd, message, strlen(message));
    char buffer[256];
    int bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Read error");
        close(client_fd);
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Server echoed: %s\n", buffer);

    close(client_fd);
}

// Main function to set up server or client based on arguments
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server|client> <port> [hostname]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);
    
    if (strcmp(argv[1], "server") == 0) {
        int server_fd = setup_server(port);
        printf("Server listening on port %d\n", port);

        while (1) {
            struct sockaddr_in client_addr;
            socklen_t addr_len = sizeof(client_addr);
            int client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
            
            if (client_socket < 0) {
                perror("Accept failed");
                continue;
            }

            handle_client(client_socket);
        }

    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Hostname required for client\n");
            exit(EXIT_FAILURE);
        }
        start_client(argv[3], port);
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}