//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the URL.
    char *url = argv[1];
    char *host = strstr(url, "://");
    if (host == NULL) {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return EXIT_FAILURE;
    }
    host += 3;
    char *path = strchr(host, '/');
    if (path == NULL) {
        path = "/";
    }

    // Resolve the hostname.
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", host);
        return EXIT_FAILURE;
    }

    // Create the socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(80);
    sockaddr.sin_addr = *((struct in_addr *)hostent->h_addr);
    if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HTTP request.
    char request[MAX_URL_LENGTH + 16];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response.
    char response[MAX_RESPONSE_LENGTH];
    ssize_t nbytes = recv(sockfd, response, sizeof(response) - 1, 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    response[nbytes] = '\0';

    // Check the HTTP response code.
    if (strncmp(response, "HTTP/1.1 200 OK", 16) != 0) {
        fprintf(stderr, "Received non-200 OK response: %s\n", response);
        return EXIT_FAILURE;
    }

    // Print the HTTP response body.
    printf("%s", response + 16);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}