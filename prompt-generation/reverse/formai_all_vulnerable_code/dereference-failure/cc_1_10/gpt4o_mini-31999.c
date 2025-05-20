//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096

// Function to create a TCP socket and connect it to the specified host and port
int create_connection(const char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    // Convert IPv4 and IPv6 addresses from text to binary
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        struct hostent *he = gethostbyname(host);
        if (he == NULL) {
            perror("gethostbyname failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to create the HTTP GET request
char *create_http_request(const char *path) {
    const char *template = "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char *request = malloc(BUFFER_SIZE);
    snprintf(request, BUFFER_SIZE, template, path, "example.com");  // change 'example.com' to appropriate host if needed
    return request;
}

// Function to read the HTTP response from the server
void read_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read response and print to stdout
    while ((bytes_read = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_read < 0) {
        perror("Read error");
    }
}

// Main function to execute the HTTP client
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // Create a connection
    int sockfd = create_connection(host, 80);

    // Create HTTP request
    char *request = create_http_request(path);
    
    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        free(request);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Free the allocated request memory
    free(request);

    // Read and print the HTTP response
    read_http_response(sockfd);

    // Close the socket connection
    close(sockfd);

    return 0;
}