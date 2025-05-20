//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 3490 // Port number for the server

// Get a socket descriptor for a server listening on the specified port
int get_server_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections on the socket
    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    return sockfd;
}

// Accept a connection on a socket and return the new socket descriptor
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen;

    // Accept a connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    return newsockfd;
}

// Send a message to a socket
void send_message(int sockfd, char *message) {
    int n;

    // Send the message
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }
}

// Receive a message from a socket
char *receive_message(int sockfd) {
    char *message;
    int n;

    // Receive the message
    message = malloc(256);
    n = recv(sockfd, message, 255, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(1);
    }

    // Null-terminate the message
    message[n] = '\0';

    return message;
}

// Close a socket
void close_socket(int sockfd) {
    close(sockfd);
}

int main() {
    int sockfd, newsockfd;
    char *message;

    // Get a socket descriptor for the server
    sockfd = get_server_socket(PORT);

    // Accept a connection on the socket
    newsockfd = accept_connection(sockfd);

    // Receive a message from the client
    message = receive_message(newsockfd);
    printf("Received message: %s\n", message);

    // Send a message to the client
    send_message(newsockfd, "Hello from the server!");

    // Close the sockets
    close_socket(newsockfd);
    close_socket(sockfd);

    return 0;
}