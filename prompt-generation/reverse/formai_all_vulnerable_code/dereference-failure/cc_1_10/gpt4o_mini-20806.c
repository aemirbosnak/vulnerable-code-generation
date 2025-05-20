//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;         
    hints.ai_socktype = SOCK_STREAM;   

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        error("getaddrinfo");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        error("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        error("connect");
    }

    freeaddrinfo(res);
    return sockfd;
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
    
    int n = write(sockfd, request, strlen(request));
    if (n < 0) {
        error("write");
    }
}

void read_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int n;
    
    while ((n = read(sockfd, response, sizeof(response) - 1)) > 0) {
        response[n] = '\0';
        printf("%s", response);
    }
    if (n < 0) {
        error("read");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    const char *port = "80";

    int sockfd = create_socket(hostname, port);
    send_http_request(sockfd, hostname, path);
    read_http_response(sockfd);
    
    close(sockfd);
    return 0;
}