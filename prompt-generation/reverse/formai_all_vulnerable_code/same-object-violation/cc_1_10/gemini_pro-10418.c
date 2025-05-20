//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

struct csv_reader {
    int fd;
    char *buf;
    size_t buf_size;
    size_t buf_pos;
    char *line_buf;
    size_t line_buf_size;
    size_t line_buf_pos;
    int epoll_fd;
    int epoll_event;
    int eof;
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

    r->buf = malloc(4096);
    if (!r->buf) {
        close(r->fd);
        free(r);
        return NULL;
    }

    r->buf_size = 4096;
    r->buf_pos = 0;

    r->line_buf = malloc(1024);
    if (!r->line_buf) {
        free(r->buf);
        close(r->fd);
        free(r);
        return NULL;
    }

    r->line_buf_size = 1024;
    r->line_buf_pos = 0;

    r->epoll_fd = epoll_create1(0);
    if (r->epoll_fd < 0) {
        free(r->line_buf);
        free(r->buf);
        close(r->fd);
        free(r);
        return NULL;
    }

    struct epoll_event ev = {
        .events = EPOLLIN,
        .data = { .ptr = r },
    };

    if (epoll_ctl(r->epoll_fd, EPOLL_CTL_ADD, r->fd, &ev) < 0) {
        close(r->epoll_fd);
        free(r->line_buf);
        free(r->buf);
        close(r->fd);
        free(r);
        return NULL;
    }

    r->epoll_event = ev.events;
    r->eof = 0;

    return r;
}

void csv_reader_free(struct csv_reader *r)
{
    if (!r)
        return;

    if (r->epoll_fd >= 0)
        close(r->epoll_fd);

    if (r->fd >= 0)
        close(r->fd);

    if (r->buf)
        free(r->buf);

    if (r->line_buf)
        free(r->line_buf);

    free(r);
}

int csv_reader_next_line(struct csv_reader *r, char **line, size_t *line_len)
{
    if (r->eof)
        return -1;

    while (r->line_buf_pos >= r->line_buf_size) {
        if (r->buf_pos >= r->buf_size) {
            ssize_t n = read(r->fd, r->buf, r->buf_size);
            if (n <= 0) {
                r->eof = 1;
                return -1;
            }

            r->buf_pos = 0;
        }

        char *p = r->buf;
        char *end = r->buf + r->buf_pos;

        while (p < end) {
            char c = *p++;

            if (c == '\n') {
                *line_len = r->line_buf_pos;
                *line = r->line_buf;
                r->line_buf[r->line_buf_pos] = 0;
                r->line_buf_pos = 0;
                return 0;
            } else {
                if (r->line_buf_pos >= r->line_buf_size) {
                    size_t new_size = r->line_buf_size * 2;
                    char *new_buf = realloc(r->line_buf, new_size);
                    if (!new_buf)
                        return -1;

                    r->line_buf = new_buf;
                    r->line_buf_size = new_size;
                }

                r->line_buf[r->line_buf_pos++] = c;
            }
        }

        memmove(r->buf, r->buf + r->buf_pos, r->buf_size - r->buf_pos);
        r->buf_pos -= r->buf_pos;
    }

    return -1;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct csv_reader *r = csv_reader_new(argv[1]);
    if (!r) {
        perror("csv_reader_new");
        return EXIT_FAILURE;
    }

    struct epoll_event events[MAX_EVENTS];
    int nfds;

    while (1) {
        nfds = epoll_wait(r->epoll_fd, events, MAX_EVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait");
            csv_reader_free(r);
            return EXIT_FAILURE;
        }

        for (int i = 0; i < nfds; i++) {
            struct csv_reader *r = events[i].data.ptr;

            if (events[i].events & EPOLLIN) {
                char *line;
                size_t line_len;

                while (csv_reader_next_line(r, &line, &line_len) == 0) {
                    printf("%s\n", line);
                }

                if (r->eof) {
                    epoll_ctl(r->epoll_fd, EPOLL_CTL_DEL, r->fd, NULL);
                    csv_reader_free(r);
                }
            } else {
                fprintf(stderr, "Unknown event: %d\n", events[i].events);
                csv_reader_free(r);
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}