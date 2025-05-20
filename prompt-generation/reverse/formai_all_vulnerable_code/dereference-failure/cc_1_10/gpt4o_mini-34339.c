//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void httpRequest(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Get the server's DNS entry
    server = gethostbyname(hostname);
    if (server == NULL) 
        error("ERROR, no such host");

    // Set up the server address struct
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;    
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80); // HTTP port

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    // Prepare and send the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    write(sockfd, request, strlen(request));

    // Read the response
    char response[BUFFER_SIZE];
    int bytes;
    printf("\nResponse from %s:\n", hostname);
    
    while ((bytes = read(sockfd, response, sizeof(response) - 1)) > 0) {
        response[bytes] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (bytes < 0)
        error("ERROR reading response");

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s http://example.com\n", argv[0]);
        exit(1);
    }

    // Parse the URL
    char *url = argv[1];
    char *hostname = NULL;
    char *path = NULL;

    if (strncmp(url, "http://", 7) == 0) {
        hostname = strtok(url + 7, "/"); // Get the hostname
        path = strtok(NULL, "");          // Get the path
        if (path == NULL) {
            path = "/"; // default path
        }
    } else {
        fprintf(stderr, "Invalid URL. Only http:// is supported.\n");
        exit(1);
    }

    // If we have a hostname, let's send a request
    if (hostname) {
        httpRequest(hostname, path);
    } else {
        fprintf(stderr, "Hostname extraction failed.\n");
        exit(1);
    }

    return 0;
}