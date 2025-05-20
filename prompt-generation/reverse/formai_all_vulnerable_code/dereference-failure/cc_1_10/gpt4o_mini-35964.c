//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server Code
void chat_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("Socket creation failed");
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("Set socket options failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("Bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        error("Listen failed");
    }
    
    printf("Server is listening on port %d...\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error("Accept failed");
    }

    // Chat loop
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size <= 0) {
            printf("Client disconnected or read error.\n");
            break;
        }
        printf("Client: %s", buffer);
        send(new_socket, buffer, read_size, 0); // Echo back
    }

    close(new_socket);
    close(server_fd);
}

// Client Code
void chat_client(const char *server_ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    // Chat loop
    while (1) {
        printf("You: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Server: %s", buffer);
    }

    close(sock);
}

// Main function
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [server|client] [server_ip (if client)]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "server") == 0) {
        chat_server();
    } else if (strcmp(argv[1], "client") == 0 && argc == 3) {
        chat_client(argv[2]);
    } else {
        fprintf(stderr, "Invalid mode. Use 'server' or 'client'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}