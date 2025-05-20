//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to resolve a hostname to an IP address
unsigned long resolve_hostname(const char *hostname) {
    struct hostent *host;
    host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        exit(1);
    }
    return *(unsigned long *)host->h_addr_list[0];
}

// Function to send an HTTP GET request to a server
char *send_http_get_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname to an IP address
    unsigned long ip_address = resolve_hostname(hostname);

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr.s_addr = ip_address;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the HTTP GET request
    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the HTTP response
    char response[4096];
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Return the HTTP response
    char *response_copy = malloc(bytes_received + 1);
    memcpy(response_copy, response, bytes_received);
    response_copy[bytes_received] = '\0';
    return response_copy;
}

// Function to parse the HTTP response and extract the body
char *parse_http_response_body(const char *response) {
    // Find the start of the body
    char *body_start = strstr(response, "\r\n\r\n");
    if (!body_start) {
        return NULL;
    }

    // Copy the body into a new buffer
    char *body = malloc(strlen(body_start) + 1);
    strcpy(body, body_start);

    // Return the body
    return body;
}

int main(int argc, char **argv) {
    // Check if the user specified a hostname and path
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    // Send the HTTP GET request
    char *response = send_http_get_request(argv[1], argv[2]);

    // Parse the HTTP response and extract the body
    char *body = parse_http_response_body(response);

    // Print the body
    printf("%s", body);

    // Free the memory allocated for the response and body
    free(response);
    free(body);

    return 0;
}