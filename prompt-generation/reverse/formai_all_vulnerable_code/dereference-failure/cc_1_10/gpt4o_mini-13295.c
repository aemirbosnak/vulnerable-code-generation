//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", program_name);
}

void perform_http_request(const char *hostname, int port, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    ssize_t bytes_received;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Create the HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read and print the server's response
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response to stdout
    }

    // Handle errors in receiving data
    if (bytes_received < 0) {
        perror("Recv failed");
    }

    // Clean up and close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    perform_http_request(hostname, port, path);

    return EXIT_SUCCESS;
}