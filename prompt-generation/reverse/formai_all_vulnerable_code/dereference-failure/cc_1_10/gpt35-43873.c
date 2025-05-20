//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h> 

#define HTTP_PORT 80
#define BUFFER_SIZE 4096

// Define structure for HTTP response
typedef struct {
    char *status_code;
    char *headers;
    char *body;
} http_response;

// Function for sending HTTP request to server
int send_http_request(int client_socket, const char *hostname, const char *path) {
    // Create HTTP request message
    char request_message[BUFFER_SIZE];
    snprintf(request_message, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send request to server
    int bytes_sent = send(client_socket, request_message, strlen(request_message), 0);
    if (bytes_sent <= 0) {
        perror("Failed to send HTTP request to server");
        return -1;
    }

    return 0;
}

// Function for receiving HTTP response from server
http_response receive_http_response(int client_socket) {
    http_response response = {.status_code = NULL, .headers = NULL, .body = NULL};

    // Create buffer to store response from server
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received <= 0) {
        perror("Failed to receive HTTP response from server");
        return response;
    }

    // Parse response message
    char *status_code = strtok(buffer, " \r\n");
    char *headers = strstr(buffer, "\r\n") + 2;
    char *body = strstr(headers, "\r\n\r\n") + 4;

    // Allocate memory for response fields
    response.status_code = (char *) malloc(strlen(status_code) + 1);
    response.headers = (char *) malloc(strlen(headers) + 1);
    response.body = (char *) malloc(bytes_received - (body - buffer) + 1);

    // Copy response fields to allocated memory
    strncpy(response.status_code, status_code, strlen(status_code) + 1);
    strncpy(response.headers, headers, strlen(headers) + 1);
    strncpy(response.body, body, bytes_received - (body - buffer) + 1);

    return response;
}

int main(int argc, char *argv[]) {
    int client_socket;
    struct hostent *server_info;
    struct sockaddr_in server_address;

    if (argc < 2) {
        printf("Usage: ./http_client <hostname> [<path>]\n");
        return 0;
    }

    const char *hostname = argv[1];
    const char *path = argv[2] ? argv[2] : "/";

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Failed to create socket");
        return -1;
    }

    // Resolve hostname to IP address
    server_info = gethostbyname(hostname);
    if (server_info == NULL) {
        perror("Failed to resolve hostname");
        return -1;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(HTTP_PORT);
    memcpy(&server_address.sin_addr, server_info->h_addr_list[0], server_info->h_length);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        return -1;
    }

    // Send HTTP request to server
    if (send_http_request(client_socket, hostname, path) == -1) {
        return -1;
    }

    // Receive HTTP response from server
    http_response response = receive_http_response(client_socket);

    // Print HTTP response
    printf("Status code: %s\nHeaders:\n%s\nBody:\n%s\n", response.status_code, response.headers, response.body);

    // Free memory allocated for response fields
    free(response.status_code);
    free(response.headers);
    free(response.body);

    // Close socket
    close(client_socket);

    return 0;
}