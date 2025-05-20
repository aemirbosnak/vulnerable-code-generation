//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number
#define PORT 8080

// Define the maximum size of the message
#define MAX_MESSAGE_SIZE 1024

// Create a socket
int create_socket() {
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Return the socket file descriptor
    return sockfd;
}

// Bind the socket to an IP address and port
void bind_socket(int sockfd, struct sockaddr_in *servaddr) {
    // Bind the socket to the IP address and port
    if (bind(sockfd, (struct sockaddr *)servaddr, sizeof(*servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
}

// Listen for connections on the socket
void listen_for_connections(int sockfd) {
    // Listen for connections
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

// Accept a connection on the socket
int accept_connection(int sockfd) {
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t len;

    // Accept a connection
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (connfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Return the connection file descriptor
    return connfd;
}

// Send a message to the client
void send_message(int connfd, char *message) {
    // Send the message to the client
    if (send(connfd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the client
char *receive_message(int connfd) {
    char *message;
    int n;

    // Allocate memory for the message
    message = malloc(MAX_MESSAGE_SIZE);
    if (message == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the client
    n = recv(connfd, message, MAX_MESSAGE_SIZE, 0);
    if (n == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Return the message
    return message;
}

// Close the connection
void close_connection(int connfd) {
    // Close the connection
    if (close(connfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char *message;

    // Create a socket
    sockfd = create_socket();

    // Bind the socket to an IP address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    bind_socket(sockfd, &servaddr);

    // Listen for connections on the socket
    listen_for_connections(sockfd);

    // Accept a connection on the socket
    connfd = accept_connection(sockfd);

    // Receive a message from the client
    message = receive_message(connfd);

    // Print the message
    printf("Received message: %s\n", message);

    // Send a message to the client
    message = "Hello, world!\n";
    send_message(connfd, message);

    // Close the connection
    close_connection(connfd);

    // Close the socket
    close(sockfd);

    return 0;
}