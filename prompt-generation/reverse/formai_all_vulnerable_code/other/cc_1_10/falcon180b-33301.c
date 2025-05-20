//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_THREADS 5
#define NUM_SEMAPHORES 2
#define NUM_ITERATIONS 10

sem_t semaphores[NUM_SEMAPHORES];
int shared_data = 0;

void init_semaphores() {
    int i;
    for (i = 0; i < NUM_SEMAPHORES; i++) {
        sem_init(&semaphores[i], 0, 1);
    }
}

void *thread_func(void *arg) {
    int id = *(int *) arg;
    int i;

    for (i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&semaphores[id % NUM_SEMAPHORES]);
        shared_data++;
        printf("Thread %d incremented shared_data to %d\n", id, shared_data);
        sem_post(&semaphores[id % NUM_SEMAPHORES]);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    init_semaphores();

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) i);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}