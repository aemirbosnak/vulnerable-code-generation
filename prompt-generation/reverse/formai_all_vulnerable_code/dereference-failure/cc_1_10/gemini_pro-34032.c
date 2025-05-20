//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of connections
#define MAX_CONNECTIONS 100

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Create a socket
int create_socket(int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

// Accept a connection
int accept_connection(int sockfd) {
    int connfd;
    struct sockaddr_in cliaddr;
    socklen_t cliaddr_len;

    // Accept a connection
    connfd = accept(sockfd, (struct sockaddr *) &cliaddr, &cliaddr_len);
    if (connfd == -1) {
        perror("accept");
        exit(1);
    }

    return connfd;
}

// Receive a message
int receive_message(int connfd) {
    char message[MAX_MESSAGE_LENGTH];
    int n;

    // Receive a message
    n = recv(connfd, message, MAX_MESSAGE_LENGTH, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }

    // Print the message
    printf("Received message: %s\n", message);

    return n;
}

// Send a message
int send_message(int connfd, char *message) {
    int n;

    // Send a message
    n = send(connfd, message, strlen(message), 0);
    if (n == -1) {
        perror("send");
        exit(1);
    }

    return n;
}

// Close a connection
int close_connection(int connfd) {
    // Close the connection
    close(connfd);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Create a socket
    int sockfd = create_socket(port);

    // Accept connections
    while (1) {
        // Accept a connection
        int connfd = accept_connection(sockfd);

        // Receive a message
        int n = receive_message(connfd);

        // Send a message
        send_message(connfd, "Hello world!");

        // Close the connection
        close_connection(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}