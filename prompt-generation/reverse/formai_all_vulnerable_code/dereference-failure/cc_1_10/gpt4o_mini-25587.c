//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 4
#define NUM_ITEMS 20

typedef struct {
    int thread_id;
    int *data;
    int start_index;
    int end_index;
} thread_data_t;

void *process_data(void *thread_arg) {
    thread_data_t *data = (thread_data_t *)thread_arg;
    int thread_id = data->thread_id;
    int *data_array = data->data;
    int start = data->start_index;
    int end = data->end_index;

    printf("Thread %d processing items from %d to %d...\n", thread_id, start, end);
    for (int i = start; i < end; ++i) {
        // Simulate data processing by squaring the value
        data_array[i] = data_array[i] * data_array[i];
        usleep(100000); // Sleep for 100ms to simulate processing time
    }

    printf("Thread %d finished processing.\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    int *data = malloc(NUM_ITEMS * sizeof(int));

    // Initialize the data
    for (int i = 0; i < NUM_ITEMS; ++i) {
        data[i] = i + 1; // Data items will be 1, 2, 3, ..., 20
    }

    // Create threads to process data
    for (int t = 0; t < NUM_THREADS; ++t) {
        thread_data[t].thread_id = t;
        thread_data[t].data = data;
        thread_data[t].start_index = t * (NUM_ITEMS / NUM_THREADS);
        thread_data[t].end_index = (t + 1) * (NUM_ITEMS / NUM_THREADS);
        
        // Create a thread to process the data
        if (pthread_create(&threads[t], NULL, process_data, (void *)&thread_data[t]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int t = 0; t < NUM_THREADS; ++t) {
        pthread_join(threads[t], NULL);
    }

    // Display processed data
    printf("Processed data:\n");
    for (int i = 0; i < NUM_ITEMS; ++i) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Cleanup
    free(data);
    return 0;
}