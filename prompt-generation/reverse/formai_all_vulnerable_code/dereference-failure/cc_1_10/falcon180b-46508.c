//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define STACK_SIZE 1024

void *runner(void *param);

int main(int argc, char **argv) {

    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    // Initialize random seed
    srand(time(NULL));

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, (void *)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join with threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads completed successfully.\n");

    return 0;
}

void *runner(void *param) {

    int *id = param;
    int i;

    printf("Thread %d started.\n", *id);

    // Simulate some work
    for (i = 0; i < 10; i++) {
        printf("Thread %d is working...\n", *id);
        sleep(rand() % 3);
    }

    printf("Thread %d completed.\n", *id);

    return NULL;
}