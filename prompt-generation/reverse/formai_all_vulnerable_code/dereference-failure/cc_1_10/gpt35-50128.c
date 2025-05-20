//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024 // Maximum buffer size

// Function to create a socket and connect to a host
int create_socket_and_connect(char *host, int port) {
    struct sockaddr_in server_addr;
    int socket_fd;

    // Create a socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    return socket_fd;
}

// Function to send HTTP request
void send_http_request(int socket_fd, char *host, char *path) {
    char request[BUFFER_SIZE];

    // Construct HTTP request 
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // Send HTTP request to the server
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive HTTP response
char *receive_http_response(int socket_fd) {
    char *response = malloc(BUFFER_SIZE);
    int bytes_received;

    // Receive HTTP response from the server
    if ((bytes_received = recv(socket_fd, response, BUFFER_SIZE, 0)) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Add null terminator at the end of response string
    response[bytes_received] = '\0';

    return response;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[2]);
    char *host = argv[1];
    char *path = "/"; // default path

    int socket_fd = create_socket_and_connect(host, port);
    send_http_request(socket_fd, host, path);
    char *response = receive_http_response(socket_fd);

    printf("HTTP response:\n%s", response);

    free(response);
    close(socket_fd);
    exit(EXIT_SUCCESS);
}