//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Function to handle secure socket communication.
int secure_socket(char *hostname, int port) {
    struct addrinfo hints, *res;
    int sockfd, ret;

    // Initialize the hints structure.
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Get the address information for the specified hostname and port.
    if ((ret = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(ret));
        return -1;
    }

    // Create a socket using the address information.
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket()");
        freeaddrinfo(res);
        return -1;
    }

    // Bind the socket to the specified address.
    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("bind()");
        freeaddrinfo(res);
        close(sockfd);
        return -1;
    }

    // Free the address information.
    freeaddrinfo(res);

    // Listen for incoming connections.
    if (listen(sockfd, 1) == -1) {
        perror("listen()");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function to handle client communication.
void handle_client(int sockfd) {
    char buffer[1024];
    int n;

    // Receive a message from the client.
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv()");
        close(sockfd);
        return;
    }

    // Send a message back to the client.
    if (send(sockfd, buffer, n, 0) == -1) {
        perror("send()");
        close(sockfd);
        return;
    }

    // Close the socket.
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;

    // Check the command-line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    // Create a secure socket.
    if ((sockfd = secure_socket(argv[1], atoi(argv[2]))) == -1) {
        fprintf(stderr, "secure_socket(): failed to create a secure socket\n");
        return 1;
    }

    // Accept incoming connections.
    while (1) {
        // Accept a new connection.
        if ((newsockfd = accept(sockfd, NULL, NULL)) == -1) {
            perror("accept()");
            close(sockfd);
            return 1;
        }

        // Handle the client communication.
        handle_client(newsockfd);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}