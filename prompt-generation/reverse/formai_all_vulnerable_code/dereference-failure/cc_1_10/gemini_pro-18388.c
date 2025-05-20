//GEMINI-pro DATASET v1.0 Category: Networking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// This function is a wrapper around the send() system call that ensures the entire message is sent.
int send_all(int socket, void *buffer, size_t length) {
    int sent = 0;
    while (sent < length) {
        int n = send(socket, buffer + sent, length - sent, 0);
        if (n == -1) {
            return -1;
        }
        sent += n;
    }
    return sent;
}

// This function is a wrapper around the recv() system call that ensures the entire message is received.
int recv_all(int socket, void *buffer, size_t length) {
    int received = 0;
    while (received < length) {
        int n = recv(socket, buffer + received, length - received, 0);
        if (n == -1) {
            return -1;
        }
        received += n;
    }
    return received;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket.
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) != 1) {
        perror("inet_pton");
        return 1;
    }
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a message to the server.
    const char *message = "Hello, server!\n";
    if (send_all(socket_fd, message, strlen(message)) == -1) {
        perror("send_all");
        return 1;
    }

    // Receive a response from the server.
    char buffer[1024];
    if (recv_all(socket_fd, buffer, sizeof(buffer)) == -1) {
        perror("recv_all");
        return 1;
    }

    // Print the response from the server.
    printf("Received: %s", buffer);

    // Close the socket.
    close(socket_fd);

    return 0;
}