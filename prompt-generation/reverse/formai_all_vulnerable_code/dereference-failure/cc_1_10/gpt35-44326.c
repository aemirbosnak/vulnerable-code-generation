//FormAI DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if all required arguments are provided
    if(argc < 2) {
        printf("Usage: %s port_number\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int server_fd, new_socket, val_read;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create the server socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setup the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind the socket to the server address
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if(listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", port);

    // Handles connections with multiple clients
    while(true) {
        // Accept a new connection
        if((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection received from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Read client's message
        val_read = read(new_socket, buffer, BUFFER_SIZE);
        printf("Received message from client: %s\n", buffer);

        // Send response to client
        char *response_message = "Hello from server!";
        send(new_socket, response_message, strlen(response_message), 0);
        printf("Response sent to client: %s\n", response_message);

        // Close the connection with the current client
        close(new_socket);
        printf("Connection with client closed\n");
    }

    return 0;
}