//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Custom HTTP client function
long custom_http_client(const char *hostname, const char *port, const char *path) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Get the host IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        return -1;
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Send the HTTP request
    char request[512];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("write");
        return -1;
    }

    // Receive the HTTP response
    char response[4096];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("recv");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", argv[0]);
        return 1;
    }

    // Parse the command line arguments
    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *path = argv[3];

    // Make the HTTP request
    if (custom_http_client(hostname, port, path) < 0) {
        return 1;
    }

    return 0;
}