//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

struct http_response {
    int status_code;
    char *headers;
    char *body;
};

struct http_response *make_http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    // Get the host address
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Could not resolve hostname");
        return NULL;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return NULL;
    }

    // Fill server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    server_addr.sin_port = htons(80);  // HTTP runs on port 80

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        close(sockfd);
        return NULL;
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sockfd, request, strlen(request), 0);

    // Read server response
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving response");
        close(sockfd);
        return NULL;
    }
    response[bytes_received] = '\0';  // Null-terminate response

    // Close the socket
    close(sockfd);

    // Create and populate http_response struct
    struct http_response *resp = malloc(sizeof(struct http_response));
    if (!resp) {
        perror("Memory allocation failed");
        return NULL;
    }

    // Parse the response
    char *header_end = strstr(response, "\r\n\r\n");
    if (header_end == NULL) {
        perror("Invalid HTTP response");
        free(resp);
        return NULL;
    }

    // Split headers and body
    *header_end = '\0';  // Terminate headers
    resp->headers = strdup(response);  // Duplicate header string
    resp->body = strdup(header_end + 4);  // Get body after the headers

    // Parse status code from first line of response
    sscanf(resp->headers, "HTTP/1.1 %d", &resp->status_code);

    return resp;
}

void free_http_response(struct http_response *resp) {
    if (resp) {
        free(resp->headers);
        free(resp->body);
        free(resp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    
    struct http_response *response = make_http_request(hostname, path);
    if (response) {
        printf("Status Code: %d\n", response->status_code);
        printf("Headers:\n%s\n", response->headers);
        printf("Body:\n%s\n", response->body);
        free_http_response(response);
    } else {
        fprintf(stderr, "Failed to make HTTP request.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}