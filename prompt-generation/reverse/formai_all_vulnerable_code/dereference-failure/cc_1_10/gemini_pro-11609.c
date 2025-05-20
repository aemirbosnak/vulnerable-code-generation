//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <time.h>
#include <signal.h>

#define MAX_EVENTS 10

struct csv_reader {
    int fd;
    char *buf;
    size_t buf_size;
    size_t buf_pos;
    int eof;
    int epoll_fd;
    int timer_fd;
    int timer_fd_timeout;
    struct epoll_event ev;
};

struct csv_reader *csv_reader_new(const char *filename)
{
    struct csv_reader *r = malloc(sizeof(*r));
    if (!r)
        return NULL;

    r->fd = open(filename, O_RDONLY);
    if (r->fd < 0) {
        free(r);
        return NULL;
    }

    r->buf = NULL;
    r->buf_size = 0;
    r->buf_pos = 0;
    r->eof = 0;

    r->epoll_fd = epoll_create1(0);
    if (r->epoll_fd < 0) {
        close(r->fd);
        free(r);
        return NULL;
    }

    r->timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);
    if (r->timer_fd < 0) {
        close(r->epoll_fd);
        close(r->fd);
        free(r);
        return NULL;
    }

    r->timer_fd_timeout = 1000;

    r->ev.events = EPOLLIN | EPOLLOUT | EPOLLRDHUP | EPOLLERR;
    r->ev.data.ptr = r;

    if (epoll_ctl(r->epoll_fd, EPOLL_CTL_ADD, r->fd, &r->ev) < 0) {
        close(r->timer_fd);
        close(r->epoll_fd);
        close(r->fd);
        free(r);
        return NULL;
    }

    if (epoll_ctl(r->epoll_fd, EPOLL_CTL_ADD, r->timer_fd, &r->ev) < 0) {
        close(r->timer_fd);
        close(r->epoll_fd);
        close(r->fd);
        free(r);
        return NULL;
    }

    return r;
}

void csv_reader_free(struct csv_reader *r)
{
    if (r->buf)
        free(r->buf);
    close(r->fd);
    close(r->epoll_fd);
    close(r->timer_fd);
    free(r);
}

int csv_reader_read_line(struct csv_reader *r, char **line, size_t *len)
{
    int n;

    for (;;) {
        if (r->buf_pos >= r->buf_size) {
            if (r->eof)
                return 0;

            r->buf_pos = 0;
            r->buf_size = 1024;
            r->buf = realloc(r->buf, r->buf_size);
            if (!r->buf)
                return -ENOMEM;

            n = read(r->fd, r->buf, r->buf_size);
            if (n < 0)
                return n;
            if (n == 0) {
                r->eof = 1;
                return 0;
            }
        }

        char *p = memchr(r->buf + r->buf_pos, '\n', r->buf_size - r->buf_pos);
        if (p) {
            *len = p - r->buf - r->buf_pos;
            *line = r->buf + r->buf_pos;
            r->buf_pos = p - r->buf + 1;
            return 1;
        }

        r->buf_pos = r->buf_size;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct csv_reader *r = csv_reader_new(argv[1]);
    if (!r) {
        perror("csv_reader_new");
        return EXIT_FAILURE;
    }

    struct epoll_event events[MAX_EVENTS];

    while (1) {
        int n = epoll_wait(r->epoll_fd, events, MAX_EVENTS, r->timer_fd_timeout);
        if (n < 0) {
            if (errno == EINTR)
                continue;
            perror("epoll_wait");
            break;
        }

        for (int i = 0; i < n; i++) {
            if (events[i].data.ptr == r) {
                if (events[i].events & EPOLLIN) {
                    char *line;
                    size_t len;
                    int rc = csv_reader_read_line(r, &line, &len);
                    if (rc < 0) {
                        perror("csv_reader_read_line");
                        break;
                    }
                    if (rc == 0) {
                        printf("EOF\n");
                        break;
                    }

                    printf("%.*s\n", (int)len, line);
                }

                if (events[i].events & EPOLLOUT) {
                    // write to stdout
                }

                if (events[i].events & EPOLLRDHUP) {
                    printf("Connection closed\n");
                    break;
                }

                if (events[i].events & EPOLLERR) {
                    perror("EPOLLERR");
                    break;
                }
            } else if (events[i].data.ptr == r->timer_fd) {
                // timeout
                printf("Timeout\n");
            }
        }
    }

    csv_reader_free(r);

    return EXIT_SUCCESS;
}