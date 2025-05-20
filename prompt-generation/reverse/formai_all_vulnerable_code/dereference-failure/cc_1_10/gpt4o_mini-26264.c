//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_help() {
    printf("Usage: http_client <URL>\n");
    printf("Example: http_client http://example.com\n");
}

void parse_url(const char *url, char *host, char *path) {
    // Initialize host and path
    strcpy(path, "/");
    if (strncmp(url, "http://", 7) == 0) {
        url += 7; // Skip over the "http://"
    } else {
        fprintf(stderr, "Invalid URL. Must start with http://\n");
        exit(EXIT_FAILURE);
    }

    char *slash = strchr(url, '/');
    if (slash) {
        strncpy(host, url, slash - url);
        host[slash - url] = '\0';
        strcpy(path, slash); // Take the path from the first slash
    } else {
        strcpy(host, url); // No path specified, use the host as path
    }
}

void http_get(const char *url) {
    char host[256];
    char path[256];

    parse_url(url, host, path);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve host
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", host);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Prepare the GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Buffer to store the response
    char response[BUFFER_SIZE];
    int bytes_received;
    
    // Receive the response
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", response); // Print response to stdout
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }

    // Clean up
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_help();
        return EXIT_FAILURE;
    }

    http_get(argv[1]);

    return EXIT_SUCCESS;
}