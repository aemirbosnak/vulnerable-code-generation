//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <url>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    int socket_fd;
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_sent, bytes_received;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], "http", &hints, &res) != 0) {
        perror("Failed to get address info");
        return 1;
    }

    socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        return 1;
    }

    if (connect(socket_fd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Failed to connect to host");
        return 1;
    }

    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[2], argv[1]);
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        perror("Failed to send request");
        return 1;
    }

    while ((bytes_received = recv(socket_fd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received == -1) {
        perror("Failed to receive response");
        return 1;
    }

    close(socket_fd);
    freeaddrinfo(res);

    return 0;
}