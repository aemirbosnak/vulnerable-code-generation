//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Server Function
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set Socket Options Failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept Failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Message received: %s\n", buffer);
        send(new_socket, buffer, valread, 0); // Echo back
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    close(new_socket);
    close(server_fd);
}

// Client Function
void start_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello, Server! This is Client.";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/address not supported \n");
        return;
    }

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return;
    }

    // Sending message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server.\n");

    // Reading echoed response from the server
    read(sock, buffer, BUFFER_SIZE);
    printf("Echo from server: %s\n", buffer);

    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc > 1 && strcmp(argv[1], "server") == 0) {
        start_server();
    } else {
        start_client();
    }
    return 0;
}