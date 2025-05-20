//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void perform_http_get(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char request[1024];
    char response[BUFFER_SIZE];

    // Resolve hostname to IP
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Fill in the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    printf("Connecting to %s...\n", hostname);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Connected to %s!\n", hostname);

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    printf("Sending request:\n%s\n", request);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive response
    printf("Receiving response...\n");
    int total_received = 0;
    int bytes_received;
    while ((bytes_received = recv(sock, response + total_received, BUFFER_SIZE - total_received - 1, 0)) > 0) {
        total_received += bytes_received;
    }
    if (bytes_received < 0) {
        perror("Failed to receive response");
    }
    response[total_received] = '\0'; // Null-terminate the response

    // Print the response
    printf("Response received:\n%s\n", response);

    // Clean up
    close(sock);
    printf("Connection closed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    perform_http_get(hostname, path);

    return EXIT_SUCCESS;
}