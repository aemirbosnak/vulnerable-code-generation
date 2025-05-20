//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int build_client_socket(const char* server_name, const char* port) {
    struct addrinfo hints, *results, *rp;
    int sock_fd;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    if (getaddrinfo(server_name, port, &hints, &results) != 0) {
        perror("getaddrinfo() error");
        return -1;
    }

    for (rp = results; rp != NULL; rp = rp->ai_next) {
        sock_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sock_fd == -1) continue;

        if (connect(sock_fd, rp->ai_addr, rp->ai_addrlen) != -1) break;

        close(sock_fd);
    }

    if (rp == NULL) {
        perror("Could not connect");
        close(sock_fd);
        return -1;
    }

    freeaddrinfo(results);
    return sock_fd;
}

void send_request(int sock_fd, const char* http_request) {
    int len = strlen(http_request), bytes_sent = 0;

    while (bytes_sent < len) {
        int bytes_remaining = len - bytes_sent;
        int bytes_sent_now = send(sock_fd, http_request + bytes_sent, bytes_remaining, 0);
        if (bytes_sent_now < 0) {
            perror("send() failed");
            break;
        }
        bytes_sent += bytes_sent_now;
    }
}

void receive_response(int sock_fd) {
    char buf[MAX_BUF];
    int bytes_read = 0;

    while ((bytes_read = recv(sock_fd, buf, MAX_BUF, 0))) {
        if (bytes_read < 0) {
            perror("recv() failed");
            break;
        }
        fwrite(buf, sizeof(char), bytes_read, stdout);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [server name] [port] [file path]\n", argv[0]);
        return 0;
    }

    const char* server_name = argv[1];
    const char* port = argv[2];
    const char* file_path = argv[3];

    char http_request[MAX_BUF];
    snprintf(http_request, MAX_BUF, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", file_path, server_name);

    int sock_fd = build_client_socket(server_name, port);

    if (sock_fd == -1) {
        printf("Failed to connect to server: %s:%s\n", server_name, port);
        return 0;
    }

    send_request(sock_fd, http_request);
    receive_response(sock_fd);

    close(sock_fd);
    return 0;
}