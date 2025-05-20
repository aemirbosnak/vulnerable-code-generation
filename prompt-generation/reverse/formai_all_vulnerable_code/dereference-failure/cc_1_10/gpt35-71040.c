//FormAI DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_error(const char* error_message) {
    fprintf(stderr, "%s: %s\n", error_message, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int socket_fd, new_socket_fd, valread;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t address_length = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char* welcome_message = "Welcome to the server!\n";
    
    // Create a TCP socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("socket");
    }

    // Set socket options to allow address reuse
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
            &opt, sizeof(opt)) == -1) {
        handle_error("setsockopt");
    }

    // Bind the socket to a local address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        handle_error("bind");
    }

    // Listen for incoming connections
    if (listen(socket_fd, 3) == -1) {
        handle_error("listen");
    }

    // Accept an incoming connection
    if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&address, 
            &address_length)) == -1) {
        handle_error("accept");
    }

    // Send a welcome message to the client
    if (send(new_socket_fd, welcome_message, strlen(welcome_message), 0) == -1) {
        handle_error("send");
    }

    printf("Connected with client %s on port %d\n", 
            inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Receive data from client
    while ((valread = read(new_socket_fd, buffer, BUFFER_SIZE)) > 0) {
        printf("Received from client: %s", buffer);

        // Echo back the message to the client
        if (send(new_socket_fd, buffer, strlen(buffer), 0) == -1) {
            handle_error("send");
        }

        // Clear the buffer
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (valread == -1) {
        handle_error("read");
    }

    // Close the socket
    close(new_socket_fd);
    close(socket_fd);

    return 0;
}