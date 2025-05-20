//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    // Parse URL
    char *hostname = strtok(url, "/");
    char *path = strtok(NULL, "");

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Could not resolve hostname!\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket!\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Could not connect to server!\n");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\n"
                                    "Host: %s\r\n"
                                    "Connection: close\r\n"
                                    "\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Could not send HTTP request!\n");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char response[BUFFER_SIZE];
    int received = 0;
    int total = BUFFER_SIZE - 1;
    while (received < total) {
        int bytes = recv(sockfd, response + received, total - received, 0);
        if (bytes < 0) {
            printf("Error receiving data!\n");
            exit(EXIT_FAILURE);
        } else if (bytes == 0) {
            break;
        }
        received += bytes;
    }
    response[received] = '\0';

    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}