//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }
    
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int error = getaddrinfo(argv[1], "http", &hints, &res);
    if (error) {
        fprintf(stderr, "Could not resolve hostname: %s\n", gai_strerror(error));
        return 2;
    }
    
    int fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (fd == -1) {
        perror("Could not create socket");
        return 3;
    }
    
    if (connect(fd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("Could not connect to host");
        close(fd);
        return 4;
    }
    
    const char *request_fmt = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    size_t request_len = strlen(request_fmt) + strlen(argv[1]);
    char *request = malloc(request_len);
    snprintf(request, request_len, request_fmt, argv[1]);
    send(fd, request, request_len, 0);
    free(request);
    
    char response[4096];
    int recv_len = recv(fd, response, sizeof(response), 0);
    if (recv_len == -1) {
        perror("Could not receive data");
        close(fd);
        return 5;
    }
    
    printf("%.*s\n", recv_len, response);
    close(fd);
    
    return 0;
}