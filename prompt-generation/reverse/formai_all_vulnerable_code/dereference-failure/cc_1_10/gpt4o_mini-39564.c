//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFFER_SIZE 4096

void parse_url(const char *url, char *hostname, char *path) {
    char *start = strstr(url, "http://");

    if (start) {
        start += strlen("http://");
    } else {
        start = (char *)url;
    }

    char *path_separator = strchr(start, '/');

    if (path_separator) {
        strncpy(hostname, start, path_separator - start);
        hostname[path_separator - start] = '\0';
        strcpy(path, path_separator); // copy the path with '/'
    } else {
        strcpy(hostname, start);
        path[0] = '/';
        path[1] = '\0'; // root path
    }
}

void get_http_response(const char *url) {
    char hostname[256];
    char path[256];
    parse_url(url, hostname, path);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server struct
    struct hostent *server = gethostbyname(hostname);
    if (!server) {
        fprintf(stderr, "Error: No such host: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Create and send HTTP GET request
    char request[512];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    write(sockfd, request, strlen(request));

    // Read and display the response
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = read(sockfd, response, sizeof(response) - 1)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate
        printf("%s", response);
    }

    // Cleanup
    close(sockfd);
}

int main() {
    char url[512];

    // Imaginative title for the HTTP Client
    printf("Welcome to the Whimsical HTTP Client!\n");
    printf("Please enter the URL you wish to explore (starting with http://): ");
    fgets(url, sizeof(url), stdin);

    // Remove trailing newline character
    url[strcspn(url, "\n")] = 0;

    // Make a request to the entered URL
    get_http_response(url);

    return 0;
}