//FormAI DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ARRAY_SIZE 10

int data[ARRAY_SIZE] = {17, 5, 15, 6, 10, 18, 3, 9, 4, 1};

struct thread_args {
    int id;
    int start_index;
    int end_index;
};

void *sum(void* arg) {
    struct thread_args *args = (struct thread_args*) arg;
    int thread_id = args->id;
    int start_index = args->start_index;
    int end_index = args->end_index;

    int thread_sum = 0;
    for(int i = start_index; i < end_index; i++) {
        thread_sum += data[i];
    }

    printf("Thread %d: Sum = %d\n", thread_id, thread_sum);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Divide the array into equal parts for each thread.
    int num_elements_per_thread = ARRAY_SIZE / NUM_THREADS;
    for(int i = 0; i < NUM_THREADS; i++) {
        struct thread_args *args = (struct thread_args*) malloc(sizeof(struct thread_args));
        args->id = i;
        args->start_index = i * num_elements_per_thread;
        if(i == NUM_THREADS - 1) {
            args->end_index = ARRAY_SIZE;
        } else {
            args->end_index = args->start_index + num_elements_per_thread;
        }

        rc = pthread_create(&threads[i], NULL, sum, args);
        if(rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}