//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RESPONSE_SIZE 4096

// Function to handle any errors that occur during the socket connection
void error_handler(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int socket_fd, port, bytes_received;
    struct sockaddr_in server_addr;
    char *host, *request, response[MAX_RESPONSE_SIZE];

    // Handle incorrect command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    port = atoi(argv[2]);

    // Create a new socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error_handler("Error creating socket");
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error_handler("inet_pton error: Invalid address");
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error_handler("Error connecting to server");
    }

    // Prepare and send HTTP request
    request = "GET / HTTP/1.1\r\nHost: ";
    request = strcat(request, host);
    request = strcat(request, "\r\n\r\n");
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        error_handler("Error sending request");
    }

    // Receive response and store it in response variable
    bytes_received = recv(socket_fd, response, MAX_RESPONSE_SIZE, 0);
    if (bytes_received < 0) {
        error_handler("Error receiving response");
    }

    // Null-terminate response
    response[bytes_received] = '\0';

    // Print out response
    printf("%s", response);

    // Close socket
    close(socket_fd);

    return 0;
}