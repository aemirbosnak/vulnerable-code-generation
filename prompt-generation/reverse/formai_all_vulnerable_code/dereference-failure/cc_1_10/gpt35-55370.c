//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    printf("Starting server on port %d...\n", port);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Could not create socket");
        exit(1);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Could not set socket options");
        exit(1);
    }

    // Bind socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Could not bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Could not listen for incoming connections");
        exit(1);
    }

    printf("Server is ready and waiting for connections...\n");

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Could not accept incoming connection");
            continue;
        }

        printf("Client connected\n");

        char buffer[1024] = {0};
        int valread;
        char *hello = "Hello from server!\n";

        // Send greeting message to client
        send(new_socket, hello, strlen(hello), 0);
        printf("Greeting message sent\n");

        // Receive data from client
        valread = read(new_socket, buffer, 1024);
        printf("Received data: %s", buffer);
    }

    return 0;
}