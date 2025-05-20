//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Failed to open socket");
        exit(1);
    }

    char *host_url = "www.example.com";
    server = gethostbyname(host_url);

    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve host '%s'\n", host_url);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect");
        exit(1);
    }

    char *request_fmt = 
        "GET / HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n";
    char request_buffer[BUFFER_SIZE];
    sprintf(request_buffer, request_fmt, host_url);

    if (write(socket_fd, request_buffer, strlen(request_buffer)) < 0) {
        perror("Failed to write to socket");
        exit(1);
    }

    int total_bytes_read = 0;
    int bytes_read = 0;
    while ((bytes_read = read(socket_fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        total_bytes_read += bytes_read;
    }

    printf("\n\nReceived %d bytes in total.\n", total_bytes_read);

    close(socket_fd);
    return 0;
}