//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <time.h>

#define PORT 80
#define TIMEOUT 10

typedef struct {
    int fd;
    char *buf;
    size_t buf_len;
    size_t buf_pos;
    struct epoll_event event;
} connection_t;

connection_t *connections[100];
int num_connections = 0;
int epoll_fd;

void add_connection(int fd) {
    connection_t *conn = malloc(sizeof(connection_t));
    conn->fd = fd;
    conn->buf = malloc(1024);
    conn->buf_len = 1024;
    conn->buf_pos = 0;
    conn->event.events = EPOLLIN | EPOLLET;
    conn->event.data.ptr = conn;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &conn->event);
    connections[num_connections++] = conn;
}

void remove_connection(connection_t *conn) {
    close(conn->fd);
    free(conn->buf);
    free(conn);
    for (int i = 0; i < num_connections; i++) {
        if (connections[i] == conn) {
            connections[i] = connections[num_connections - 1];
            num_connections--;
            break;
        }
    }
}

void handle_connection(connection_t *conn) {
    ssize_t bytes_read = read(conn->fd, conn->buf + conn->buf_pos, conn->buf_len - conn->buf_pos);
    if (bytes_read == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return;
        } else {
            remove_connection(conn);
            return;
        }
    } else if (bytes_read == 0) {
        remove_connection(conn);
        return;
    }

    conn->buf_pos += bytes_read;

    if (conn->buf_pos == conn->buf_len) {
        conn->buf_len *= 2;
        conn->buf = realloc(conn->buf, conn->buf_len);
    }
}

int main() {
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return 1;
    }

    int opt = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, 100) == -1) {
        perror("listen");
        return 1;
    }

    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        return 1;
    }

    struct epoll_event event;
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = listen_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) == -1) {
        perror("epoll_ctl");
        return 1;
    }

    while (1) {
        int num_events = epoll_wait(epoll_fd, &event, 1, TIMEOUT * 1000);
        if (num_events == -1) {
            perror("epoll_wait");
            return 1;
        }

        for (int i = 0; i < num_events; i++) {
            if (event.data.fd == listen_fd) {
                int conn_fd = accept(listen_fd, NULL, NULL);
                if (conn_fd == -1) {
                    perror("accept");
                    continue;
                }

                int flags = fcntl(conn_fd, F_GETFL, 0);
                if (flags == -1) {
                    perror("fcntl");
                    continue;
                }

                if (fcntl(conn_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
                    perror("fcntl");
                    continue;
                }

                add_connection(conn_fd);
            } else {
                connection_t *conn = event.data.ptr;
                handle_connection(conn);
            }
        }
    }

    close(listen_fd);
    close(epoll_fd);

    for (int i = 0; i < num_connections; i++) {
        remove_connection(connections[i]);
    }

    return 0;
}