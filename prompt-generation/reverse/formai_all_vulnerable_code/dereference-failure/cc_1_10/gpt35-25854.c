//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define PORT 8080

int set_nonblocking(int sock_fd) {
    int opts = fcntl(sock_fd, F_GETFL);
    if (opts < 0) {
        perror("fcntl(F_GETFL)");
        return -1;
    }
    opts |= O_NONBLOCK;
    if (fcntl(sock_fd, F_SETFL, opts) < 0) {
        perror("fcntl(F_SETFL)");
        return -1;
    }
    return 0;
}

void handle_client_data(int client_fd) {
    char buffer[1024];
    ssize_t nread;
    while ((nread = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received %ld bytes from client %d: %s\n", nread, client_fd, buffer);
        send(client_fd, buffer, nread, 0);
    }
    if (nread == -1 && errno != EAGAIN) {
        perror("recv");
        close(client_fd);
    }
}

int main() {
    struct sockaddr_in addr;
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    int efd = epoll_create1(0);
    if (listen_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (set_nonblocking(listen_fd) == -1) {
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(struct sockaddr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if (bind(listen_fd, (const struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct epoll_event event;
    event.data.fd = listen_fd;
    event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(efd, EPOLL_CTL_ADD, listen_fd, &event) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    struct epoll_event events[MAX_EVENTS];
    while (1) {
        int n = epoll_wait(efd, events, MAX_EVENTS, -1);
        for (int i = 0; i < n; i++) {
            if ((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                (!(events[i].events & EPOLLIN))) {
                perror("epoll error");
                close(events[i].data.fd);
                continue;
            } else if (listen_fd == events[i].data.fd) {
                while (1) {
                    struct sockaddr in_addr;
                    socklen_t in_addr_len = sizeof(in_addr);
                    int client_fd = accept(listen_fd, &in_addr, &in_addr_len);
                    if (client_fd == -1) {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                            break;
                        } else {
                            perror("accept");
                            break;
                        }
                    }

                    if (set_nonblocking(client_fd) == -1) {
                        exit(EXIT_FAILURE);
                    }

                    struct epoll_event client_event;
                    client_event.data.fd = client_fd;
                    client_event.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(efd, EPOLL_CTL_ADD, client_fd, &client_event) == -1) {
                        perror("epoll_ctl");
                        exit(EXIT_FAILURE);
                    }
                }
            } else {
                handle_client_data(events[i].data.fd);
            }
        }
    }

    close(listen_fd);
    return 0;
}