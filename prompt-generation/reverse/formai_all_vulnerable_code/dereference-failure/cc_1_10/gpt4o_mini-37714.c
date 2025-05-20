//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define NUM_THREADS 4

typedef struct {
    int *array;
    int start;
    int end;
    long sum;
} ThreadData;

void *calculate_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;
    
    for (int i = data->start; i < data->end; i++) {
        data->sum += data->array[i];
    }
    
    return NULL;
}

int main() {
    int *array = malloc(ARRAY_SIZE * sizeof(int));
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    long total_sum = 0;

    // Initialize the array with values from 1 to ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;  // Fill with values 1 to ARRAY_SIZE
    }

    int chunk_size = ARRAY_SIZE / NUM_THREADS;
    
    // Create threads to calculate the sum of array chunks
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].array = array;
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
        
        // Create a new thread
        if (pthread_create(&threads[i], NULL, calculate_sum, (void *)&thread_data[i]) != 0) {
            perror("Failed to create thread");
            free(array);
            return EXIT_FAILURE;
        }
    }

    // Join threads and collect their results
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }

    printf("Total Sum of array: %ld\n", total_sum);

    // Clean up
    free(array);
    return EXIT_SUCCESS;
}