//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_usage(const char *program) {
    printf("Usage: %s <hostname> <port> <path>\n", program);
}

void http_get(const char *hostname, const char *port, const char *path) {
    int sock;
    struct addrinfo hints, *res;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    // Prepare requests
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Clear hints
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;

    // Resolve hostname
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo failed");
        return;
    }

    // Create socket
    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket");
        freeaddrinfo(res);
        return;
    }

    // Connect to the server
    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        close(sock);
        freeaddrinfo(res);
        return;
    }

    // Free the address info
    freeaddrinfo(res);

    // Send HTTP GET request
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        close(sock);
        return;
    }

    // Receive the response
    printf("Response:\n");
    int bytes_received;
    while ((bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", response);
    }

    if (bytes_received == -1) {
        perror("recv");
    }

    // Close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *path = argv[3];

    http_get(hostname, port, path);
    return 0;
}