//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int num_elements;
    int* data;
    int* result;
} thread_data_t;

void* compute_sum(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    int start = data->num_elements * data->thread_id;
    int end = start + data->num_elements - 1;
    int sum = 0;

    for (int i = start; i <= end; i++) {
        sum += data->data[i];
    }

    data->result[data->thread_id] = sum;
    pthread_exit(NULL);
}

int main() {
    int num_threads = NUM_THREADS;
    int num_elements = 100000000;
    int* data = malloc(num_elements * sizeof(int));
    int* results = malloc(num_threads * sizeof(int));
    pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
    thread_data_t* thread_data = malloc(num_threads * sizeof(thread_data_t));
    bool should_consolidate_results = false;

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < num_elements; i++) {
        data[i] = rand() % 100;
    }

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].num_elements = num_elements / num_threads;
        thread_data[i].data = data;
        thread_data[i].result = results;

        int rc = pthread_create(&threads[i], NULL, compute_sum, (void*) &thread_data[i]);

        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    int sum = 0;

    if (should_consolidate_results) {
        for (int i = 0; i < num_threads; i++) {
            sum += results[i];
        }
    } else {
        for (int i = 0; i < num_elements; i++) {
            sum += data[i];
        }
    }

    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000.0);
    printf("Total sum: %d\n", sum);
    printf("Time taken: %f seconds\n", time_taken);

    free(data);
    free(results);
    free(threads);
    free(thread_data);

    pthread_exit(NULL);
}