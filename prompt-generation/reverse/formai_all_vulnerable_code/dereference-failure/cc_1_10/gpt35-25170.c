//FormAI DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define BUF_SIZE 4096 

static int count;

// helper function to check if the current character is a word character
bool is_word_char(char c) {
    return isalpha(c) || c == '_';
}

// helper function to read data from file descriptor and count words
void count_words(int fd) {
    char buffer[BUF_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (is_word_char(buffer[i])) {
                while (is_word_char(buffer[i])) {
                    i++;
                }
                count++;
            }
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from file descriptor %d: %s\n", fd, strerror(errno));
    }
}

// helper function to set file descriptor to non-blocking mode
void set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        printf("Error creating epoll file descriptor: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct epoll_event ev, events[MAX_EVENTS];
    int fd, nfds;

    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            printf("Error opening file %s: %s\n", argv[i], strerror(errno));
            continue;
        }

        set_nonblocking(fd);

        ev.events = EPOLLIN;
        ev.data.fd = fd;

        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1) {
            printf("Error adding file descriptor to epoll: %s\n", strerror(errno));
            close(fd);
            continue;
        }
    }

    while (true) {
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

        for (int n = 0; n < nfds; n++) {
            fd = events[n].data.fd;

            if (events[n].events & EPOLLIN) {
                count_words(fd);
            }
        }
    }

    printf("Total word count: %d\n", count);

    exit(EXIT_SUCCESS);
}