//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the HTTP request template.
char *http_request_template =
    "GET / HTTP/1.1\r\n"
    "Host: %s\r\n"
    "Connection: close\r\n"
    "\r\n";

// Function to send an HTTP request to a server.
int send_http_request(char *host, int port) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send the HTTP request.
    char *request = malloc(strlen(http_request_template) + strlen(host) + 1);
    sprintf(request, http_request_template, host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        free(request);
        close(sockfd);
        return -1;
    }
    free(request);

    // Receive the HTTP response.
    char response[4096];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Print the HTTP response.
    printf("%s", response);

    // Close the socket.
    close(sockfd);

    return 0;
}

// Main function.
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    if (send_http_request(host, port) == -1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}