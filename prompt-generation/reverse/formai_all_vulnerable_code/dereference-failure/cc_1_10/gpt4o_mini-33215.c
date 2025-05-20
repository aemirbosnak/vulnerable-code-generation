//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to perform the HTTP GET request
void http_get(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *he;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    // Get host address
    if ((he = gethostbyname(host)) == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    memcpy(&server_addr.sin_addr, he->h_addr, he->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connect failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the GET request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive the response
    printf("Response:\n");
    while (1) {
        ssize_t bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // Perform the HTTP GET request
    http_get(host, path);

    return 0;
}