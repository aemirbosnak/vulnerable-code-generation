//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_THREADS 10
#define NUM_ITERATIONS 1000

typedef struct {
    int id;
    int count;
} thread_data_t;

sem_t thread_sem;

void *thread_func(void *arg) {
    int id = *(int *) arg;
    thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
    data->id = id;
    data->count = 0;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&thread_sem);
        data->count++;
        printf("Thread %d completed iteration %d\n", id, i);
        sem_post(&thread_sem);
    }

    free(data);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t *data[NUM_THREADS];

    sem_init(&thread_sem, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i] = (thread_data_t *) malloc(sizeof(thread_data_t));
        data[i]->id = i;
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&thread_sem);

    return 0;
}