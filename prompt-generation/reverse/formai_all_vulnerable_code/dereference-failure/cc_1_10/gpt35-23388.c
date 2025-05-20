//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

volatile sig_atomic_t is_running = 1;

void sig_handler(int signum) {
    if (signum == SIGINT) {
        is_running = 0;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <remote_host> <remote_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sig_handler);

    const char *remote_host = argv[1];
    const char *remote_port = argv[2];

    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
        .ai_protocol = IPPROTO_TCP,
    };
    struct addrinfo *result;
    if (getaddrinfo(remote_host, remote_port, &hints, &result) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    int remote_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (remote_sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(remote_sock, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = htonl(INADDR_LOOPBACK),
    };

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 1) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (is_running) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buf[BUF_SIZE];
        int num_bytes = recv(client_sock, buf, BUF_SIZE, 0);
        if (num_bytes == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        if (num_bytes == 0) {
            close(client_sock);
            continue;
        }

        if (send(remote_sock, buf, num_bytes, 0) == -1) {
            perror("send");
            close(client_sock);
            continue;
        }

        num_bytes = recv(remote_sock, buf, BUF_SIZE, 0);
        if (num_bytes == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        if (num_bytes == 0) {
            close(client_sock);
            continue;
        }

        if (send(client_sock, buf, num_bytes, 0) == -1) {
            perror("send");
            close(client_sock);
            continue;
        }

        close(client_sock);
    }

    close(server_sock);
    close(remote_sock);

    return 0;
}