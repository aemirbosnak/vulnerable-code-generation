//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

ssize_t send_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: My-Simple-HTTP-Client\r\n"
             "Accept: */*\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    return send(sockfd, request, strlen(request), 0);
}

ssize_t read_response(int sockfd, char *buffer, size_t size) {
    ssize_t n;
    while (size > 0) {
        n = recv(sockfd, buffer, size, 0);
        if (n <= 0)
            return n;
        size -= n;
        buffer += n;
    }
    return size;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("connect");

    if (send_request(sockfd, host, path) < 0)
        die("send_request");

    char buffer[BUFFER_SIZE];
    size_t size = BUFFER_SIZE;
    ssize_t bytes_received;

    while ((bytes_received = read_response(sockfd, buffer, size)) > 0) {
        size -= bytes_received;
        write(STDOUT_FILENO, buffer, bytes_received);
        memmove(buffer, buffer + bytes_received, size);
    }

    if (bytes_received < 0) {
        perror("Error reading response");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    free(buffer);
    close(sockfd);
    return EXIT_SUCCESS;
}