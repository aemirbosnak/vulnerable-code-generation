//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// This program is a simple TCP client that connects to a server and sends a message.
// It's written in a introspective style, which means that it includes comments that explain
// what the program is doing and why.

// This function creates a TCP socket and connects it to the specified server.
int create_and_connect_socket(const char *server_ip, int port) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// This function sends a message to the specified socket.
void send_message(int sockfd, const char *message) {
    // Send the message.
    int len = strlen(message);
    if (send(sockfd, message, len, 0) != len) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// This function receives a message from the specified socket.
char *receive_message(int sockfd) {
    // Receive the message.
    char *buffer = malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int len = recv(sockfd, buffer, 1024, 0);
    if (len == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the message.
    buffer[len] = '\0';

    return buffer;
}

// This function closes the specified socket.
void close_socket(int sockfd) {
    // Close the socket.
    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    // Check the command-line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket and connect it to the server.
    int sockfd = create_and_connect_socket(argv[1], atoi(argv[2]));

    // Send a message to the server.
    send_message(sockfd, "Hello, world!\n");

    // Receive a message from the server.
    char *message = receive_message(sockfd);

    // Print the message.
    printf("Received message: %s\n", message);

    // Free the message buffer.
    free(message);

    // Close the socket.
    close_socket(sockfd);

    return EXIT_SUCCESS;
}