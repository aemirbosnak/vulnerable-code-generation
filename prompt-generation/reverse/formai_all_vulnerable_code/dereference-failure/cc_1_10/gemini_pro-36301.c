//GEMINI-pro DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the port number
#define PORT 8080

// Create a socket
int create_socket() {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Bind the socket to the port
void bind_socket(int sockfd, int port) {
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

// Listen for connections
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
}

// Accept a connection
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cliaddr;
    memset(&cliaddr, 0, sizeof(cliaddr));
    socklen_t clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

// Send a message to the client
void send_message(int sockfd, char *message) {
    int n;
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the client
char *receive_message(int sockfd) {
    char *buffer = malloc(1024);
    int n;
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    return buffer;
}

// Close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main() {
    // Create a socket
    int sockfd = create_socket();

    // Bind the socket to the port
    bind_socket(sockfd, PORT);

    // Listen for connections
    listen_for_connections(sockfd);

    // Accept a connection
    int newsockfd = accept_connection(sockfd);

    // Send a message to the client
    send_message(newsockfd, "Hello, world!\n");

    // Receive a message from the client
    char *message = receive_message(newsockfd);

    // Print the message
    printf("Message from client: %s\n", message);

    // Close the socket
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}