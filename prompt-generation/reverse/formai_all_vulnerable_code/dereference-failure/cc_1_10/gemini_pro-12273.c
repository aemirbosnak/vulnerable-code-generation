//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// HTTP GET request function
int http_get(char *host, char *path) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Create the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, hostent->h_addr, hostent->h_length);
    addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Send the HTTP GET request
    char request[1024];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
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
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return -1;
    }

    // Send the HTTP GET request
    if (http_get(argv[1], argv[2]) == -1) {
        return -1;
    }

    return 0;
}