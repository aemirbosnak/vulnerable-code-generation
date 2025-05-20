//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

struct thread_data {
    int thread_id;
    int *shared_memory;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int *shared_memory = data->shared_memory;

    int thread_id = data->thread_id;
    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < 100000; i++) {
        (*shared_memory)++;
    }

    printf("Thread %d finished\n", thread_id);
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int shared_memory = 0;

    int rc;
    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->shared_memory = &shared_memory;

        rc = pthread_create(&threads[i], NULL, thread_func, (void *) data);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Shared memory value: %d\n", shared_memory);
    return 0;
}