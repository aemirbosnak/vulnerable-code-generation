//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

void print_response(const char *response) {
    printf("Response:\n%s\n", response);
}

void create_http_request(const char *host, const char *path, char *request) {
    sprintf(request,
            "GET %s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n"
            "\r\n",
            path, host);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    struct hostent *server;
    struct sockaddr_in server_addr;
    int sockfd, port = 80;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received, total_bytes_received = 0;

    // Get the server details
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return EXIT_FAILURE;
    }

    // Set up the server address structure
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Create HTTP request
    create_http_request(hostname, path, request);
    
    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the response
    memset(response, 0, BUFFER_SIZE);
    while ((bytes_received = recv(sockfd, response + total_bytes_received, BUFFER_SIZE - total_bytes_received - 1, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    
    if (bytes_received < 0) {
        perror("Error receiving response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Null-terminate the response
    response[total_bytes_received] = '\0';
    
    // Print the response
    print_response(response);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}