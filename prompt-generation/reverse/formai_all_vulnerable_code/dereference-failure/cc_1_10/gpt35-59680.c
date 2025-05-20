//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MESSAGE_LEN 1024

int main(int argc, char *argv[]) {
    char *host = "www.google.com";
    char *port = "80";
    char *path = "/";
    if (argc > 1) {
        host = argv[1];
        if (argc > 2) {
            port = argv[2];
            if (argc > 3) {
                path = argv[3];
            }
        }
    }

    printf("Sending HTTP request to %s:%s%s\n", host, port, path);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *server;
    if (getaddrinfo(host, port, &hints, &server) != 0) {
        perror("Could not resolve server address");
        return 1;
    }

    int socket_fd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (socket_fd < 0) {
        perror("Could not create socket");
        return 1;
    }

    if (connect(socket_fd, server->ai_addr, server->ai_addrlen) < 0) {
        perror("Could not connect to server");
        return 1;
    }

    char *message = malloc(MAX_MESSAGE_LEN);
    snprintf(message, MAX_MESSAGE_LEN,
             "GET %s HTTP/1.1\r\n"
             "Host: %s:%s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, host, port);

    if (send(socket_fd, message, strlen(message), 0) == -1) {
        perror("Could not send message to server");
        return 1;
    }

    free(message);

    char response[MAX_MESSAGE_LEN];
    memset(response, 0, MAX_MESSAGE_LEN);
    int response_len = recv(socket_fd, response, MAX_MESSAGE_LEN, 0);
    if (response_len == -1) {
        perror("Could not receive response from server");
        return 1;
    }

    printf("Received response from server:\n%s", response);

    if (close(socket_fd) == -1) {
        perror("Could not close socket");
        return 1;
    }

    return 0;
}