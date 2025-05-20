//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#define NUM_THREADS 10
#define NUM_LOOPS 10000000

int shared_var = 0;
sem_t mutex;

void init_mutex() {
    if (sem_init(&mutex, 0, 1) == -1) {
        fprintf(stderr, "Error initializing mutex: %s\n", strerror(errno));
        exit(1);
    }
}

void lock_mutex() {
    if (sem_wait(&mutex) == -1) {
        fprintf(stderr, "Error locking mutex: %s\n", strerror(errno));
        exit(1);
    }
}

void unlock_mutex() {
    if (sem_post(&mutex) == -1) {
        fprintf(stderr, "Error unlocking mutex: %s\n", strerror(errno));
        exit(1);
    }
}

void *thread_func(void *arg) {
    int thread_id = (int) arg;
    for (int i = 0; i < NUM_LOOPS; i++) {
        lock_mutex();
        shared_var++;
        printf("Thread %d incremented shared_var to %d\n", thread_id, shared_var);
        unlock_mutex();
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) i);
        if (rc) {
            fprintf(stderr, "Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}