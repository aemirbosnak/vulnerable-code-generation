//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define NUM_THREADS 4

struct thread_data {
    int *array;
    int start_index;
    int end_index;
    long sum;
};

void *calculate_sum(void *threadarg) {
    struct thread_data *data = (struct thread_data *)threadarg;
    long sum = 0;

    for (int i = data->start_index; i < data->end_index; i++) {
        sum += data->array[i];
    }

    data->sum = sum;
    pthread_exit(NULL);
}

int main() {
    // Initialize the array with some arbitrary values
    int *array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;  // Filling the array with values from 1 to ARRAY_SIZE
    }

    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_array[NUM_THREADS];
    int segment_size = ARRAY_SIZE / NUM_THREADS;

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_array[i].array = array;
        thread_data_array[i].start_index = i * segment_size;
        thread_data_array[i].end_index = (i + 1) * segment_size;

        if (i == NUM_THREADS - 1) { // Last segment takes the remainder
            thread_data_array[i].end_index = ARRAY_SIZE;
        }

        pthread_create(&threads[i], NULL, calculate_sum, (void *)&thread_data_array[i]);
    }

    // Wait for threads to finish and accumulate the sum
    long total_sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data_array[i].sum; // Sum the results from each thread
    }

    printf("The total sum of the array is: %ld\n", total_sum);

    // Free the allocated memory
    free(array);
    
    return 0;
}