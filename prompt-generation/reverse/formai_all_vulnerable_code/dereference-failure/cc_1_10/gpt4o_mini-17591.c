//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 80
#define USER_AGENT "Post-Apocalyptic-HTTP-Client/1.0"

// Function prototypes
void send_http_request(const char *hostname, const char *path);
void die(const char *message);

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_http_request(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Failed to create socket");
    }

    // Get the server by hostname
    host = gethostbyname(hostname);
    if (!host) {
        close(sock);
        die("Failed to retrieve host by name");
    }

    // Fill the server address structure
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sock);
        die("Failed to connect to server");
    }

    // Create the HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "User-Agent: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname, USER_AGENT);

    // Send the HTTP request
    if (send(sock, request, strlen(request), 0) < 0) {
        close(sock);
        die("Failed to send request");
    }

    // Buffer to store the response
    char response[BUFFER_SIZE];

    // Read the response from the server
    printf("Response:\n");
    while (1) {
        bzero(response, BUFFER_SIZE);
        ssize_t bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break; // End of response
        }
        printf("%s", response);
    }

    // Close the socket
    close(sock);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // The ruins of civilization may have swiped the civilized way of doing things,
    // but the HTTP request remained. Beware of the connection errors, for
    // they can lead you to despair in these barren lands.

    // Extract arguments
    const char *hostname = argv[1];
    const char *path = argv[2];

    // Send the HTTP request
    send_http_request(hostname, path);

    return 0;
}