//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192
#define DEFAULT_PORT "80"

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_http_request(int sockfd, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);
    write(sockfd, request, strlen(request));
}

void read_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        error("Failed to read response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    struct addrinfo hints, *res;
    int sockfd;

    // Prepare hints for getaddrinfo
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // Get address information
    if (getaddrinfo(hostname, DEFAULT_PORT, &hints, &res) != 0) {
        error("getaddrinfo");
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        error("Error creating socket");
    }

    // Connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        error("Error connecting to server");
    }

    freeaddrinfo(res); // Free the linked list

    // Send HTTP request
    send_http_request(sockfd, hostname, path);

    // Read and print the HTTP response
    read_http_response(sockfd);

    // Clean up and exit
    close(sockfd);
    return EXIT_SUCCESS;
}