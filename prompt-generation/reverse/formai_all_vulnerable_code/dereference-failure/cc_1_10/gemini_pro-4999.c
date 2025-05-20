//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Ephemeral HTTP client

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get host and port
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Resolve host
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "Error: Could not resolve host %s\n", host);
        return EXIT_FAILURE;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)he->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return EXIT_FAILURE;
    }

    // Send HTTP request
    const char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request_buf[256];
    snprintf(request_buf, sizeof(request_buf), request, host);
    if (send(sockfd, request_buf, strlen(request_buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send HTTP request\n");
        return EXIT_FAILURE;
    }

    // Receive HTTP response
    char response_buf[1024];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response_buf, sizeof(response_buf), 0)) > 0) {
        // Print response
        printf("%s", response_buf);
    }
    if (bytes_received == -1) {
        fprintf(stderr, "Error: Could not receive HTTP response\n");
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}