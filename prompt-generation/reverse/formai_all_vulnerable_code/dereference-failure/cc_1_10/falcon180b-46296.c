//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#define NUM_THREADS 4
#define NUM_BLOCKS 10
#define BLOCK_SIZE 100

typedef struct {
    int id;
    int block_size;
    int num_blocks;
    int *blocks;
} thread_data;

sem_t mutex;

void *thread_func(void *arg) {
    thread_data *data = arg;
    int i;
    for (i = 0; i < data->num_blocks; i++) {
        sem_wait(&mutex);
        printf("Thread %d allocating block %d\n", data->id, i);
        data->blocks[i] = malloc(data->block_size);
        if (data->blocks[i] == NULL) {
            printf("Thread %d failed to allocate block %d\n", data->id, i);
            exit(1);
        }
        printf("Thread %d allocated block %d\n", data->id, i);
        sem_post(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].block_size = BLOCK_SIZE;
        data[i].num_blocks = NUM_BLOCKS / NUM_THREADS;
        data[i].blocks = malloc(data[i].num_blocks * sizeof(int *));
        if (data[i].blocks == NULL) {
            printf("Failed to allocate memory for thread %d\n", i);
            exit(1);
        }
        for (int j = 0; j < data[i].num_blocks; j++) {
            data[i].blocks[j] = NULL;
        }
    }
    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < data[i].num_blocks; j++) {
            free(data[i].blocks[j]);
        }
        free(data[i].blocks);
    }
    sem_destroy(&mutex);
    return 0;
}