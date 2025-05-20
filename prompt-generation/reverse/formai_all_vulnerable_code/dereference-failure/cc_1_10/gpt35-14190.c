//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 7777

char* read_line() {
    char* line = NULL;
    size_t buffer_size = 0;
    ssize_t line_size = getline(&line, &buffer_size, stdin);
    if (line_size == -1) {
        perror("Error reading from stdin");
        exit(EXIT_FAILURE);
    }
    return line;
}

void add_delimiter(char* message) {
    int message_len = strlen(message);
    message[message_len] = '#';
    message[message_len+1] = '\0';
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to port 7777
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for incoming connection...\n");

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted! Type your message:\n");

    while(1) {

        // Read message from user
        char* message = read_line();

        // Add delimiter to message
        add_delimiter(message);

        // Send message to client
        send(new_socket, message, strlen(message), 0);

        // Receive message from client
        int valread = read(new_socket, buffer, 1024);

        // Remove delimiter from message
        buffer[valread-1] = '\0';

        // Print received message
        printf("Received message: %s\n", buffer);

        free(message);
    }

    return 0;
}