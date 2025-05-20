//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define DATA_SIZE 1000000

typedef struct {
    int thread_id;
    int start_index;
    int end_index;
} thread_data_t;

unsigned int data[DATA_SIZE];

void *thread_func(void *arg) {
    thread_data_t *thread_data = arg;
    int thread_id = thread_data->thread_id;
    int start_index = thread_data->start_index;
    int end_index = thread_data->end_index;

    for (int i = start_index; i < end_index; i++) {
        data[i] ^= (thread_id << 16) | (thread_id >> 16);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t thread_data;
        thread_data.thread_id = i;
        thread_data.start_index = i * DATA_SIZE / NUM_THREADS;
        thread_data.end_index = (i + 1) * DATA_SIZE / NUM_THREADS;

        int rc = pthread_create(&threads[i], NULL, thread_func, &thread_data);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
    }

    int result = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        result ^= data[i];
    }

    printf("Result: %X\n", result);

    return 0;
}