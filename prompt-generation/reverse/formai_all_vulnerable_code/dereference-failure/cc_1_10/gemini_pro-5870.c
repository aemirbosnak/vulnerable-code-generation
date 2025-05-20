//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char request[512];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (write(sockfd, request, strlen(request)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    char response[4096];
    int bytes_read;
    while ((bytes_read = read(sockfd, response, sizeof(response))) > 0) {
        fwrite(response, 1, bytes_read, stdout);
    }

    if (bytes_read < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}