//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
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

void http_get(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];

    host = gethostbyname(hostname);
    if (host == NULL) {
        die("Unable to resolve hostname");
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    // Set server details
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }

    // Send HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sock, request, strlen(request), 0);

    // Receive response
    printf("Response:\n");
    while (1) {
        ssize_t received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (received < 0) {
            die("Failed to receive data");
        }
        if (received == 0) {
            break;
        }

        buffer[received] = '\0';
        printf("%s", buffer);
    }

    // Clean up
    close(sock);
}

void roam_the_wasteland() {
    char *hostname = "example.com"; // Domain of the last remaining data center
    char *path = "/";                // Root path to extract resources
    printf("===================================\n");
    printf("WASTELAND HTTP CLIENT\n");
    printf("Attempting to reclaim lost knowledge...\n");
    printf("Connecting to: %s%s\n", hostname, path);
    http_get(hostname, path);
    printf("\nData retrieval complete! Time to archive...\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    char *path = argv[2];

    printf("Wandering through the ruins...\n");
    roam_the_wasteland(hostname, path);

    return 0;
}