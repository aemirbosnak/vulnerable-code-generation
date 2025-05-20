//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5
#define BUFFER_SIZE 10

typedef struct {
    int id;
    char name[20];
    int *buffer;
    pthread_mutex_t *mutex;
    pthread_cond_t *cond;
} thread_data_t;

void *producer(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(data->mutex);
        while (data->buffer[data->id] != -1) {
            pthread_cond_wait(data->cond, data->mutex);
        }
        data->buffer[data->id] = i;
        printf("Producer %s produced %d\n", data->name, i);
        pthread_cond_broadcast(data->cond);
        pthread_mutex_unlock(data->mutex);
        sleep(rand() % 2);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        pthread_mutex_lock(data->mutex);
        while (data->buffer[data->id] == -1) {
            pthread_cond_wait(data->cond, data->mutex);
        }
        printf("Consumer %s consumed %d\n", data->name, data->buffer[data->id]);
        data->buffer[data->id] = -1;   // Mark the buffer as empty
        pthread_cond_broadcast(data->cond);
        pthread_mutex_unlock(data->mutex);
        sleep(rand() % 2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int *buffer = malloc(NUM_THREADS * sizeof(int));

    for (int i = 0; i < NUM_THREADS; i++) {
        buffer[i] = -1; // Initialize buffer to -1 (empty)
    }

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        sprintf(thread_data[i].name, "Thread-%d", i);
        thread_data[i].id = i;
        thread_data[i].buffer = buffer;
        thread_data[i].mutex = &mutex;
        thread_data[i].cond = &cond;

        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, producer, (void *)&thread_data[i]);
        } else {
            pthread_create(&threads[i], NULL, consumer, (void *)&thread_data[i]);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(buffer);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}