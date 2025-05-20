//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <arpa/inet.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <poll.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
    char buf[MAX_BUF];
    size_t buf_len;
    struct pollfd pfd;
} client;

static void
proxy(client *client1, client *client2)
{
    int nfds;
    struct pollfd pfds[] = {
        { .fd = client1->fd, .events = POLLIN },
        { .fd = client2->fd, .events = POLLIN },
    };

    for (;;) {
        nfds = poll(pfds, 2, -1);
        if (nfds < 0) {
            perror("poll");
            break;
        }

        for (int i = 0; i < 2; i++) {
            if (pfds[i].revents & POLLIN) {
                ssize_t n = read(pfds[i].fd, client1->buf, MAX_BUF);
                if (n < 0) {
                    perror("read");
                } else if (n == 0) {
                    close(pfds[i].fd);
                    pfds[i].fd = -1;
                } else {
                    client1->buf_len = n;
                    ssize_t m = write(client2->fd, client1->buf, n);
                    if (m < 0) {
                        perror("write");
                    }
                }
            }

            if (pfds[i].revents & POLLHUP) {
                close(client1->fd);
                close(client2->fd);
                exit(0);
            }
        }
    }
}

static int
create_server(const char *host, const char *port)
{
    struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
        .ai_protocol = IPPROTO_TCP,
    };
    struct addrinfo *result;

    if (getaddrinfo(host, port, &hints, &result) != 0) {
        err(1, "getaddrinfo");
    }

    int server_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_fd < 0) {
        err(1, "socket");
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) != 0) {
        err(1, "setsockopt");
    }

    if (bind(server_fd, result->ai_addr, result->ai_addrlen) != 0) {
        err(1, "bind");
    }

    freeaddrinfo(result);

    if (listen(server_fd, 10) != 0) {
        err(1, "listen");
    }

    return server_fd;
}

int
main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    int server_fd = create_server(argv[1], argv[2]);

    for (;;) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        client client1 = {
            .fd = client_fd,
            .addr = client_addr,
            .buf = { 0 },
            .buf_len = 0,
            .pfd = { .fd = client_fd, .events = POLLIN },
        };

        client client2 = {
            .fd = client_fd,
            .addr = client_addr,
            .buf = { 0 },
            .buf_len = 0,
            .pfd = { .fd = client_fd, .events = POLLIN },
        };

        proxy(&client1, &client2);
    }

    return 0;
}