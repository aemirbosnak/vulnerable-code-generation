//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Maximum size of the HTTP request
#define MAX_REQUEST_SIZE 4096

// Maximum size of the HTTP response
#define MAX_RESPONSE_SIZE 10240

// The HTTP GET request
const char *GET_REQUEST = "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";

// The HTTP response status codes
const char *HTTP_STATUS_CODES[] = {
    "200 OK",
    "400 Bad Request",
    "404 Not Found",
    "500 Internal Server Error"
};

// The HTTP content types
const char *HTTP_CONTENT_TYPES[] = {
    "text/html",
    "application/json",
    "image/jpeg",
    "image/png"
};

// The main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return 1;
    }

    // Parse the host and path from the command line arguments
    char *host = argv[1];
    char *path = argv[2];

    // Create a socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", host);
        return 1;
    }

    // Create the socket address
    struct sockaddr_in sockaddr_in;
    memset(&sockaddr_in, 0, sizeof(sockaddr_in));
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(80);
    memcpy(&sockaddr_in.sin_addr, hostent->h_addr_list[0], hostent->h_length);

    // Connect to the server
    if (connect(socketfd, (struct sockaddr *)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
        perror("connect");
        return 1;
    }

    // Create the HTTP request
    char request[MAX_REQUEST_SIZE];
    snprintf(request, MAX_REQUEST_SIZE, GET_REQUEST, path, host);

    // Send the HTTP request
    if (send(socketfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the HTTP response
    char response[MAX_RESPONSE_SIZE];
    int response_size = recv(socketfd, response, MAX_RESPONSE_SIZE, 0);
    if (response_size == -1) {
        perror("recv");
        return 1;
    }

    // Parse the HTTP response
    char *status_line = strtok(response, "\r\n");
    char *status_code = strtok(NULL, " ");
    char *status_message = strtok(NULL, "\r\n");

    // Print the HTTP response status line
    printf("%s\n", status_line);

    // Check the HTTP response status code
    int status_code_int = atoi(status_code);
    if (status_code_int != 200) {
        fprintf(stderr, "HTTP error: %s\n", HTTP_STATUS_CODES[status_code_int]);
        return 1;
    }

    // Parse the HTTP response headers
    char *headers = strtok(NULL, "\r\n\r\n");
    while (headers != NULL) {
        char *header = strtok(headers, ": ");
        char *value = strtok(NULL, "\r\n");

        printf("%s: %s\n", header, value);

        headers = strtok(NULL, "\r\n\r\n");
    }

    // Print a newline
    printf("\n");

    // Parse the HTTP response body
    char *body = strtok(NULL, "");
    while (body != NULL) {
        printf("%s", body);

        body = strtok(NULL, "");
    }

    // Close the socket
    close(socketfd);

    return 0;
}