//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <poll.h>

#define MAX_PORTS 100

static volatile int running = 1;

void signal_handler(int sig) {
    running = 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    struct pollfd pfd[MAX_PORTS];
    for (int i = 0; i < MAX_PORTS; i++) {
        pfd[i].fd = -1;
        pfd[i].events = POLLIN;
    }

    int max_fd = 0;

    while (running) {
        for (int port = 1; port <= 65535; port++) {
            if (pfd[port].fd == -1) {
                int fd = socket(AF_INET, SOCK_STREAM, 0);
                if (fd < 0) {
                    perror("socket");
                    return EXIT_FAILURE;
                }

                fcntl(fd, F_SETFL, O_NONBLOCK);

                addr.sin_port = htons(port);

                if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
                    if (errno != EINPROGRESS) {
                        perror("connect");
                        return EXIT_FAILURE;
                    }
                }

                pfd[port].fd = fd;
                if (fd > max_fd) {
                    max_fd = fd;
                }
            }
        }

        int n = poll(pfd, max_fd + 1, 1000);
        if (n < 0) {
            perror("poll");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < MAX_PORTS; i++) {
            if (pfd[i].fd != -1 && (pfd[i].revents & POLLIN)) {
                int err;
                socklen_t len = sizeof(err);
                if (getsockopt(pfd[i].fd, SOL_SOCKET, SO_ERROR, &err, &len) < 0) {
                    perror("getsockopt");
                    return EXIT_FAILURE;
                }

                if (err == 0) {
                    printf("Port %d is open\n", i);
                } else {
                    printf("Port %d is closed\n", i);
                }

                close(pfd[i].fd);
                pfd[i].fd = -1;
            }
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}