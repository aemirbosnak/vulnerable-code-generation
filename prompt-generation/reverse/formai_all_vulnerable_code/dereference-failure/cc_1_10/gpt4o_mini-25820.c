//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT "80"

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct addrinfo hints, *res;
    char buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    if (getaddrinfo(hostname, PORT, &hints, &res) != 0) {
        die("getaddrinfo");
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        die("socket");
    }

    // Connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        close(sockfd);
        die("connect");
    }

    freeaddrinfo(res); // Free the address info

    // Prepare the HTTP GET request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send request
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        die("send");
    }

    // Receive response
    printf("Response:\n");
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", buffer);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = NULL;
    char *path = NULL;
    char *url = argv[1];

    // Parse the URL
    if (strncmp(url, "http://", 7) == 0) {
        url += 7; // Skip "http://"
    }

    host = strtok(url, "/");
    if (host == NULL) {
        fprintf(stderr, "Invalid URL\n");
        exit(EXIT_FAILURE);
    }

    path = strtok(NULL, "");
    if (path == NULL) {
        path = "/"; // Default to root path
    } else {
        path = strtok(NULL, ""); // Remaining path components
        if (path == NULL) {
            path = "/";
        }
    }

    // Perform HTTP GET request
    http_get(host, path);

    return 0;
}