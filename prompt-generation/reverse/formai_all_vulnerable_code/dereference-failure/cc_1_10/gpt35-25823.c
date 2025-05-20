//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * This program builds a HTTP client that sends GET requests to the given URL.
 * The response from the server is printed to the console.
 */

int main(int argc, char *argv[]) {
    // Check if URL argument is provided
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *hostname = url;
    char *path = "/";
    int port = 80;

    // Get hostname and path from the URL
    char *http = strstr(url, "http://");
    if (http != NULL) {
        hostname = url + 7;
    }
    char *slash = strchr(hostname, '/');
    if (slash != NULL) {
        path = slash;
        *slash = '\0';
    }
    char *colon = strchr(hostname, ':');
    if (colon != NULL) {
        *colon = '\0';
        port = atoi(colon + 1);
    }

    // Get IP address from the hostname
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Unknown host: %s\n", hostname);
        return 1;
    }
    char *ip = inet_ntoa(*(struct in_addr*)he->h_addr);

    // Create socket and connect to server
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Send GET request to server
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
    int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

    // Receive response from server and print to console
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, stdout);
    }

    // Close socket and exit program
    close(sockfd);
    return 0;
}