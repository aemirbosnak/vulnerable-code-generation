//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HEADERS 10
#define MAX_RESPONSE_SIZE 1024

int open_connection(const char *host, int port) {
    struct hostent *he;
    struct sockaddr_in server_address;
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(1);
    }
    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_address.sin_zero), '\0', 8);
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    return socket_fd;
}

void close_connection(int socket_fd) {
    close(socket_fd);
}

void send_request(int socket_fd, const char *method, const char *path, const char *headers[], size_t num_headers) {
    size_t i;
    char request[MAX_RESPONSE_SIZE];
    sprintf(request, "%s %s HTTP/1.0\r\n", method, path);
    for (i = 0; i < num_headers; i++) {
        strcat(request, headers[i]);
        strcat(request, "\r\n");
    }
    strcat(request, "\r\n");
    if (send(socket_fd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }
}

void read_response(int socket_fd, char *response_buffer) {
    memset(response_buffer, 0, MAX_RESPONSE_SIZE);
    ssize_t num_bytes_read = recv(socket_fd, response_buffer, MAX_RESPONSE_SIZE - 1, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(1);
    }
}

int main() {
    const char *host = "www.google.com";
    int port = 80;
    const char *method = "GET";
    const char *path = "/";
    const char *headers[MAX_HEADERS] = {
        "Host: www.google.com",
        "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:89.0) Gecko/20100101 Firefox/89.0",
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
        "Accept-Language: en-US,en;q=0.5",
        "Connection: keep-alive",
        "Upgrade-Insecure-Requests: 1",
        "TE: Trailers"
    };
    size_t num_headers = 7;
    int socket_fd = open_connection(host, port);
    send_request(socket_fd, method, path, headers, num_headers);
    char response_buffer[MAX_RESPONSE_SIZE];
    read_response(socket_fd, response_buffer);
    printf("%s", response_buffer);
    close_connection(socket_fd);
    return 0;
}