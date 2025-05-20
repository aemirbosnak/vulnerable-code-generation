//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define STACK_SIZE 1024 * 1024

void *thread_func(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started\n", id);
    sleep(1);
    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    void *stack;
    size_t stack_size;

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_attr_init(&stack);
        if (rc) {
            fprintf(stderr, "Error initializing thread attributes: %d\n", rc);
            exit(1);
        }

        rc = pthread_attr_setstacksize(stack, STACK_SIZE);
        if (rc) {
            fprintf(stderr, "Error setting stack size: %d\n", rc);
            exit(1);
        }

        rc = pthread_create(&threads[i], stack, thread_func, (void *) i);
        if (rc) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &stack);
        if (rc) {
            fprintf(stderr, "Error joining thread: %d\n", rc);
            exit(1);
        }
    }

    return 0;
}