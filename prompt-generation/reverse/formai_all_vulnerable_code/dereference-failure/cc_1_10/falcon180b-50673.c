//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define STACK_SIZE (1024 * 1024)

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    char thread_name[16];
    sprintf(thread_name, "thread_%d", thread_id);
    printf("Hello from thread %s!\n", thread_name);
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
            printf("ERROR: unable to init thread, %d\n", rc);
            exit(-1);
        }
        stack_size = STACK_SIZE;
        printf("Thread %d stack size: %zu bytes\n", i, stack_size);
        rc = pthread_attr_setstacksize(stack, stack_size);
        if (rc) {
            printf("ERROR: unable to set thread stack size, %d\n", rc);
            exit(-1);
        }
        rc = pthread_create(&threads[i], stack, thread_func, (void *) i);
        if (rc) {
            printf("ERROR: unable to create thread, %d\n", rc);
            exit(-1);
        }
        printf("Created thread %d\n", i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: unable to join with thread %d, %d\n", i, rc);
            exit(-1);
        }
        printf("Joined with thread %d\n", i);
    }

    return 0;
}