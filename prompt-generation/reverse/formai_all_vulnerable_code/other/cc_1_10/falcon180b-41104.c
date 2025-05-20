//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_VALUE 100

int shared_value = 0;

sem_t mutex;
sem_t write_lock;

void init_mutex() {
    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);
}

void destroy_mutex() {
    sem_destroy(&mutex);
    sem_destroy(&write_lock);
}

void write_shared_value(int value) {
    sem_wait(&write_lock);
    shared_value = value;
    printf("Shared value updated to %d\n", shared_value);
    sem_post(&write_lock);
    sem_post(&mutex);
}

void read_shared_value() {
    sem_wait(&mutex);
    printf("Shared value is %d\n", shared_value);
    sem_post(&mutex);
}

void *thread_func(void *arg) {
    int id = (int) arg;
    int value = id * 10;

    printf("Thread %d starting with value %d\n", id, value);

    for (int i = 0; i < 10; i++) {
        write_shared_value(value + i);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = rand() % MAX_VALUE;
        printf("Creating thread %d with id %d\n", i, ids[i]);
        pthread_create(&threads[i], NULL, thread_func, (void *) ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    destroy_mutex();

    return 0;
}