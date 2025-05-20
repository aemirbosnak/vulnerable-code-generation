//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: retro
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

void http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get server IP address
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Set up the server address structure
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Create the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request
    if (write(sockfd, request, strlen(request)) < 0) {
        error("ERROR writing to socket");
    }

    // Read the response
    char response[BUFFER_SIZE];
    int bytes_read;

    printf("Response:\n\n");
    while ((bytes_read = read(sockfd, response, BUFFER_SIZE - 1)) > 0) {
        response[bytes_read] = '\0'; // Null terminate the string
        printf("%s", response);
    }

    if (bytes_read < 0) {
        error("ERROR reading from socket");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_request(hostname, path);

    return 0;
}