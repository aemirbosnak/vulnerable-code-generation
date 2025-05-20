//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold thread-specific data
typedef struct thread_data {
    int thread_id;
    int num_tasks;
    int *tasks;
} thread_data_t;

// Thread function to perform tasks
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Perform the tasks assigned to this thread
    for (int i = 0; i < data->num_tasks; i++) {
        // Do something with the task
        printf("Thread %d: Performing task %d\n", data->thread_id, data->tasks[i]);
    }

    // Free the memory allocated for the thread-specific data
    free(data->tasks);
    free(data);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num_threads> <num_tasks>\n", argv[0]);
        return 1;
    }

    // Get the number of threads and tasks from the command line arguments
    int num_threads = atoi(argv[1]);
    int num_tasks = atoi(argv[2]);

    // Create an array of thread identifiers
    pthread_t threads[num_threads];

    // Create an array of thread-specific data structures
    thread_data_t *data[num_threads];

    // Create tasks for each thread
    for (int i = 0; i < num_threads; i++) {
        // Allocate memory for the thread-specific data
        data[i] = malloc(sizeof(thread_data_t));

        // Initialize the thread-specific data
        data[i]->thread_id = i;
        data[i]->num_tasks = num_tasks / num_threads;
        data[i]->tasks = malloc(sizeof(int) * data[i]->num_tasks);

        // Initialize the tasks for this thread
        for (int j = 0; j < data[i]->num_tasks; j++) {
            data[i]->tasks[j] = i * data[i]->num_tasks + j;
        }
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the memory allocated for the thread-specific data
    for (int i = 0; i < num_threads; i++) {
        free(data[i]);
    }

    return 0;
}