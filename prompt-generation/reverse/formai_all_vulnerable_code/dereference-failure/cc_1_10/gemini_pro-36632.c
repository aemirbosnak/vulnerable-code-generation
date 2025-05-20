//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_EVENTS 1024

static int epoll_fd;
static int listen_fd;

static void signal_handler(int signum) {
    close(epoll_fd);
    close(listen_fd);
    exit(0);
}

static void add_event(int fd, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
}

static void modify_event(int fd, int events) {
    struct epoll_event event;
    event.events = events;
    event.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event);
}

static void delete_event(int fd) {
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
}

static void handle_accept(int listen_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd == -1) {
        perror("accept");
        return;
    }
    add_event(client_fd, EPOLLIN | EPOLLET);
}

static void handle_read(int client_fd) {
    char buffer[1024];
    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(client_fd);
        delete_event(client_fd);
        return;
    } else if (bytes_read == 0) {
        close(client_fd);
        delete_event(client_fd);
        return;
    }
    write(client_fd, buffer, bytes_read);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return 1;
    }
    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }
    if (listen(listen_fd, 10) == -1) {
        perror("listen");
        return 1;
    }

    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        return 1;
    }
    add_event(listen_fd, EPOLLIN | EPOLLET);

    signal(SIGINT, signal_handler);

    while (1) {
        struct epoll_event events[MAX_EVENTS];
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            break;
        }
        for (int i = 0; i < num_events; i++) {
            if (events[i].events & EPOLLIN) {
                if (events[i].data.fd == listen_fd) {
                    handle_accept(listen_fd);
                } else {
                    handle_read(events[i].data.fd);
                }
            }
        }
    }

    return 0;
}