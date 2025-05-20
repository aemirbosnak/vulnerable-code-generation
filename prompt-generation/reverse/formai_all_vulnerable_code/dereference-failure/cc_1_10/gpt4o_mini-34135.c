//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFFER_SIZE 1024

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get server by hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Fill in server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read response from the server
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Output the response to standard output
    }

    if (bytes_received < 0) {
        perror("Error receiving response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Call the http_get function
    http_get(hostname, path);

    return 0;
}