//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024
#define THREAD_COUNT 4

typedef struct {
    char *data;
    size_t size;
} buffer_t;

typedef struct {
    buffer_t *buffers;
    size_t buffer_count;
    size_t total_size;
} compression_data_t;

void *compression_thread(void *arg) {
    compression_data_t *data = arg;
    size_t i, j;
    char *buffer;

    for (i = 0; i < THREAD_COUNT; i++) {
        buffer = data->buffers[i].data;
        for (j = 0; j < data->buffers[i].size; j++) {
            if (buffer[j] == 'a' || buffer[j] == 'e' || buffer[j] == 'i' || buffer[j] == 'o' || buffer[j] == 'u') {
                buffer[j] = '4';
            } else if (buffer[j] == 'A' || buffer[j] == 'E' || buffer[j] == 'I' || buffer[j] == 'O' || buffer[j] == 'U') {
                buffer[j] = '4';
            }
        }
    }

    return NULL;
}

int main() {
    compression_data_t data;
    data.buffers = calloc(THREAD_COUNT, sizeof(buffer_t));
    data.buffer_count = THREAD_COUNT;
    data.total_size = 0;

    for (size_t i = 0; i < THREAD_COUNT; i++) {
        data.buffers[i].data = calloc(BUFFER_SIZE, sizeof(char));
        data.buffers[i].size = BUFFER_SIZE;
        data.total_size += data.buffers[i].size;
    }

    pthread_t threads[THREAD_COUNT];

    for (size_t i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, compression_thread, &data);
    }

    sem_t sem;
    sem_init(&sem, 0, THREAD_COUNT);

    for (size_t i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);

    return 0;
}