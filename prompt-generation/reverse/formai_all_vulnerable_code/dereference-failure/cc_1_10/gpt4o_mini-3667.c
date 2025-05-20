//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUF 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_usage(const char *progname) {
    printf("Usage: %s <hostname> <port> <path>\n", progname);
    printf("Example: %s www.example.com 80 /\n", progname);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *port = argv[2];
    const char *path = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // Use IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if (getaddrinfo(host, port, &hints, &servinfo) != 0) {
        error("getaddrinfo failed");
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break; // Successfully connected
    }

    freeaddrinfo(servinfo); // No longer needed

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s:%s\n", host, port);
        return EXIT_FAILURE;
    }

    // Prepare the HTTP GET request
    char request[MAX_BUF];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        error("send");
    }

    // Receive and display the response
    char response[MAX_BUF];
    int bytes_received;

    printf("Response:\n");
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the received string
        printf("%s", response);
    }

    if (bytes_received == -1) {
        error("recv");
    }

    // Clean up and close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}