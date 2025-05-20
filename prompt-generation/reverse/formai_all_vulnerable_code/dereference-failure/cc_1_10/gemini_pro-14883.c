//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints;
    struct addrinfo *result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if (getaddrinfo(hostname, argv[2], &hints, &result) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket() failed\n");
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        fprintf(stderr, "connect() failed\n");
        return 1;
    }

    freeaddrinfo(result);

    char *request = "GET / HTTP/1.1\r\nHost: "
        "google.com\r\n\r\n";

    if (send(sockfd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "send() failed\n");
        return 1;
    }

    char buffer[4096];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }

    if (n == -1) {
        fprintf(stderr, "recv() failed\n");
        return 1;
    }

    close(sockfd);

    return 0;
}