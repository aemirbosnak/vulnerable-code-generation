//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BLOCK_SIZE 512

typedef struct {
    int fd;
    off_t offset;
    size_t size;
    char *buffer;
} block_t;

typedef struct {
    sem_t semaphore;
    pthread_t thread;
    block_t *block;
} thread_data_t;

void *read_block(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    ssize_t bytes_read = read(data->block->fd, data->block->buffer, data->block->size);
    if (bytes_read < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    sem_post(&data->semaphore);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat input_stat;
    if (fstat(input_fd, &input_stat) < 0) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    size_t num_blocks = input_stat.st_size / BLOCK_SIZE;
    if (input_stat.st_size % BLOCK_SIZE != 0) {
        num_blocks++;
    }

    block_t *blocks = malloc(sizeof(block_t) * num_blocks);
    if (blocks == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < num_blocks; i++) {
        blocks[i].fd = input_fd;
        blocks[i].offset = i * BLOCK_SIZE;
        blocks[i].size = BLOCK_SIZE;
        blocks[i].buffer = malloc(BLOCK_SIZE);
        if (blocks[i].buffer == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    thread_data_t *threads = malloc(sizeof(thread_data_t) * num_blocks);
    if (threads == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < num_blocks; i++) {
        sem_init(&threads[i].semaphore, 0, 0);
        threads[i].block = &blocks[i];
        if (pthread_create(&threads[i].thread, NULL, read_block, &threads[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (size_t i = 0; i < num_blocks; i++) {
        sem_wait(&threads[i].semaphore);
        if (write(output_fd, blocks[i].buffer, blocks[i].size) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        free(blocks[i].buffer);
        pthread_join(threads[i].thread, NULL);
        sem_destroy(&threads[i].semaphore);
    }

    free(blocks);
    free(threads);
    close(input_fd);
    close(output_fd);

    return 0;
}