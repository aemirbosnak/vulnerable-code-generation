//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *host;
    char *path;
    int port;
} http_request_t;

void print_usage(char *prog_name) {
    printf("Usage: %s <URL>\n", prog_name);
}

bool parse_url(const char *url, http_request_t *request) {
    char *url_copy = strdup(url); // Duplicate the URL string
    if (!url_copy) {
        return false;
    }

    char *protocol_end = strstr(url_copy, "://");
    if (protocol_end) {
        *protocol_end = '\0'; // Split protocol off
        protocol_end += 3; // Move past "://"
    } else {
        protocol_end = url_copy; // No protocol specified
    }

    // Extract host
    char *host_end = strchr(protocol_end, '/');
    if (host_end) {
        *host_end = '\0'; // Terminate host string
        request->path = strdup(host_end); // Save the path
    } else {
        request->path = strdup("/"); // Default path
    }
    request->host = strdup(protocol_end); // Save the host

    // Default port for HTTP
    request->port = 80;

    // Check if host has a port specified
    char *port_str = strchr(request->host, ':');
    if (port_str) {
        *port_str = '\0'; // Terminate host string
        request->port = atoi(port_str + 1); // Set port
    }

    free(url_copy); // Clean up
    return true;
}

void free_request(http_request_t *request) {
    free(request->host);
    free(request->path);
}

int create_http_request(const http_request_t *request, char *out_request) {
    return sprintf(out_request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", 
                   request->path, request->host);
}

int send_http_request(const http_request_t *request) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request_buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    struct hostent *server = gethostbyname(request->host);
    if (server == NULL) {
        perror("No such host");
        close(sockfd);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(request->port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Establish connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    // Create HTTP request
    create_http_request(request, request_buffer);

    // Send HTTP request
    send(sockfd, request_buffer, strlen(request_buffer), 0);

    // Receive response
    char response_buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, response_buffer, sizeof(response_buffer) - 1, 0)) > 0) {
        response_buffer[bytes_received] = '\0'; // Null terminate
        printf("%s", response_buffer); // Print response
    }

    // Clean up
    if (bytes_received < 0) {
        perror("Error receiving data");
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    http_request_t request;
    if (!parse_url(argv[1], &request)) {
        fprintf(stderr, "Failed to parse URL: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int result = send_http_request(&request);
    free_request(&request);
    return result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}