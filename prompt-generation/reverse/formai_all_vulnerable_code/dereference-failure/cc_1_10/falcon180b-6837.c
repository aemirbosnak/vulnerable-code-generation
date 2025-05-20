//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// global data
int num_loans = 0;
int max_loans = 100;

// function prototypes
void *thread_func(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }

    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of loans processed: %d\n", num_loans);

    return 0;
}

// thread function
void *thread_func(void *arg) {
    int id = *(int *)arg;
    int num_loans_processed = 0;

    // simulate mortgage processing
    while (num_loans_processed < 10 && num_loans < max_loans) {
        pthread_mutex_lock(&mutex);
        num_loans++;
        pthread_mutex_unlock(&mutex);
        num_loans_processed++;
        sleep(1);
    }

    pthread_exit(NULL);
}