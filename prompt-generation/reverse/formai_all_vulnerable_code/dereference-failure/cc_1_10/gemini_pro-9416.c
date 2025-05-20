//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define HTTP_PORT 80

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *path = argv[2];

    struct addrinfo hints;
    struct addrinfo *result;

    // Initialize the hints structure.
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    hints.ai_flags = AI_PASSIVE;      // Fill in the IP address

    // Get the address information for the hostname.
    int status = getaddrinfo(hostname, HTTP_PORT, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // Create a socket.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the HTTP request.
    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response.
    char response[4096];
    int nbytes;
    while ((nbytes = recv(sockfd, response, sizeof(response), 0)) > 0) {
        fwrite(response, 1, nbytes, stdout);
    }
    if (nbytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Close the socket.
    close(sockfd);

    // Free the address information.
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}