//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

void make_http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char request[1024], response[4096];

    // Step 1: Resolve the hostname to an IP address
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        return;
    }

    // Step 2: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Step 3: Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP runs on port 80
    memcpy(&server_addr.sin_addr, host_entry->h_addr, host_entry->h_length);

    // Step 4: Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return;
    }

    // Step 5: Create the HTTP request
    snprintf(request, sizeof(request),
            "GET %s HTTP/1.1\r\n"
            "Host: %s\r\n"
            "Connection: close\r\n\r\n", 
            path, hostname);

    // Step 6: Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        return;
    }

    // Step 7: Receive the HTTP response
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        close(sockfd);
        return;
    }

    // Step 8: Print the HTTP response
    printf("Received response:\n%s\n", response);

    // Step 9: Clean up and close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Step 10: Make the HTTP request
    make_http_request(hostname, path);

    return EXIT_SUCCESS;
}