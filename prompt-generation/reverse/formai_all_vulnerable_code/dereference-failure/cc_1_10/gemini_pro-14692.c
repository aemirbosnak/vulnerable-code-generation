//GEMINI-pro DATASET v1.0 Category: Networking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Error handling macro
#define ERROR(msg) { perror(msg); exit(EXIT_FAILURE); }

int main(int argc, char** argv) {
    // Check if the user has provided the necessary arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the server's IP address and port number
    char* server_ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) ERROR("socket");

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(server_ip, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) ERROR("connect");

    // Send a message to the server
    char* message = "Hello, world!";
    if (send(sockfd, message, strlen(message), 0) < 0) ERROR("send");

    // Receive a message from the server
    char buffer[256];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) ERROR("recv");
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}