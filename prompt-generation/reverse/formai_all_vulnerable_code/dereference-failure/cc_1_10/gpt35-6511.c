//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

int http_client(const char *url) {
    struct addrinfo addr_hints, *addr_result;

    memset(&addr_hints, 0, sizeof(struct addrinfo));
    addr_hints.ai_family = AF_UNSPEC;
    addr_hints.ai_socktype = SOCK_STREAM;
    addr_hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(url, "http", &addr_hints, &addr_result) != 0) {
        printf("Failed to get address information: %s\n", strerror(errno));
        return 1;
    }

    int sock_fd = socket(addr_result->ai_family, addr_result->ai_socktype, addr_result->ai_protocol);
    if (sock_fd == -1) {
        printf("Failed to create socket: %s\n", strerror(errno));
        freeaddrinfo(addr_result);
        return 1;
    }

    if (connect(sock_fd, addr_result->ai_addr, addr_result->ai_addrlen) == -1) {
        printf("Failed to connect to server: %s\n", strerror(errno));
        freeaddrinfo(addr_result);
        close(sock_fd);
        return 1;
    }

    char *request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sock_fd, request, strlen(request), 0) == -1) {
        printf("Failed to send request to server: %s\n", strerror(errno));
        freeaddrinfo(addr_result);
        close(sock_fd);
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_received = 0;
    while (1) {
        ssize_t bytes = recv(sock_fd, buffer + bytes_received, MAX_BUFFER_SIZE - bytes_received, 0);
        if (bytes == -1) {
            printf("Failed to receive data from server: %s\n", strerror(errno));
            freeaddrinfo(addr_result);
            close(sock_fd);
            return 1;
        } else if (bytes == 0) {
            break;
        } else {
            bytes_received += bytes;
        }
    }

    printf("Received response from server:\n%s", buffer);

    freeaddrinfo(addr_result);
    close(sock_fd);

    return 0;
}

int main() {
    char url[] = "example.com";
    return http_client(url);
}