//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 8192
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char request[MAX_REQUEST_SIZE], response[MAX_REQUEST_SIZE];
    int bytes_sent, bytes_received, total_bytes_received = 0;

    // Check if enough arguments provided
    if (argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Parse the URL to get server name and path
    char *url = argv[1];
    char server_name[100], path[200];
    sscanf(url, "http://%99[^/]/%199[^\r\n]", server_name, path);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Get server IP address
    server = gethostbyname(server_name);
    if (server == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", server_name);
        return 1;
    }

    // Set server address parameters
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);
    server_addr.sin_port = htons(DEFAULT_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Construct HTTP request
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, server_name);

    // Send HTTP request
    bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error sending request");
        return 1;
    }

    // Receive HTTP response
    while ((bytes_received = recv(sockfd, response + total_bytes_received, MAX_REQUEST_SIZE - total_bytes_received - 1, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    // Add null terminator to response buffer
    response[total_bytes_received] = '\0';

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}