//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>      // Standard Input and Output
#include <stdlib.h>     // Standard Library
#include <string.h>     // String manipulations
#include <unistd.h>     // Symbolic Constants
#include <sys/types.h>  // Data Types
#include <sys/socket.h> // Networking
#include <netinet/in.h> // Internet Addresses
#include <arpa/inet.h>  // Definitions for Internet Operations
#include <netdb.h>      // Hostname Resolution

// Function prototypes
void error(const char *msg);
void http_get_request(const char *hostname, const char *path);
void parse_response(const char *response);

int main(int argc, char *argv[]) {
    // Check for proper arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Make the HTTP GET request
    http_get_request(hostname, path);

    return 0;
}

// Function to print the error and exit
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to perform the HTTP GET request
void http_get_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    const int port = 80; // HTTP port

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get host information
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Prepare the HTTP GET request message
    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request
    int n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    char response[4096];
    bzero(response, sizeof(response));

    // Read the response
    n = read(sockfd, response, sizeof(response) - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Parse and display the response
    parse_response(response);

    // Close the socket
    close(sockfd);
}

// Function to parse and print the HTTP response
void parse_response(const char *response) {
    // Split the response headers and body
    const char *body_start = strstr(response, "\r\n\r\n");
    if (body_start) {
        body_start += 4; // Skip the headers
        printf("Response body:\n%s\n", body_start);
    } else {
        printf("Invalid HTTP response.\n");
    }
}