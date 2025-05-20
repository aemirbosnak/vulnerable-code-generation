//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 80
#define MAX_BUF_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *host, *path;
    char request[MAX_BUF_LEN], response[MAX_BUF_LEN];

    // Validate input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    // Parse host and path from URL
    char *url = argv[1];
    host = strtok(url, "/");
    path = strtok(NULL, "");

    // Resolve hostname to IP address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: Invalid hostname\n");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to connect to server");
        exit(1);
    }

    // Send GET request
    snprintf(request, MAX_BUF_LEN, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error: Failed to send request");
        exit(1);
    }

    // Receive response
    int total_len = 0;
    int recv_len = 0;
    do {
        memset(response, 0, MAX_BUF_LEN);
        recv_len = recv(sockfd, response, MAX_BUF_LEN-1, 0);
        if (recv_len < 0) {
            perror("Error: Failed to receive response");
            exit(1);
        }
        total_len += recv_len;
        printf("%s", response);
    } while (recv_len > 0);

    // Clean up
    close(sockfd);

    return 0;
}