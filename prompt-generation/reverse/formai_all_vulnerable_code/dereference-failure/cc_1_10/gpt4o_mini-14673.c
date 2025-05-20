//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

char* get_http_response(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char *response = (char *)malloc(BUFFER_SIZE);
    int bytes_received;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);  // HTTP port

    // Convert IPv4 addresses from text to binary form
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("Invalid address or Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the request
    send(sockfd, request, strlen(request), 0);

    // Read the response
    memset(response, 0, BUFFER_SIZE); // Initialize response buffer
    bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    
    // Check for errors in receiving the data
    if (bytes_received < 0) {
        error("Failed to receive data");
    }

    response[bytes_received] = '\0'; // Null terminate the response

    close(sockfd); // Close socket connection

    return response;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    char *response = get_http_response(host, path);

    printf("HTTP Response:\n%s\n", response);

    free(response); // Free the allocated response buffer
    
    return 0;
}