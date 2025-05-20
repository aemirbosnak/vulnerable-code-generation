//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

void fatal(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_request(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd;
    char buffer[BUFFER_SIZE];

    // Get server address
    if ((host = gethostbyname(hostname)) == NULL) {
        fatal("Failed to resolve hostname");
    }

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fatal("Socket creation failed");
    }

    // Setup server address struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(80);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fatal("Failed to connect to server");
    }

    // Send HTTP GET request
    snprintf(buffer, sizeof(buffer),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fatal("Failed to send request");
    }

    // Receive response
    printf("Response:\n");
    while (1) {
        int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) break;

        buffer[bytes_received] = '\0'; // Null terminate for safe printing
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_request(hostname, path);

    return EXIT_SUCCESS;
}