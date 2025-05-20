//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold the data for each thread
typedef struct thread_data_t {
    int thread_id;
    int *array;
    int size;
} thread_data_t;

// Function to be executed by each thread
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sum = 0;

    // Calculate the sum of the elements in the array
    for (int i = 0; i < data->size; i++) {
        sum += data->array[i];
    }

    // Return the sum
    return (void *)sum;
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number of threads> <size of array>\n", argv[0]);
        return 1;
    }

    // Get the number of threads and the size of the array
    int num_threads = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Create the array
    int *array = malloc(sizeof(int) * size);
    if (array == NULL) {
        fprintf(stderr, "Error allocating memory for array\n");
        return 1;
    }

    // Initialize the array with random numbers
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Create the thread data structures
    thread_data_t data[num_threads];
    for (int i = 0; i < num_threads; i++) {
        data[i].thread_id = i;
        data[i].array = array;
        data[i].size = size / num_threads;
    }

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for the threads to finish
    int sums[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], (void **)&sums[i]);
    }

    // Calculate the total sum
    int total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        total_sum += sums[i];
    }

    // Print the total sum
    printf("Total sum: %d\n", total_sum);

    // Free the array
    free(array);

    return 0;
}