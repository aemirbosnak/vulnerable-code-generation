//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Failed to create socket");
    }

    // Configure server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        die("Invalid address or address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    // Prepare HTTP GET request
    const char *request_template = "GET / HTTP/1.1\r\n"
                                   "Host: %s\r\n"
                                   "Connection: close\r\n\r\n";
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), request_template, hostname);

    // Send HTTP GET request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Failed to send request");
    }

    // Receive response
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", response);          // Output the response
    }

    if (bytes_received < 0) {
        die("Failed to receive response");
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}