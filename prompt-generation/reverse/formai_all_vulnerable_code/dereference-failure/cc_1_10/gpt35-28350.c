//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    char *http_host = "www.example.com";
    int http_port = 80;

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(http_port);
    if(inet_pton(AF_INET, http_host, &server_address.sin_addr) < 1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    const char *http_request_template = "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n";
    size_t http_request_size = strlen(http_request_template) + strlen(http_host) + 6;
    char http_request[http_request_size];
    snprintf(http_request, http_request_size, http_request_template, http_host, http_port);

    ssize_t sent = send(sockfd, http_request, strlen(http_request), 0);
    if(sent < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    ssize_t received = recv(sockfd, buf, BUFSIZE, 0);
    if(received < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    const char *http_response_template = "HTTP/1.1 %d %s\r\n";
    int http_response_code = -1;
    char http_response_reason[BUFSIZE] = {'\0'};
    sscanf(buf, http_response_template, &http_response_code, http_response_reason);

    printf("HTTP response code: %d\n", http_response_code);
    printf("HTTP response reason: %s\n", http_response_reason);
    printf("HTTP response message:\n---\n%s\n---\n", buf + strlen(http_response_reason) + 14);

    close(sockfd);
    return EXIT_SUCCESS;
}