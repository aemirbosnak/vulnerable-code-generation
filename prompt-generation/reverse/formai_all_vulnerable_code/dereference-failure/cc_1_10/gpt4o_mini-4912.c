//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_response_headers(char *response) {
    char *header_end = strstr(response, "\r\n\r\n");
    if (header_end) {
        *header_end = '\0'; // Terminate the header at the end of headers section
        printf("Response Headers:\n%s\n", response);
        *header_end = '\r'; // Restore header_end for further processing
    }
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) handle_error("socket");

    // Resolve hostname to IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return EXIT_FAILURE;
    }

    // Set up server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        handle_error("connect");

    // Prepare HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", hostname);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0)
        handle_error("send");

    // Read response
    char response[BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    int total_bytes_received = 0;

    while (1) {
        int bytes_received = recv(sockfd, response + total_bytes_received, sizeof(response) - total_bytes_received - 1, 0);
        if (bytes_received < 0) {
            handle_error("recv");
            break;
        } else if (bytes_received == 0) {
            break; // Connection closed
        }
        total_bytes_received += bytes_received;
    }

    // Null terminate the response to make it a string
    response[total_bytes_received] = '\0';

    // Print the response headers
    print_response_headers(response);

    // Print the response body
    printf("Response Body:\n%s\n", strstr(response, "\r\n\r\n") + 4); // Skip headers

    // Clean up and close socket
    close(sockfd);
    return EXIT_SUCCESS;
}