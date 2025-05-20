//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024 // Buffer size for HTTP response

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1]; // Get host from command line argument

    // Set up socket connection
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(host, "80", &hints, &res);

    // Create socket
    int fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    // Connect to server
    connect(fd, res->ai_addr, res->ai_addrlen);

    // Prepare HTTP request
    char *request = "GET / HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Connection: close\r\n"
                    "\r\n";
    int request_len = snprintf(NULL, 0, request, host);
    char request_buff[request_len + 1];
    snprintf(request_buff, request_len + 1, request, host);

    // Send HTTP request
    send(fd, request_buff, strlen(request_buff), 0);

    // Receive HTTP response
    char buff[BUFF_SIZE];
    memset(buff, 0, sizeof buff);
    ssize_t bytes_received;
    while ((bytes_received = recv(fd, buff, sizeof buff, 0)) > 0) {
        printf("%s", buff);
        memset(buff, 0, sizeof buff);
    }
    printf("\n");

    // Clean up socket connection
    close(fd);
    freeaddrinfo(res);

    return 0;
}