//GEMINI-pro DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <poll.h>
#include <errno.h>
#include <string.h>

#define ERR(str) do { perror(str); exit(-1); } while(0)

#define BUFFER_SIZE (1024 * 1024)
#define MAX_FDS 10

struct {
    int fd;
    char *buf;
    size_t buf_size;
    size_t buf_len;
    size_t buf_offset;
} fds[MAX_FDS];

int num_fds = 0;

void add_fd(int fd) {
    if (num_fds >= MAX_FDS)
        ERR("Too many files");

    fds[num_fds].fd = fd;
    fds[num_fds].buf_size = BUFFER_SIZE;
    fds[num_fds].buf = malloc(BUFFER_SIZE);
    fds[num_fds].buf_len = 0;
    fds[num_fds].buf_offset = 0;

    num_fds++;
}

void remove_fd(int fd) {
    for (int i = 0; i < num_fds; i++) {
        if (fds[i].fd == fd) {
            free(fds[i].buf);
            num_fds--;
            memmove(&fds[i], &fds[i + 1], sizeof(fds[0]) * (num_fds - i));
            return;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2)
        ERR("Usage: ./a.out file1 file2 ...");

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0)
            ERR("Failed to open file");
        add_fd(fd);
    }

    struct pollfd pfds[MAX_FDS];
    for (int i = 0; i < num_fds; i++) {
        pfds[i].fd = fds[i].fd;
        pfds[i].events = POLLIN;
    }

    while (num_fds > 0) {
        int ret = poll(pfds, num_fds, -1);
        if (ret < 0)
            ERR("Poll failed");

        for (int i = 0; i < num_fds; i++) {
            if (pfds[i].revents & POLLHUP) {
                close(pfds[i].fd);
                remove_fd(pfds[i].fd);
                continue;
            }

            if (pfds[i].revents & POLLIN) {
                ssize_t nread = read(pfds[i].fd, fds[i].buf + fds[i].buf_len, fds[i].buf_size - fds[i].buf_len);
                if (nread < 0)
                    ERR("Read failed");
                else if (nread == 0) {
                    close(pfds[i].fd);
                    remove_fd(pfds[i].fd);
                } else {
                    fds[i].buf_len += nread;
                }
            }
        }
    }

    for (int i = 0; i < num_fds; i++) {
        write(STDOUT_FILENO, fds[i].buf, fds[i].buf_len);
        free(fds[i].buf);
    }

    return 0;
}