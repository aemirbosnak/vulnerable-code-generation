//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Recursive function to build the HTTP request.
char *build_http_request(const char *hostname, const char *path) {
    // Allocate memory for the request.
    char *request = malloc(BUF_SIZE);

    // Build the request header.
    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    sprintf(request, "%sHost: %s\r\n", request, hostname);
    sprintf(request, "%sConnection: close\r\n", request);
    sprintf(request, "%s\r\n", request);

    // Return the request.
    return request;
}

// Recursive function to send the HTTP request.
int send_http_request(int sockfd, const char *request) {
    // Send the request.
    int n = send(sockfd, request, strlen(request), 0);
    if (n < 0) {
        perror("send");
        return -1;
    }

    // Return the number of bytes sent.
    return n;
}

// Recursive function to receive the HTTP response.
char *receive_http_response(int sockfd) {
    // Allocate memory for the response.
    char *response = malloc(BUF_SIZE);

    // Receive the response.
    int n = recv(sockfd, response, BUF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        return NULL;
    }

    // Return the response.
    return response;
}

// Recursive function to parse the HTTP response.
char *parse_http_response(char *response) {
    // Find the start of the body.
    char *body = strstr(response, "\r\n\r\n");
    if (body == NULL) {
        return NULL;
    }

    // Return the body.
    return body + 4;
}

// Recursive function to print the HTTP response.
void print_http_response(char *response) {
    // Print the response.
    printf("%s", response);
}

// Recursive function to main.
int main(int argc, char **argv) {
    // Check the arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname path\n", argv[0]);
        return 1;
    }

    // Get the hostname and path.
    const char *hostname = argv[1];
    const char *path = argv[2];

    // Build the HTTP request.
    char *request = build_http_request(hostname, path);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server.
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request.
    int n = send_http_request(sockfd, request);
    if (n < 0) {
        return 1;
    }

    // Receive the HTTP response.
    char *response = receive_http_response(sockfd);
    if (response == NULL) {
        return 1;
    }

    // Parse the HTTP response.
    char *body = parse_http_response(response);
    if (body == NULL) {
        return 1;
    }

    // Print the HTTP response.
    print_http_response(body);

    // Close the socket.
    close(sockfd);

    // Free the memory.
    free(request);
    free(response);

    // Return 0.
    return 0;
}