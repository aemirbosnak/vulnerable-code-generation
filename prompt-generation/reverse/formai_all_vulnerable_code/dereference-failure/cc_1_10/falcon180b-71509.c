//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_ELEMENTS 1000000
#define NUM_BUCKETS 10
#define NUM_THREADS 10

typedef struct {
    int start;
    int end;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j, index;
    int count[NUM_BUCKETS] = { 0 };

    for (i = data->start; i <= data->end; i++) {
        index = (int) ((float) i / MAX_ELEMENTS * NUM_BUCKETS);
        count[index]++;
    }

    for (i = 0; i < NUM_BUCKETS; i++) {
        if (count[i] > 0) {
            for (j = 0; j < count[i]; j++) {
                fprintf(stdout, "%d ", i * (MAX_ELEMENTS / NUM_BUCKETS) + j * (MAX_ELEMENTS / NUM_BUCKETS) + 1);
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, j, index;
    int count[NUM_BUCKETS] = { 0 };
    int *arr = (int *) malloc(MAX_ELEMENTS * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < MAX_ELEMENTS; i++) {
        arr[i] = rand() % MAX_ELEMENTS;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_t data;
        data.start = i * MAX_ELEMENTS / NUM_THREADS;
        data.end = (i == NUM_THREADS - 1)? MAX_ELEMENTS : (i + 1) * MAX_ELEMENTS / NUM_THREADS;
        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(arr);

    return 0;
}