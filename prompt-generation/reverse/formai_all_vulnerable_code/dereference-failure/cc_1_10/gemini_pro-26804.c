//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define the maximum size of the HTTP request and response headers
#define MAX_HEADER_SIZE 1024

// Define the maximum size of the HTTP request and response bodies
#define MAX_BODY_SIZE 4096

// Create a socket
int create_socket(const char *host, const char *port)
{
    // Get the IP address of the host
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int err = getaddrinfo(host, port, &hints, &result);
    if (err != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return -1;
    }

    // Create a socket
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1)
    {
        perror("connect");
        return -1;
    }

    // Free the addrinfo structure
    freeaddrinfo(result);

    return sockfd;
}

// Send an HTTP request
int send_request(int sockfd, const char *path)
{
    // Create the HTTP request
    char request[MAX_HEADER_SIZE + MAX_BODY_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, "example.com");

    // Send the HTTP request
    int n = send(sockfd, request, strlen(request), 0);
    if (n == -1)
    {
        perror("send");
        return -1;
    }

    return n;
}

// Receive an HTTP response
int receive_response(int sockfd)
{
    // Create the HTTP response buffer
    char response[MAX_HEADER_SIZE + MAX_BODY_SIZE];

    // Receive the HTTP response
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1)
    {
        perror("recv");
        return -1;
    }

    // Print the HTTP response
    printf("%s", response);

    return n;
}

// Close the socket
void close_socket(int sockfd)
{
    close(sockfd);
}

// Main function
int main(int argc, char **argv)
{
    // Check the number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }

    // Create the socket
    int sockfd = create_socket(argv[1], argv[2]);
    if (sockfd == -1)
    {
        return -1;
    }

    // Send the HTTP request
    int n = send_request(sockfd, "/index.html");
    if (n == -1)
    {
        return -1;
    }

    // Receive the HTTP response
    n = receive_response(sockfd);
    if (n == -1)
    {
        return -1;
    }

    // Close the socket
    close_socket(sockfd);

    return 0;
}