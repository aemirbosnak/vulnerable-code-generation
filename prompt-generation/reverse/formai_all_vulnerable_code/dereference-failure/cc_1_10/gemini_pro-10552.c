//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Recursive function to send a HTTP request and receive the response
int send_http_request(int sockfd, char *host, char *port, char *path) {
    // Create the HTTP request
    char request[1024];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return -1;
    }

    // Receive the HTTP response
    char response[4096];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Print the HTTP response
    printf("%s", response);

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s host port path\n", argv[0]);
        return 1;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the HTTP request and receive the response
    send_http_request(sockfd, argv[1], argv[2], argv[3]);

    return 0;
}