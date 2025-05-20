//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

struct http_request {
    char *method;
    char *path;
    char *version;
    char *headers;
    char *body;
};

struct http_response {
    char *status_code;
    char *status_message;
    char *headers;
    char *body;
};

void parse_http_request(char *request, struct http_request *http_request) {
    // Parse the HTTP method
    char *method = strtok(request, " ");
    http_request->method = strdup(method);

    // Parse the HTTP path
    char *path = strtok(NULL, " ");
    http_request->path = strdup(path);

    // Parse the HTTP version
    char *version = strtok(NULL, "\r\n");
    http_request->version = strdup(version);

    // Parse the HTTP headers
    char *headers = strtok(NULL, "\r\n\r\n");
    http_request->headers = strdup(headers);

    // Parse the HTTP body
    char *body = strtok(NULL, "");
    http_request->body = strdup(body);
}

void parse_http_response(char *response, struct http_response *http_response) {
    // Parse the HTTP status code
    char *status_code = strtok(response, " ");
    http_response->status_code = strdup(status_code);

    // Parse the HTTP status message
    char *status_message = strtok(NULL, "\r\n");
    http_response->status_message = strdup(status_message);

    // Parse the HTTP headers
    char *headers = strtok(NULL, "\r\n\r\n");
    http_response->headers = strdup(headers);

    // Parse the HTTP body
    char *body = strtok(NULL, "");
    http_response->body = strdup(body);
}

void forward_http_request(struct http_request *http_request, int upstream_socket) {
    char *request_string = malloc(MAX_BUFFER_SIZE);
    sprintf(request_string, "%s %s %s\r\n%s\r\n\r\n", http_request->method, http_request->path, http_request->version, http_request->headers);
    send(upstream_socket, request_string, strlen(request_string), 0);
    free(request_string);
}

void receive_http_response(struct http_response *http_response, int upstream_socket) {
    char *response_string = malloc(MAX_BUFFER_SIZE);
    recv(upstream_socket, response_string, MAX_BUFFER_SIZE, 0);
    parse_http_response(response_string, http_response);
    free(response_string);
}

void proxy_http_request(int client_socket, int upstream_socket) {
    // Receive the HTTP request from the client
    char *request_buffer = malloc(MAX_BUFFER_SIZE);
    recv(client_socket, request_buffer, MAX_BUFFER_SIZE, 0);

    // Parse the HTTP request
    struct http_request http_request;
    parse_http_request(request_buffer, &http_request);

    // Forward the HTTP request to the upstream server
    forward_http_request(&http_request, upstream_socket);

    // Receive the HTTP response from the upstream server
    struct http_response http_response;
    receive_http_response(&http_response, upstream_socket);

    // Send the HTTP response to the client
    char *response_string = malloc(MAX_BUFFER_SIZE);
    sprintf(response_string, "%s %s\r\n%s\r\n\r\n%s", http_response.status_code, http_response.status_message, http_response.headers, http_response.body);
    send(client_socket, response_string, strlen(response_string), 0);

    // Free the memory allocated for the HTTP request and response
    free(request_buffer);
    free(http_request.method);
    free(http_request.path);
    free(http_request.version);
    free(http_request.headers);
    free(http_request.body);
    free(http_response.status_code);
    free(http_response.status_message);
    free(http_response.headers);
    free(http_response.body);
    free(response_string);
}

int main(int argc, char **argv) {
    // Create the listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the listening socket to the specified address and port
    struct sockaddr_in listening_address;
    memset(&listening_address, 0, sizeof(listening_address));
    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(8080);
    listening_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listening_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and proxy HTTP requests
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        // Create a socket to connect to the upstream server
        int upstream_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (upstream_socket == -1) {
            perror("socket");
            exit(1);
        }

        // Connect to the upstream server
        struct sockaddr_in upstream_address;
        memset(&upstream_address, 0, sizeof(upstream_address));
        upstream_address.sin_family = AF_INET;
        upstream_address.sin_port = htons(80);
        upstream_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        if (connect(upstream_socket, (struct sockaddr *) &upstream_address, sizeof(upstream_address)) == -1) {
            perror("connect");
            exit(1);
        }

        // Proxy the HTTP request
        proxy_http_request(client_socket, upstream_socket);

        // Close the client socket
        close(client_socket);

        // Close the upstream socket
        close(upstream_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}