//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Send HTTP request to server
void send_http_request(int sockfd, const char* path, const char* host) {
    char buffer[BUFFER_SIZE];

    // Construct HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send HTTP request to server
    ssize_t bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
}

// Print HTTP response from server
void print_http_response(char* response) {
    char* line = strtok(response, "\n");

    // Skip HTTP headers
    while (line != NULL && strcmp(line, "\r") != 0) {
        line = strtok(NULL, "\n");
    }

    // Print HTTP response body
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* hostname = argv[1];
    const char* path = argv[2];

    // Get IP address from hostname
    struct hostent* host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        herror("gethostbyname() failed");
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr = *((struct in_addr*)host_entry->h_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request to server
    send_http_request(sockfd, path, hostname);

    // Receive HTTP response from server
    char* response = malloc(BUFFER_SIZE);
    size_t bytes_received = 0;
    ssize_t bytes_read;

    while ((bytes_read = recv(sockfd, response + bytes_received, BUFFER_SIZE - bytes_received, 0)) > 0) {
        bytes_received += bytes_read;
    }
    if (bytes_read < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }

    // Print HTTP response from server
    print_http_response(response);

    free(response);
    close(sockfd);
    return EXIT_SUCCESS;
}