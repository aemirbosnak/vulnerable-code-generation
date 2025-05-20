//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Define a structure to represent an HTTP request
typedef struct {
    char *method;
    char *url;
    char *headers;
    char *body;
} HttpRequest;

// Define a structure to represent an HTTP response
typedef struct {
    int status_code;
    char *status_message;
    char *headers;
    char *body;
} HttpResponse;

// Function to initialize an HTTP request
HttpRequest* create_request(const char *method, const char *url, const char *headers, const char *body) {
    HttpRequest *request = (HttpRequest *)malloc(sizeof(HttpRequest));
    request->method = strdup(method);
    request->url = strdup(url);
    request->headers = headers ? strdup(headers) : NULL;
    request->body = body ? strdup(body) : NULL;
    return request;
}

// Function to free the allocated memory for an HTTP request
void free_request(HttpRequest *request) {
    if (request) {
        free(request->method);
        free(request->url);
        if (request->headers) free(request->headers);
        if (request->body) free(request->body);
        free(request);
    }
}

// Function to send the HTTP request and receive the response
HttpResponse* send_request(HttpRequest *request) {
    // Define server address and port (use hardcoded example)
    const char *server_ip = "93.184.216.34"; // Example: example.com
    int port = 80;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP request message
    char request_buffer[1024];
    snprintf(request_buffer, sizeof(request_buffer), "%s %s HTTP/1.1\r\nHost: %s\r\n",
            request->method, request->url, server_ip);
    
    if (request->headers) {
        strncat(request_buffer, request->headers, sizeof(request_buffer) - strlen(request_buffer) - 1);
    }
    strncat(request_buffer, "\r\n", sizeof(request_buffer) - strlen(request_buffer) - 1);
    
    if (request->body) {
        strncat(request_buffer, request->body, sizeof(request_buffer) - strlen(request_buffer) - 1);
    }

    // Send the HTTP request
    send(sock, request_buffer, strlen(request_buffer), 0);

    // Allocate memory for the response
    HttpResponse *response = (HttpResponse *)malloc(sizeof(HttpResponse));
    response->body = NULL;
    char response_buffer[4096];
    int received_size = recv(sock, response_buffer, sizeof(response_buffer) - 1, 0);
    if (received_size > 0) {
        response_buffer[received_size] = '\0';

        // Simple parsing of the response
        sscanf(response_buffer, "HTTP/1.1 %d %[^\r\n]", &response->status_code, response->status_message);
        response->body = strdup(strstr(response_buffer, "\r\n\r\n") + 4); // Get the body after headers
    }

    // Close the socket
    close(sock);
    return response;
}

// Function to free the allocated memory for an HTTP response
void free_response(HttpResponse *response) {
    if (response) {
        free(response->body);
        free(response);
    }
}


int main() {
    // Create an HTTP GET request
    HttpRequest *request = create_request("GET", "/", NULL, NULL);
    
    // Send request and receive response
    HttpResponse *response = send_request(request);
    
    // Display the response
    printf("Status Code: %d\n", response->status_code);
    printf("Status Message: %s\n", response->status_message);
    printf("Response Body:\n%s\n", response->body);
    
    // Free allocated memory
    free_request(request);
    free_response(response);
    
    return 0;
}