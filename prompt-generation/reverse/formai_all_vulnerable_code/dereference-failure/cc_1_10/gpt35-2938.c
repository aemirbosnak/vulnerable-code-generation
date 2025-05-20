//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, status;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFSIZE];
    char *request, *response;
    const char *message_format = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    bool connected = false;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (!server) {
        fprintf(stderr, "Error: no such host as %s\n", argv[1]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(errno);
    }

    status = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("connect");
        exit(errno);
    }
    connected = true;

    request = (char *) malloc(strlen(message_format) + strlen(argv[1]) - 1);
    sprintf(request, message_format, argv[1]);

    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("write");
        exit(errno);
    }

    response = (char *) malloc(BUFSIZE);
    memset(response, 0, BUFSIZE);

    while ((n = read(sockfd, buffer, BUFSIZE - 1)) > 0) {
        buffer[n] = '\0';
        strcat(response, buffer);
    }

    if (n < 0) {
        perror("read");
        exit(errno);
    }

    printf("%s\n", response);

    if (connected) {
        close(sockfd);
    }

    free(request);
    free(response);
    exit(0);
}