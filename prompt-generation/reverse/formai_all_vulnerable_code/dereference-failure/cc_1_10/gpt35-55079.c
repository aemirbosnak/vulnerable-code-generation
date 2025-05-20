//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <path>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char *path = argv[3];

    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(hostname, port, &hints, &res);

    if (status != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        return 2;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect failed");
        return 3;
    }

    char request[MAX_MESSAGE_LENGTH];
    snprintf(request, MAX_MESSAGE_LENGTH, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    printf("Requesting:\n%s\n", request);

    write(sockfd, request, strlen(request));

    char response[MAX_MESSAGE_LENGTH];
    int n;
    while ((n = read(sockfd, response, MAX_MESSAGE_LENGTH - 1)) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }

    close(sockfd);
    freeaddrinfo(res);
    return 0;
}