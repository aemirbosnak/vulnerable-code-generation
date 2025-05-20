//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <URL> <Output_File>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *url = argv[1];
    const char *output_file = argv[2];

    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(NULL, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: C-HTTP-Client/1.0\r\n"
             "Accept: */*\r\n"
             "Connection: keep-alive\r\n"
             "\r\n",
             url, url);

    write(sockfd, request, strlen(request));

    char response[BUFFER_SIZE];
    ssize_t read_size;
    FILE *output = fopen(output_file, "wb");

    while ((read_size = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        fwrite(response, read_size, 1, output);
    }

    if (read_size < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    fclose(output);

    close(sockfd);

    return EXIT_SUCCESS;
}