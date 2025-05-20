//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HTTP_PORT "80" // Default HTTP port
#define MAX_DATA_SIZE 1024 // Maximum expected response data size

int http_client(char *host, char *path) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int status;
    char *request;
    char *buffer;
    ssize_t bytes_recv;

    // Setup hints struct for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for the host
    if ((status = getaddrinfo(host, HTTP_PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // Loop through all results and connect to the first possible
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // Attempt to open a socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        // Attempt to connect to the host
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        // We've successfully connected, stop the loop
        break;
    }

    // Check if we were able to connect
    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", host);
        return 2;
    }

    // Request data to send (GET HTTP request)
    const char *format = "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    int req_len = strlen(format) + strlen(path) + strlen(host) - 4;
    request = (char *)malloc(req_len + 1);
    snprintf(request, req_len + 1, format, path, host);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 3;
    }

    // Allocate memory for the response buffer
    buffer = (char *)malloc(MAX_DATA_SIZE);
    memset(buffer, 0, MAX_DATA_SIZE);

    // Receive the response
    bytes_recv = recv(sockfd, buffer, MAX_DATA_SIZE, 0);
    if (bytes_recv == -1) {
        perror("recv");
        return 4;
    }

    // Print out the response
    printf("%s", buffer);

    // Clean up
    freeaddrinfo(servinfo);
    close(sockfd);
    free(request);
    free(buffer);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <path>\n", argv[0]);
        return 1;
    }

    return http_client(argv[1], argv[2]);
}