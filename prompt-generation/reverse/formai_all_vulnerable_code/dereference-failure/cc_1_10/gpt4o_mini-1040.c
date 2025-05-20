//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_client(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    // Lookup the host
    server = gethostbyname(host);
    if (server == NULL) error("No such host");

    // Prepare the server address structure
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Connection failed");

    // Prepare the HTTP GET request
    snprintf(buffer, sizeof(buffer),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);

    // Send the request
    if (write(sockfd, buffer, strlen(buffer)) < 0) error("Failed to send request");

    // Read the response
    printf("Response from server:\n");
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t n;
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n < 0) error("Error reading response");

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Basic usage check
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // Let's begin our journey into the realms of HTTP
    printf("Establishing HTTP connection to %s at path: %s...\n", host, path);
    http_client(host, path);
    
    printf("\nConnection closed. Until next time, dear friend!\n");
    return EXIT_SUCCESS;
}