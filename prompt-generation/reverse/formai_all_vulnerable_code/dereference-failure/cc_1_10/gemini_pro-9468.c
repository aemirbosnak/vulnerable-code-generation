//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

// Define the port number
#define PORT 8080

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the host information
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Initialize the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char *message = "Hello, world!";
    if (write(sockfd, message, strlen(message)) == -1) {
        perror("write");
        exit(1);
    }

    // Receive a message from the server
    char buffer[256];
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        exit(1);
    }

    // Print the message received from the server
    printf("Message received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}