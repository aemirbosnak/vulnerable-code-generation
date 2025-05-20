//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENTS 1024
#define PORT 8080
#define BUF_SIZE 1024

struct connection {
    int fd;
    char buf[BUF_SIZE];
    int buf_len;
    int state;
};

int main() {
    // Create a listening socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the socket to be non-blocking
    int flags = fcntl(listenfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(listenfd, F_SETFL, flags) == -1) {
        perror("fcntl");
        return -1;
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return -1;
    }

    // Listen on the socket
    if (listen(listenfd, SOMAXCONN) == -1) {
        perror("listen");
        return -1;
    }

    // Create an epoll instance
    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return -1;
    }

    // Add the listening socket to the epoll instance
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listenfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev) == -1) {
        perror("epoll_ctl");
        return -1;
    }

    // Main loop
    while (1) {
        // Wait for events
        struct epoll_event events[MAX_EVENTS];
        int num_events = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            return -1;
        }

        // Process events
        for (int i = 0; i < num_events; i++) {
            // New connection
            if (events[i].data.fd == listenfd) {
                int connfd = accept(listenfd, NULL, NULL);
                if (connfd == -1) {
                    perror("accept");
                    continue;
                }

                // Set the socket to be non-blocking
                flags = fcntl(connfd, F_GETFL, 0);
                if (flags == -1) {
                    perror("fcntl");
                    continue;
                }
                flags |= O_NONBLOCK;
                if (fcntl(connfd, F_SETFL, flags) == -1) {
                    perror("fcntl");
                    continue;
                }

                // Add the new connection to the epoll instance
                ev.events = EPOLLIN | EPOLLOUT;
                ev.data.fd = connfd;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &ev) == -1) {
                    perror("epoll_ctl");
                    continue;
                }
            } else {
                // Existing connection
                int fd = events[i].data.fd;
                struct connection *conn = (struct connection*)malloc(sizeof(struct connection));
                conn->fd = fd;
                conn->buf_len = 0;

                if (events[i].events & EPOLLIN) {
                    // Read data from the client
                    int n = read(fd, conn->buf + conn->buf_len, BUF_SIZE - conn->buf_len);
                    if (n == -1) {
                        if (errno == EAGAIN) {
                            // Non-blocking read would block, so just ignore it
                            continue;
                        } else {
                            perror("read");
                            epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                            close(fd);
                            free(conn);
                            continue;
                        }
                    } else if (n == 0) {
                        // Client closed the connection
                        epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                        close(fd);
                        free(conn);
                        continue;
                    } else {
                        // Data received
                        conn->buf_len += n;
                    }
                }

                if (events[i].events & EPOLLOUT) {
                    // Write data to the client
                    int n = write(fd, conn->buf, conn->buf_len);
                    if (n == -1) {
                        if (errno == EAGAIN) {
                            // Non-blocking write would block, so just ignore it
                            continue;
                        } else {
                            perror("write");
                            epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                            close(fd);
                            free(conn);
                            continue;
                        }
                    } else {
                        // Data sent
                        conn->buf_len -= n;
                        memmove(conn->buf, conn->buf + n, conn->buf_len);
                    }
                }

                if (conn->buf_len == 0) {
                    // No more data to send, so remove the EPOLLOUT event from the epoll instance
                    ev.events = EPOLLIN;
                    ev.data.fd = fd;
                    if (epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev) == -1) {
                        perror("epoll_ctl");
                        epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
                        close(fd);
                        free(conn);
                        continue;
                    }
                }
            }
        }
    }

    // Close the listening socket
    close(listenfd);

    // Close the epoll instance
    close(epollfd);

    return 0;
}