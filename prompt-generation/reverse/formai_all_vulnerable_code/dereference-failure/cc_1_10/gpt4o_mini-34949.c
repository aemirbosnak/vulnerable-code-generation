//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <hostname> <port> <resource>\n", prog_name);
}

int create_socket(const char *hostname, const char *port) {
    struct addrinfo hints, *res;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        close(sockfd);
        freeaddrinfo(res);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);
    return sockfd;
}

void send_http_request(int sockfd, const char *hostname, const char *resource) {
    char request[BUFFER_SIZE];

    snprintf(request, sizeof(request), 
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", resource, hostname);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t nbytes;

    while ((nbytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[nbytes] = '\0'; // Ensure null termination
        printf("%s", buffer);
    }

    if (nbytes == -1) {
        perror("recv");
    }
}

void clean_exit(int sockfd) {
    close(sockfd);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *resource = argv[3];

    int sockfd = create_socket(hostname, port);
    send_http_request(sockfd, hostname, resource);
    receive_http_response(sockfd);
    close(sockfd);

    return EXIT_SUCCESS;
}