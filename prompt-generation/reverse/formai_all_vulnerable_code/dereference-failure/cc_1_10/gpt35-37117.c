//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define DEFAULT_PORT "80"
#define MAX_HEADER_SIZE 1024
#define MAX_RESPONSE_SIZE 1024

/**
 * Sends the HTTP request to the server
 */
bool send_request(int client_socket, const char* request) {
    int num_bytes_sent = send(client_socket, request, strlen(request), 0);
    if (num_bytes_sent == -1) {
        perror("Error sending request");
        return false;
    }

    return true;
}

/**
 * Receives the HTTP response from the server
 */
bool receive_response(int client_socket) {
    char response[MAX_RESPONSE_SIZE];
    int num_bytes_received = recv(client_socket, response, MAX_RESPONSE_SIZE - 1, 0);
    if (num_bytes_received == -1) {
        perror("Error receiving response");
        return false;
    }

    response[num_bytes_received] = '\0';
    printf("Response:\n%s", response);

    return true;
}

/**
 * Builds the HTTP request string based on the inputs
 */
char* build_request(const char* host, const char* port, const char* path) {
    char* request = malloc(MAX_HEADER_SIZE);

    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    sprintf(request + strlen(request), "Host: %s:%s\r\n", host, port);
    sprintf(request + strlen(request), "Connection: close\r\n\r\n");

    return request;
}

int main(int argc, char* argv[]) {
    // Get the host, port and path from command line inputs
    if (argc < 2) {
        printf("Usage: %s <host> <path> [port]\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    const char* host = argv[1];
    const char* path = argc > 2 ? argv[2] : "/";
    const char* port = argc > 3 ? argv[3] : DEFAULT_PORT;

    // Resolve the host name to an IP address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo* server_info;
    int error = getaddrinfo(host, port, &hints, &server_info);
    if (error != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct addrinfo* rp;
    int client_socket;
    for (rp = server_info; rp != NULL; rp = rp->ai_next) {
        client_socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (client_socket == -1) {
            continue;
        }

        if (connect(client_socket, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }

        close(client_socket);
    }

    if (rp == NULL) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(server_info);

    // Build the HTTP request and send it to the server
    char* request = build_request(host, port, path);
    if (!send_request(client_socket, request)) {
        exit(EXIT_FAILURE);
    }

    // Receive the HTTP response from the server
    if (!receive_response(client_socket)) {
        exit(EXIT_FAILURE);
    }

    close(client_socket);
    free(request);

    return EXIT_SUCCESS;
}