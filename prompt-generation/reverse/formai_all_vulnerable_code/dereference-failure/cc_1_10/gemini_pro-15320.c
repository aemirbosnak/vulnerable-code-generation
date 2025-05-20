//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 4096

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    if (getaddrinfo(host, argv[2], &hints, &result) != 0)
    {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1)
    {
        fprintf(stderr, "socket() failed\n");
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1)
    {
        fprintf(stderr, "connect() failed\n");
        return 1;
    }

    freeaddrinfo(result);

    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        fprintf(stderr, "send() failed\n");
        return 1;
    }

    char buf[BUF_SIZE];
    int n;

    while ((n = recv(sockfd, buf, BUF_SIZE, 0)) > 0)
    {
        fwrite(buf, 1, n, stdout);
    }

    if (n == -1)
    {
        fprintf(stderr, "recv() failed\n");
        return 1;
    }

    close(sockfd);

    return 0;
}