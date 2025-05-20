//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
/*
This program creates a TCP/IP server that listens to incoming connections and
sends a welcome message to the client. When the client sends a message, the server
responds with the length of the message and terminates the connection.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to my server";

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
	
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
        (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Send welcome message to the client
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Wait for client to send a message
    valread = read(new_socket, buffer, 1024);
    printf("Client sent: %s\n", buffer);

    // Send length of message to client
    int message_length = strlen(buffer);
    char length_message[50];
    sprintf(length_message, "Length of message: %d", message_length);
    send(new_socket, length_message, strlen(length_message), 0);

    // Terminate connection
    close(new_socket);
    close(server_fd);

    return 0;
}