//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>

#define MAX_EVENTS 1024
#define TIMEOUT 1000

typedef struct {
    int fd;
    int port;
    struct sockaddr_in addr;
} scan_info;

void set_non_blocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

void start_scanning(const char *ip, int start_port, int end_port) {
    struct epoll_event ev, events[MAX_EVENTS];
    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    scan_info *scans = malloc(sizeof(scan_info) * (end_port - start_port + 1));
    if (!scans) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        set_non_blocking(sockfd);

        scans[port - start_port].port = port;
        scans[port - start_port].fd = sockfd;
        scans[port - start_port].addr.sin_family = AF_INET;
        scans[port - start_port].addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &scans[port - start_port].addr.sin_addr);

        if (connect(sockfd, (struct sockaddr *)&scans[port - start_port].addr, sizeof(scans[port - start_port].addr)) < 0) {
            if (errno != EINPROGRESS) {
                close(sockfd);
                continue;
            }
        }

        ev.events = EPOLLOUT | EPOLLIN | EPOLLERR;
        ev.data.ptr = &scans[port - start_port];
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &ev) == -1) {
            perror("epoll_ctl");
            close(sockfd);
            continue;
        }
    }

    int n_fds;
    while ((n_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, TIMEOUT)) > 0) {
        for (int i = 0; i < n_fds; i++) {
            scan_info *info = events[i].data.ptr;
            int port = info->port;
            int sockfd = info->fd;

            int error = 0;
            socklen_t len = sizeof(error);
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
                perror("getsockopt");
            } else {
                if (error == 0) {
                    printf("Port %d is open\n", port);
                } else {
                    printf("Port %d is closed\n", port);
                }
            }
            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, sockfd, NULL);
            close(sockfd);
        }
    }

    free(scans);
    close(epoll_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    start_scanning(ip_address, start_port, end_port);
    
    return 0;
}