//FormAI DATASET v1.0 Category: Networking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    // Check if command line arguments are correct
    if (argc < 2) {
        perror("Usage: ./server <port>");
        exit(1);
    }

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set socket options to reuse the address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Set address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    // Create loop to handle connections
    while (1) {

        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Client connected\n");

        // Create loop to handle requests from client
        while (1) {

            // Read message from client
            if ((valread = read(new_socket, buffer, BUFFER_SIZE)) == 0) {
                printf("Client disconnected\n");
                break;
            }

            // Print message from client
            printf("Client: %s", buffer);

            // Send message to client
            send(new_socket, buffer, strlen(buffer), 0);
        }

        close(new_socket);
    }

    return 0;
}