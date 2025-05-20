//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

// Define struct to hold thread-specific data
typedef struct {
    int thread_id;
    int *array;
    int array_size;
} thread_data;

void *thread_function(void *arg) {
    // Retrieve thread-specific data from argument
    thread_data *data = (thread_data*) arg;
    int thread_id = data->thread_id;
    int *array = data->array;
    int array_size = data->array_size;
    
    // Calculate start and end indices for this thread's subset of array
    int start_index = thread_id * (array_size / MAX_THREADS);
    int end_index = (thread_id + 1) * (array_size / MAX_THREADS);
    if (thread_id == (MAX_THREADS - 1)) {
        end_index = array_size;
    }
    
    // Perform some operation on this thread's subset of array
    for (int i = start_index; i < end_index; i++) {
        array[i] += thread_id;
    }
    
    printf("Thread %d processed indices %d through %d.\n", thread_id, start_index, end_index - 1);
    
    // Free memory allocated for thread-specific data
    free(data);
    
    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Declare and initialize array
    int array_size = 1000000;
    int *array = malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++) {
        array[i] = i;
    }
    
    // Declare array of thread IDs and create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        // Allocate memory for thread-specific data
        thread_data *data = malloc(sizeof(thread_data));
        data->thread_id = i;
        data->array = array;
        data->array_size = array_size;
        
        // Create thread
        if (pthread_create(&threads[i], NULL, thread_function, (void*) data) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }
    
    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
    }
    
    // Print first and last 10 elements of modified array
    printf("First 10 elements of modified array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("Last 10 elements of modified array:\n");
    for (int i = array_size - 10; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free memory allocated for array
    free(array);
    
    return 0;
}