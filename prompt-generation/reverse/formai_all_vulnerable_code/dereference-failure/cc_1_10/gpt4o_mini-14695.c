//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 4096

void error(const char* msg) {
    perror(msg);
    exit(1);
}

char* build_http_request(const char *hostname, const char *path) {
    char *request = malloc(MAX_BUFFER * sizeof(char));
    if (request == NULL) {
        error("Memory allocation failed");
    }
    
    snprintf(request, MAX_BUFFER,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);
    
    return request;
}

void perform_http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Get server by hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        error("No such host");
    }

    // Server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Failed to connect");
    }

    // Build the HTTP request
    char *request = build_http_request(hostname, path);

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }

    // Buffer to store the response from the server
    char response[MAX_BUFFER];
    memset(response, 0, MAX_BUFFER);
    int received;

    // Read the response
    while ((received = recv(sockfd, response, MAX_BUFFER - 1, 0)) > 0) {
        response[received] = '\0'; // Null-terminate the buffer
        printf("%s", response); // Print the response
    }

    // Error in receiving data
    if (received < 0) {
        error("Error receiving response");
    }

    // Clean up
    free(request);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    perform_http_get(hostname, path);

    return 0;
}