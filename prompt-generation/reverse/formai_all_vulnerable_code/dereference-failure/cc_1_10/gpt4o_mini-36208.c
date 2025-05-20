//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Error: Could not send HTTP request");
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (bytes_received < 0) {
        die("Error: Could not receive HTTP response");
    }
}

void parse_url(const char *url, char *hostname, char *path) {
    const char *start = strstr(url, "http://");
    if (start) {
        start += strlen("http://");
    } else {
        start = url;
    }

    const char *end = strchr(start, '/');
    if (end) {
        strncpy(hostname, start, end - start);
        hostname[end - start] = '\0';
        strcpy(path, end);
    } else {
        strcpy(hostname, start);
        path[0] = '/';
        path[1] = '\0';
    }
}

int establish_connection(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Error: Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Error: Could not connect to server");
    }

    return sockfd;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char hostname[256];
    char path[256];
    parse_url(argv[1], hostname, path);

    int sockfd = establish_connection(hostname, 80);
    send_http_request(sockfd, hostname, path);
    receive_http_response(sockfd);

    close(sockfd);
    return 0;
}