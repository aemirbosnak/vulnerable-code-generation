//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENTS 10

struct thread_data {
    int fd;
    char *buf;
    int buf_len;
    int count;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;
    int n;

    while ((n = read(data->fd, data->buf, data->buf_len)) > 0) {
        data->count += n;
    }

    if (n == -1) {
        perror("read");
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int fd, efd, i;
    struct epoll_event event;
    struct thread_data threads[MAX_EVENTS];
    pthread_t tid[MAX_EVENTS];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2] ...\n", argv[0]);
        return 1;
    }

    efd = epoll_create1(0);
    if (efd == -1) {
        perror("epoll_create1");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            perror("open");
            continue;
        }

        event.events = EPOLLIN;
        event.data.fd = fd;

        if (epoll_ctl(efd, EPOLL_CTL_ADD, fd, &event) == -1) {
            perror("epoll_ctl");
            close(fd);
            continue;
        }

        threads[i - 1].fd = fd;
        threads[i - 1].buf = malloc(4096);
        threads[i - 1].buf_len = 4096;
        threads[i - 1].count = 0;

        pthread_create(&tid[i - 1], NULL, thread_func, &threads[i - 1]);
    }

    int count = 0;
    while (1) {
        int n = epoll_wait(efd, &event, MAX_EVENTS, -1);
        if (n == -1) {
            perror("epoll_wait");
            break;
        }

        for (i = 0; i < n; i++) {
            if (event.events & EPOLLIN) {
                close(event.data.fd);
            }
        }

        for (i = 1; i < argc; i++) {
            pthread_join(tid[i - 1], NULL);
            count += threads[i - 1].count;
            free(threads[i - 1].buf);
            close(threads[i - 1].fd);
        }

        break;
    }

    printf("Total count: %d\n", count);

    close(efd);

    return 0;
}