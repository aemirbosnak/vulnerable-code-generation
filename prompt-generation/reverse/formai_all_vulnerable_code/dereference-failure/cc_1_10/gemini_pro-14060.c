//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

// Define the port number for the server
#define PORT 8080

// Create a socket and return its file descriptor
int create_socket() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Specify the server's address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket to the server's address and port
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Accept an incoming connection and return the file descriptor of the new socket
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen;

    // Accept an incoming connection
    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return newsockfd;
}

// Send a message to the client
void send_message(int sockfd, char *message) {
    int n;

    // Send the message to the client
    n = write(sockfd, message, strlen(message));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the client
char *receive_message(int sockfd) {
    char buffer[256];
    int n;

    // Receive the message from the client
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Return the message
    return strdup(buffer);
}

// Close a socket
void close_socket(int sockfd) {
    // Close the socket
    close(sockfd);
}

// Main function
int main() {
    int sockfd, newsockfd;
    char *message;

    // Create a socket
    sockfd = create_socket();

    // Accept an incoming connection
    newsockfd = accept_connection(sockfd);

    // Receive a message from the client
    message = receive_message(newsockfd);

    // Send a message to the client
    send_message(newsockfd, "Hello, world!");

    // Close the socket
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}