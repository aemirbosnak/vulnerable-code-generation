//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the IP address from the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: No such host: %s\n", hostname);
        return -1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Establish connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void http_get(const char *hostname, const char *path) {
    int sockfd = create_connection(hostname, 80);
    if (sockfd < 0) return; // Connection failed, exit

    // Prepare the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Error sending request");
    }

    // Buffer to store the response
    char response[BUFFER_SIZE];
    printf("Response from server:\n");

    // Read the response from the server
    while (1) {
        memset(response, 0, sizeof(response));
        int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) break; // No more data or an error occurred
        printf("%s", response);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    printf("Making an HTTP GET request to %s%s...\n", hostname, path);
    http_get(hostname, path);
    printf("\nRequest completed!\n");

    return 0;
}