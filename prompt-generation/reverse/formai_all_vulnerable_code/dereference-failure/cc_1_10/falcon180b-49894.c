//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_OPERATIONS 1000000

void *runner(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;

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
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    int count = 0;
    int thread_id = *(int *)param;

    while (count < NUM_OPERATIONS) {
        // Perform bitwise operations
        int a = rand() % 256;
        int b = rand() % 256;
        int result;

        result = a & b;
        count++;

        result = a | b;
        count++;

        result = a ^ b;
        count++;

        result = ~a;
        count++;

        result = a << 1;
        count++;

        result = a >> 1;
        count++;

        // Print thread ID and operation result
        printf("Thread %d performed %d bitwise operations\n", thread_id, count);
    }

    return NULL;
}