//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to print the usage of the HTTP Client
void print_usage(const char *prog_name) {
    printf("Usage: %s <hostname> <port> <path>\n", prog_name);
    printf("Example: %s www.example.com 80 /\n", prog_name);
}

// Function to perform HTTP GET request
void http_get(const char *hostname, int port, const char *path) {
    int sockfd;
    struct sockaddr_in server_address;
    struct hostent *host_entry;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    ssize_t bytes_received;

    // Resolve the hostname to an IP address
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr, host_entry->h_addr, host_entry->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Create the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the HTTP GET request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    printf("Response from server:\n");
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the server's response
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }

    // Clean up and close the socket
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    http_get(hostname, port, path);

    return EXIT_SUCCESS;
}