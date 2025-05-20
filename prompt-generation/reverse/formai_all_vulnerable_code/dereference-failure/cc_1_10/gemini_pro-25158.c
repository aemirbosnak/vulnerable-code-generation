//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

// Function to create a socket and connect to a server
int create_socket(const char *host, const char *port) {
    // Get the IP address of the server
    struct addrinfo hints;
    struct addrinfo *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    int status = getaddrinfo(host, port, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    // Create a socket and connect to the server
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // Free the memory allocated by getaddrinfo()
    freeaddrinfo(result);

    return sockfd;
}

// Function to send a HTTP request to a server
void send_request(int sockfd, const char *request) {
    // Send the request to the server
    size_t request_length = strlen(request);
    if (send(sockfd, request, request_length, 0) == -1) {
        perror("send");
        exit(1);
    }
}

// Function to receive the HTTP response from a server
void receive_response(int sockfd) {
    // Receive the response from the server
    char response[4096];
    ssize_t received_bytes;
    while ((received_bytes = recv(sockfd, response, sizeof(response), 0)) > 0) {
        // Print the response to the console
        printf("%.*s", (int) received_bytes, response);
    }
    if (received_bytes == -1) {
        perror("recv");
        exit(1);
    }
}

// Function to close a socket
void close_socket(int sockfd) {
    // Close the socket
    if (close(sockfd) == -1) {
        perror("close");
        exit(1);
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided the necessary arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket and connect to the server
    int sockfd = create_socket(argv[1], argv[2]);

    // Create the HTTP request
    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";

    // Send the request to the server
    send_request(sockfd, request);

    // Receive the response from the server
    receive_response(sockfd);

    // Close the socket
    close_socket(sockfd);

    return 0;
}