//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 80

void execute_request(int sockfd, const char *request) {
    // Send the HTTP request to the server
    send(sockfd, request, strlen(request), 0);

    // Buffer to hold the response
    char response[BUFFER_SIZE];
    int bytes_received;

    // Receive the response in a loop
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response string
        printf("%s", response); // Print the response
    }
}

void create_request(const char *host, const char *path) {
    // Create the request string
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n",
             path, host);

    // Resolve the host to an IP address
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        return;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr); // Copy the address

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        close(sockfd);
        return;
    }

    // Execute the HTTP request
    execute_request(sockfd, request);

    // Close the socket
    close(sockfd);
}

void parse_url(const char *url, char *host, char *path) {
    // Parse the URL to extract the host and path
    const char *prefix = "http://";
    if (strncmp(url, prefix, strlen(prefix)) == 0) {
        url += strlen(prefix); // Skip the "http://"
    }

    // Find the first '/' in the URL which separates the host from the path
    const char *path_start = strchr(url, '/');
    if (path_start) {
        strncpy(host, url, path_start - url); // Copy host
        host[path_start - url] = '\0'; // Null-terminate the host string
        strcpy(path, path_start); // Copy path
    } else {
        strcpy(host, url); // No path, just the host
        path[0] = '/'; // Default path
        path[1] = '\0'; // Null-terminate
    }
}

void http_request(const char *url) {
    // Host and path will hold the parsed components of the URL
    char host[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    parse_url(url, host, path);

    // Create and execute the request
    create_request(host, path);
}

void recursive_http_requests(const char *url, int depth) {
    if (depth <= 0) {
        return;
    }

    printf("HTTP request for: %s, Depth: %d\n", url, depth);
    http_request(url);

    // To simulate a recursive exploration, change the url slightly
    char new_url[BUFFER_SIZE];
    snprintf(new_url, sizeof(new_url), "%s?page=%d", url, depth);
    
    // Recursive call
    recursive_http_requests(new_url, depth - 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <URL> <depth>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];
    int depth = atoi(argv[2]);
    recursive_http_requests(url, depth);

    return EXIT_SUCCESS;
}