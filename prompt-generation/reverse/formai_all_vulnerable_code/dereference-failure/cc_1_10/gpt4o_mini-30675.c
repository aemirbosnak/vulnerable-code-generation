//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Structure to hold the HTTP request details
typedef struct {
    char *host;
    char *path;
    char *request_type;
} HttpRequest;

// Function to create and set up the HTTP request
HttpRequest *create_request(const char *host, const char *path, const char *request_type) {
    HttpRequest *request = malloc(sizeof(HttpRequest));
    request->host = strdup(host);
    request->path = strdup(path);
    request->request_type = strdup(request_type);
    return request;
}

// Function to send the HTTP request and receive the response
void send_http_request(HttpRequest *request) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char buffer[BUFFER_SIZE];

    // Resolve the host name
    host_entry = gethostbyname(request->host);
    if (!host_entry) {
        fprintf(stderr, "Could not resolve host: %s\n", request->host);
        return;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        return;
    }

    // Create the HTTP request string
    char request_str[BUFFER_SIZE];
    snprintf(request_str, sizeof(request_str),
             "%s %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             request->request_type, request->path, request->host);

    // Send the HTTP request
    send(sockfd, request_str, strlen(request_str), 0);

    // Receive the response
    printf("Response:\n");
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close the socket
    close(sockfd);
}

// Clean up the HTTP request structure
void free_request(HttpRequest *request) {
    if (request) {
        free(request->host);
        free(request->path);
        free(request->request_type);
        free(request);
    }
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <path> <request_type>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create and send the HTTP request
    HttpRequest *request = create_request(argv[1], argv[2], argv[3]);
    send_http_request(request);

    // Clean up resources
    free_request(request);

    return 0;
}