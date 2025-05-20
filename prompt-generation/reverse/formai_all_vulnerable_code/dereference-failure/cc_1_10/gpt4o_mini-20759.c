//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(1);
}

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];

    // Getting the server's IP address
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        die("gethostbyname failed");
    }

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    // Prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr_list[0], host_entry->h_length);
    server_addr.sin_port = htons(80); // HTTP port

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    // Prepare the GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    // Sending the GET request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Send failed");
    }

    // Read the server response
    printf("Response:\n");
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            die("Receive failed");
        }
        if (bytes_received == 0) {
            break; // Connection closed
        }
        printf("%s", buffer);
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_get(hostname, path);

    return 0;
}