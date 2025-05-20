//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;

    // create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        if (rc) {
            fprintf(stderr, "Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
        thread_ids[i] = i;
    }

    // join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("Main thread exiting...\n");
    return 0;
}

void *thread_func(void *param) {
    int thread_id = *(int *)param;

    printf("Thread %d starting...\n", thread_id);

    // do some work
    for (int i = 0; i < 10; i++) {
        printf("Thread %d is working...\n", thread_id);
        sleep(1);
    }

    printf("Thread %d exiting...\n", thread_id);
    return NULL;
}