//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char buffer[BUFFER_SIZE];

    // Get host by name
    if ((host_entry = gethostbyname(host)) == NULL) {
        die("gethostbyname failed");
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("socket creation failed");
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP default port
    server_addr.sin_addr = *((struct in_addr *)host_entry->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connection to server failed");
    }

    // Prepare HTTP GET request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    
    // Send request to server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        die("send failed");
    }
    printf("Request sent:\n%s", buffer);

    // Read response
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            die("receive failed");
        }
        if (bytes_received == 0) {
            break; // connection closed
        }
        printf("%s", buffer); // Print response
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // Perform HTTP GET request
    http_get(host, path);

    return 0;
}