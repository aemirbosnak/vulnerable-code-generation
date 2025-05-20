//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_THREADS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int fd;
    char *buffer;
    size_t size;
} thread_data_t;

void *thread_func(void *data) {
    thread_data_t *td = data;
    size_t bytes_read = 0;

    while (1) {
        ssize_t read_size = read(td->fd, td->buffer, td->size);
        if (read_size < 0) {
            break;
        }
        bytes_read += read_size;
        if (bytes_read >= td->size) {
            break;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <num_threads>\n", argv[0]);
        return 1;
    }

    int file_fd = open(argv[1], O_RDONLY);
    if (file_fd < 0) {
        perror("open");
        return 1;
    }

    size_t file_size = lseek(file_fd, 0, SEEK_END);
    if (file_size < 0) {
        perror("lseek");
        return 1;
    }

    size_t buffer_size = MAX_BUFFER_SIZE;
    char *buffer = malloc(buffer_size);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    pthread_t *threads = calloc(MAX_THREADS, sizeof(pthread_t));
    if (threads == NULL) {
        perror("calloc");
        return 1;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data_t *td = calloc(1, sizeof(thread_data_t));
        td->fd = file_fd;
        td->buffer = buffer;
        td->size = buffer_size;
        pthread_create(&threads[i], NULL, thread_func, td);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(buffer);
    free(threads);

    return 0;
}