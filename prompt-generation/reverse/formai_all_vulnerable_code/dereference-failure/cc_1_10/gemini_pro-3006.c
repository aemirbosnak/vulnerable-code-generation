//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

char *get_http_request(char *host, char *path) {
    size_t len = strlen(host) + strlen(path) + 100;
    char *request = malloc(len);
    if (request == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    snprintf(request, len, "GET %s HTTP/1.1\n"
                          "Host: %s\n"
                          "Connection: close\n"
                          "\n", path, host);
    return request;
}

char *send_http_request(char *host, char *path) {
    int sockfd;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, "80", &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    char *request = get_http_request(host, path);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    free(request);

    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    while (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    close(sockfd);

    return buffer;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    send_http_request(argv[1], argv[2]);

    return EXIT_SUCCESS;
}