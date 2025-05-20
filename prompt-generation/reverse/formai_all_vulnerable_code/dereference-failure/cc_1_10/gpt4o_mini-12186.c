//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesReceived;

    // Read the response until the server closes the connection
    while ((bytesReceived = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesReceived] = '\0';  // Null terminate the buffer
        printf("%s", buffer);
    }
    
    if (bytesReceived < 0) {
        perror("Failed to read from server");
    }
}

int create_socket(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Failed to resolve hostname");
        exit(EXIT_FAILURE);
    }
    
    // Fill in server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_request(int sockfd, const char *hostname, const char *path) {
    // Buffer to hold the HTTP request
    char request[BUFFER_SIZE];

    // Create the HTTP GET request
    snprintf(request, sizeof(request), 
        "GET %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n\r\n", 
        path, hostname);

    // Send the request
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("Failed to send request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get hostname and path from command line arguments
    const char *hostname = argv[1];
    const char *path = argv[2];
    
    // Create a socket and connect to the server
    int sockfd = create_socket(hostname, 80);

    // Send the HTTP GET request
    send_request(sockfd, hostname, path);

    // Print the server's response
    print_response(sockfd);

    // Close the socket
    close(sockfd);
    
    return 0;
}