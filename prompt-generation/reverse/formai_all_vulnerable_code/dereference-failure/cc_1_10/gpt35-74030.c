//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 10000000
#define BLOCK_SIZE (ARRAY_SIZE / NUM_THREADS)

typedef struct {
    int *array;
    int start_index;
    int end_index;
} ThreadArgs;

void *partial_sum(void *args) {
    ThreadArgs *targs = (ThreadArgs *) args;
    int *array = targs->array;
    int start_index = targs->start_index;
    int end_index = targs->end_index;

    for (int i = start_index; i < end_index; i++) {
        array[i+1] += array[i];
    }

    pthread_exit(NULL);
}

int main() {
    int *array = (int *) malloc(sizeof(int) * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    pthread_t threads[NUM_THREADS];
    ThreadArgs targs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        targs[i].array = array;
        targs[i].start_index = i * BLOCK_SIZE;
        targs[i].end_index = (i + 1) * BLOCK_SIZE;
        pthread_create(&threads[i], NULL, partial_sum, (void *) &targs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 1; i < ARRAY_SIZE; i++) {
        array[i] += array[i-1];
    }

    printf("Result:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}