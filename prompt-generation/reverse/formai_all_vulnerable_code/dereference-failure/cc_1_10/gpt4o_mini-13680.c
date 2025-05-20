//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "www.example.com"
#define PORT 80
#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd, bytes;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];

    // Resolving the server hostname
    if ((host = gethostbyname(hostname)) == NULL) {
        error("Failed to resolve hostname");
    }

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }

    // Setting up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Failed to connect");
    }

    // Preparing the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Sending the HTTP request
    send(sockfd, request, strlen(request), 0);

    // Reading the response
    while ((bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes] = '\0';  // Null-terminate the buffer
        printf("%s", buffer);  // Print the received data
    }

    // Closing the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    printf("HTTP GET request to %s%s\n", hostname, path);
    http_get(hostname, path);
    
    return EXIT_SUCCESS;
}