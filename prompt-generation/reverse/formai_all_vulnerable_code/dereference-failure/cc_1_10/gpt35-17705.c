//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RESPONSE_SIZE 1024
#define MAX_HEADER_SIZE 512

typedef struct {
    int status_code;
    char *body;
} HttpResponse;

// Sends an HTTP request to the given address and returns the response
HttpResponse send_http_request(char *address, char *method, char *path, char *headers) {
    int port = 80;

    // Parse the address to get the host and port
    char *host_and_port = strtok(address, ":");
    char *port_str = strtok(NULL, ":");
    if (port_str != NULL) {
        port = atoi(port_str);
    }

    // Resolve the host address
    struct hostent *he;
    if ((he = gethostbyname(host_and_port)) == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", host_and_port);
        exit(1);
    }

    // Create a socket and connect to the server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(port);
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Could not connect to host: %s\n", host_and_port);
        exit(1);
    }

    // Build the HTTP request string
    char request[MAX_HEADER_SIZE];
    snprintf(request, sizeof(request), "%s %s HTTP/1.1\r\nHost: %s\r\n%s\r\n", method, path, host_and_port, headers);

    // Send the request to the server
    send(socket_fd, request, strlen(request), 0);

    // Read the response from the server
    char response_body[MAX_RESPONSE_SIZE];
    int response_size = 0;
    char buffer[MAX_RESPONSE_SIZE];
    int bytes_received;
    bool headers_complete = false;
    while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0)) > 0) {
        // Find the end of the response headers
        if (!headers_complete) {
            char *end_of_headers = strstr(buffer, "\r\n\r\n");
            if (end_of_headers != NULL) {
                headers_complete = true;

                // Copy the response body
                memcpy(response_body, end_of_headers + 4, bytes_received - (end_of_headers - buffer) - 4);
                response_size += bytes_received - (end_of_headers - buffer) - 4;

                // Find the status code in the headers
                char *status_line = strtok(buffer, "\r\n");
                char *status_code_str = strtok(NULL, " ");
                int status_code = atoi(status_code_str);

                // Allocate and populate the HttpResponse struct
                char *body = malloc(response_size + 1);
                memcpy(body, response_body, response_size);
                body[response_size] = '\0';
                HttpResponse response = { status_code, body };
                return response;
            }
        }

        // Copy the response data to the response body
        memcpy(response_body + response_size, buffer, bytes_received);
        response_size += bytes_received;
    }

    // Return an empty response if no data received
    char *body = malloc(1);
    body[0] = '\0';
    HttpResponse response = { -1, body };
    return response;
}

int main() {
    // Send a GET request to the specified URL
    char *url = "http://example.com";
    char *method = "GET";
    char *path = "/";
    char *headers = "";
    HttpResponse response = send_http_request(url, method, path, headers);

    // Print the response body
    printf("%s", response.body);

    // Free the allocated memory
    free(response.body);

    return 0;
}