//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Define the port number for the HTTP request
#define PORT 80

// Define the buffer size for the HTTP request
#define BUFFER_SIZE 1024

// Function to send an HTTP GET request to the specified URL
int send_http_get_request(char *url)
{
    // Parse the URL into its component parts
    struct sockaddr_in server_addr;
    char *hostname, *path;
    int port;

    if (parse_url(url, &hostname, &path, &port) == -1) {
        perror("Error parsing URL");
        return -1;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error resolving hostname");
        return -1;
    }

    // Create a socket for the HTTP request
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return -1;
    }

    // Send the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Error sending HTTP request");
        return -1;
    }

    // Receive the HTTP response
    char response[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        // Print the HTTP response
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to parse a URL into its component parts
int parse_url(char *url, char **hostname, char **path, int *port)
{
    // Find the scheme separator
    char *scheme_separator = strstr(url, "://");
    if (scheme_separator == NULL) {
        return -1;
    }

    // Find the path separator
    char *path_separator = strchr(url, '/');
    if (path_separator == NULL) {
        return -1;
    }

    // Find the port separator
    char *port_separator = strchr(url, ':');
    if (port_separator != NULL) {
        *port = atoi(port_separator + 1);
    } else {
        *port = 80;
    }

    // Set the hostname
    *hostname = scheme_separator + 3;

    // Set the path
    *path = path_separator;

    return 0;
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the user specified a URL
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Send the HTTP GET request
    if (send_http_get_request(argv[1]) == -1) {
        return 1;
    }

    return 0;
}