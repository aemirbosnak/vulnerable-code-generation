//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to create socket and connect to server
int create_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    // Resolve the hostname to an IP address
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    // Establish connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Function for sending HTTP GET request
void send_http_request(int sockfd, const char *path) {
    char request[BUFFER_SIZE];

    // Format the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", path);
    write(sockfd, request, strlen(request));
}

// Function to read and print the response from server
void read_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Read the response
    while (1) {
        int bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0) {
            perror("read");
            break;
        } else if (bytes_read == 0) {
            break; // Connection closed
        }

        // Null-terminate the buffer to treat it as a string
        buffer[bytes_read] = '\0';
        printf("%s", buffer); // Print the response
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Create a connection to the server
    int sockfd = create_connection(hostname, 80);
    if (sockfd < 0) {
        exit(EXIT_FAILURE);
    }

    // Send the HTTP GET request
    send_http_request(sockfd, path);

    // Read and display the HTTP response
    read_http_response(sockfd);

    // Clean up
    close(sockfd);
    return 0;
}