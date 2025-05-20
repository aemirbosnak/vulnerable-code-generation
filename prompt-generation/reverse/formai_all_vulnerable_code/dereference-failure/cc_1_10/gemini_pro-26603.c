//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *port = argv[2];

    // Get the IP address of the host.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    struct addrinfo *result;
    int err = getaddrinfo(host, port, &hints, &result);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the host.
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a HTTP GET request to the host.
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request_buffer[strlen(request) + strlen(host) + 1];
    sprintf(request_buffer, request, host);
    if (send(sockfd, request_buffer, strlen(request_buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response from the host.
    char response_buffer[4096];
    int bytes_received = recv(sockfd, response_buffer, sizeof(response_buffer), 0);
    if (bytes_received == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the HTTP response to the console.
    printf("%s", response_buffer);

    // Close the socket.
    close(sockfd);

    // Free the memory allocated by getaddrinfo().
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}