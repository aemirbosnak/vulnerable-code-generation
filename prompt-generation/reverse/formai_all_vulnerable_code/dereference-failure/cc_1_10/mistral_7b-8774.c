//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *url = argv[1];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int error = getaddrinfo(NULL, NULL, &hints, &res);
    if (error != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        close(sockfd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *) res->ai_addr;

    if (connect(sockfd, (struct sockaddr *) ipv4, sizeof *ipv4) < 0)
        die("connect");

    freeaddrinfo(res);

    char request[BUFFER_SIZE];
    snprintf(request, sizeof request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Simple-HTTP-Client/1.0\r\nAccept: */*\r\nConnection: close\r\n\r\n", url, url);

    ssize_t request_len = send(sockfd, request, strlen(request), 0);
    if (request_len < 0) die("send");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof buffer - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        fflush(stdout);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}