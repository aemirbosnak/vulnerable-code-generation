//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to print the error message and exit the program.
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to create a socket and bind it to a port.
int create_and_bind_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Set the socket options.
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
        error("ERROR setting socket options");

    // Bind the socket to a port.
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR binding socket");

    return sockfd;
}

// Function to listen for incoming connections.
void listen_for_connections(int sockfd) {
    if (listen(sockfd, 5) < 0)
        error("ERROR listening for connections");
}

// Function to accept an incoming connection.
int accept_connection(int sockfd) {
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen;

    // Accept an incoming connection.
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR accepting connection");

    return newsockfd;
}

// Function to send a message to a client.
void send_message(int sockfd, char *message) {
    int n;

    // Send the message to the client.
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
}

// Function to receive a message from a client.
char *receive_message(int sockfd) {
    char buffer[256];
    int n;

    // Receive the message from the client.
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0)
        error("ERROR reading from socket");

    // Return the message.
    return strdup(buffer);
}

// Main function.
int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    char *message;

    // Check the number of arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get the port number.
    int port = atoi(argv[1]);

    // Create a socket and bind it to a port.
    sockfd = create_and_bind_socket(port);

    // Listen for incoming connections.
    listen_for_connections(sockfd);

    // Accept an incoming connection.
    newsockfd = accept_connection(sockfd);

    // Receive a message from the client.
    message = receive_message(newsockfd);

    // Print the message.
    printf("Message from client: %s\n", message);

    // Send a message to the client.
    send_message(newsockfd, "Hello from the server!");

    // Close the connection.
    close(newsockfd);
    close(sockfd);

    return 0;
}