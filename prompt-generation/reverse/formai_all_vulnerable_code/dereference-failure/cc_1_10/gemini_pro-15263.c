//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Error handling macro
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char** argv) {
    // Check if the correct number of arguments were provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the server IP address and port number from the command line arguments
    char* server_ip = argv[1];
    int port_number = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket");
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("inet_pton");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    // Send a message to the server
    char* message = "Hello from the client";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        handle_error("send");
    }

    // Receive a message from the server
    char buffer[256];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        handle_error("recv");
    }

    // Print the message received from the server
    printf("Message from the server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}