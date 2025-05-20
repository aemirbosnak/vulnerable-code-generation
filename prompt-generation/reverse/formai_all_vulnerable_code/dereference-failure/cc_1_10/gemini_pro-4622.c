//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char *host, *port, *path, *request;
    int host_len, port_len, path_len, request_len;
    ssize_t n;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    port = argv[2];
    path = argv[3];

    host_len = strlen(host);
    port_len = strlen(port);
    path_len = strlen(path);

    request_len = host_len + port_len + path_len + 128;
    request = malloc(request_len);
    if (request == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    snprintf(request, request_len,
             "GET %s HTTP/1.1\r\n"
             "Host: %s:%s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, host, port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    if (write(sockfd, request, request_len) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    while ((n = read(sockfd, request, request_len)) > 0) {
        if (write(STDOUT_FILENO, request, n) < 0) {
            perror("write");
            return EXIT_FAILURE;
        }
    }

    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}