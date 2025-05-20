//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if URL argument is provided
    if (argc != 2) {
        printf("Error: Please provide a URL.\n");
        return 1;
    }

    // Parse URL
    char *url = argv[1];
    char *hostname = url + 7; // Skip "http://"
    char *path = strchr(hostname, '/');
    
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path += 1;
    }

    // Get host information
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Could not resolve hostname.\n");
        return 1;
    }

    // Set up socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    // Set up server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // HTTP port
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }

    // Send HTTP request
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive HTTP response
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}