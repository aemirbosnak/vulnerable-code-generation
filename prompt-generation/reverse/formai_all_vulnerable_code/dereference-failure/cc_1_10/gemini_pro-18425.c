//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <linux/hdreg.h>
#include <pthread.h>
#include <semaphore.h>

#define BUF_SIZE 512
#define NR_SECTORS 65536
#define NR_THREADS 4

struct thread_data {
    int fd;
    char *buf;
    int start;
    int len;
    sem_t sem;
};

void *thread_func(void *arg)
{
    struct thread_data *data = (struct thread_data *)arg;
    int nread;

    nread = pread(data->fd, data->buf, data->len, data->start);
    if (nread == -1) {
        perror("pread");
        exit(1);
    }

    sem_post(&data->sem);
    return NULL;
}

int main(int argc, char *argv[])
{
    int fd, i;
    struct stat st;
    char *buf;
    pthread_t tid[NR_THREADS];
    struct thread_data data[NR_THREADS];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(1);
    }

    buf = malloc(BUF_SIZE);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    for (i = 0; i < NR_THREADS; i++) {
        data[i].fd = fd;
        data[i].buf = buf;
        data[i].start = i * (st.st_size / NR_THREADS);
        data[i].len = (st.st_size / NR_THREADS) - 1;
        sem_init(&data[i].sem, 0, 0);
    }

    for (i = 0; i < NR_THREADS; i++) {
        if (pthread_create(&tid[i], NULL, thread_func, &data[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    for (i = 0; i < NR_THREADS; i++) {
        sem_wait(&data[i].sem);
        sem_destroy(&data[i].sem);
    }

    for (i = 0; i < NR_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    free(buf);
    close(fd);
    return 0;
}