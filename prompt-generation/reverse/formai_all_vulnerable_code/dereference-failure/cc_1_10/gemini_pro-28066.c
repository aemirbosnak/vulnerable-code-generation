//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// Define the maximum length of the HTTP request and response
#define MAX_REQUEST_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096

// Define the HTTP methods
#define METHOD_GET "GET"
#define METHOD_POST "POST"
#define METHOD_PUT "PUT"
#define METHOD_DELETE "DELETE"

// Define the HTTP status codes
#define STATUS_OK 200
#define STATUS_CREATED 201
#define STATUS_ACCEPTED 202
#define STATUS_BAD_REQUEST 400
#define STATUS_UNAUTHORIZED 401
#define STATUS_FORBIDDEN 403
#define STATUS_NOT_FOUND 404
#define STATUS_INTERNAL_SERVER_ERROR 500

// Create a socket and connect to the specified host and port
int create_socket(const char *host, const char *port) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;

    // Set the address family to IPv4 or IPv6
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get the address information for the specified host and port
    s = getaddrinfo(host, port, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    // Iterate over the address information and try to connect to each address
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        // Create a socket
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1) {
            perror("socket");
            continue;
        }

        // Connect to the specified address
        s = connect(sfd, rp->ai_addr, rp->ai_addrlen);
        if (s == -1) {
            perror("connect");
            close(sfd);
            continue;
        }

        // Break out of the loop if the connection was successful
        break;
    }

    // Free the address information
    freeaddrinfo(result);

    // Return the socket file descriptor
    return sfd;
}

// Send an HTTP request to the specified socket
int send_request(int sfd, const char *method, const char *path, const char *body) {
    char request[MAX_REQUEST_LENGTH];

    // Build the HTTP request
    snprintf(request, MAX_REQUEST_LENGTH, "%s %s HTTP/1.1\r\n", method, path);
    snprintf(request, MAX_REQUEST_LENGTH, "%sHost: %s\r\n", request, "www.example.com");
    snprintf(request, MAX_REQUEST_LENGTH, "%sContent-Length: %lu\r\n", request, strlen(body));
    snprintf(request, MAX_REQUEST_LENGTH, "%s\r\n", request);
    snprintf(request, MAX_REQUEST_LENGTH, "%s%s", request, body);

    // Send the HTTP request
    ssize_t bytes_sent = send(sfd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        perror("send");
        return -1;
    }

    // Return the number of bytes sent
    return bytes_sent;
}

// Receive an HTTP response from the specified socket
int receive_response(int sfd, char *response, size_t response_length) {
    ssize_t bytes_received = recv(sfd, response, response_length, 0);
    if (bytes_received == -1) {
        perror("recv");
        return -1;
    }

    // Return the number of bytes received
    return bytes_received;
}

// Parse the HTTP response and return the status code
int parse_status_code(const char *response) {
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        return -1;
    }

    char *status_code_string = strtok(status_line, " ");
    if (status_code_string == NULL) {
        return -1;
    }

    int status_code = atoi(status_code_string);
    return status_code;
}

// Print the HTTP response
void print_response(const char *response) {
    printf("%s", response);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        return -1;
    }

    // Get the host, port, and path from the command line arguments
    const char *host = argv[1];
    const char *port = argv[2];
    const char *path = argv[3];

    // Create a socket and connect to the specified host and port
    int sfd = create_socket(host, port);
    if (sfd == -1) {
        return -1;
    }

    // Send an HTTP GET request to the specified path
    int bytes_sent = send_request(sfd, METHOD_GET, path, "");
    if (bytes_sent == -1) {
        close(sfd);
        return -1;
    }

    // Receive the HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received = receive_response(sfd, response, MAX_RESPONSE_LENGTH);
    if (bytes_received == -1) {
        close(sfd);
        return -1;
    }

    // Parse the HTTP response status code
    int status_code = parse_status_code(response);
    if (status_code == -1) {
        fprintf(stderr, "Error parsing HTTP response status code\n");
        close(sfd);
        return -1;
    }

    // Print the HTTP response
    print_response(response);

    // Close the socket
    close(sfd);

    return 0;
}