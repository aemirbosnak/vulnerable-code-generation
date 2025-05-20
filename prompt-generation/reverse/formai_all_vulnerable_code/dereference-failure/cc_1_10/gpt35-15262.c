//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_error(char *message);
bool validate_url(char *url, char **hostname, char **path);
void build_http_request(char *http_request, char *hostname, char *path);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s URL\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *hostname = NULL;
    char *path = NULL;

    // Validate URL
    if (!validate_url(url, &hostname, &path)) {
        printf("Invalid URL.\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error creating socket");
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Error connecting to server");
    }

    // Build HTTP request
    char http_request[BUFFER_SIZE];
    build_http_request(http_request, hostname, path);

    // Send HTTP request
    if (send(sockfd, http_request, strlen(http_request), 0) < 0) {
        handle_error("Error sending data");
    }

    // Receive server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close socket
    close(sockfd);

    return 0;
}

void handle_error(char *message) {
    perror(message);
    exit(1);
}

bool validate_url(char *url, char **hostname, char **path) {
    // Validate format
    if (strncmp(url, "http://", 7) != 0) {
        return false;
    }

    // Get hostname and path
    char *slash_pos = strchr(url + 7, '/');
    if (slash_pos == NULL) {
        *hostname = strdup(url + 7);
        *path = strdup("/");
    } else {
        *hostname = strndup(url + 7, slash_pos - url - 7);
        *path = strdup(slash_pos);
    }

    return true;
}

void build_http_request(char *http_request, char *hostname, char *path) {
    sprintf(http_request, "GET %s HTTP/1.0\r\n"
                          "Host: %s\r\n"
                          "User-Agent: HTTPClient/1.0\r\n"
                          "Connection: close\r\n\r\n",
                          path, hostname);
}