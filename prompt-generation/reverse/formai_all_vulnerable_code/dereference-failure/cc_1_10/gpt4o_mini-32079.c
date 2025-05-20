//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define NUM_TASKS 10

typedef struct {
    int thread_id;
    int task_id;
} thread_data;

pthread_mutex_t mutex;
int tasks[NUM_TASKS] = {0};

void* perform_task(void* threadarg) {
    thread_data* data = (thread_data*) threadarg;
    int thread_id = data->thread_id;
    int task_id = data->task_id;

    free(data); // Free the allocated structure

    // Simulate processing time
    srand(time(NULL) + thread_id);
    int processing_time = rand() % 3 + 1; // 1 to 3 seconds

    printf("Thread %d: Starting task %d. Processing time: %d seconds\n", thread_id, task_id, processing_time);
    sleep(processing_time);

    // Lock the mutex while updating shared resource
    pthread_mutex_lock(&mutex);
    tasks[task_id] = thread_id; // Assign task to the thread
    pthread_mutex_unlock(&mutex);

    printf("Thread %d: Completed task %d\n", thread_id, task_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    
    for (int i = 0; i < NUM_TASKS; i++) {
        // Create thread data structure
        thread_data* data = malloc(sizeof(thread_data));
        data->task_id = i;
        data->thread_id = i % NUM_THREADS; // Assign task to thread based on id

        // Create a new thread
        int rc = pthread_create(&threads[data->thread_id], NULL, perform_task, (void*) data);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", data->thread_id, rc);
            free(data);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output the results
    printf("Final task assignments:\n");
    for (int i = 0; i < NUM_TASKS; i++) {
        printf("Task %d assigned to thread %d\n", i, tasks[i]);
    }

    pthread_mutex_destroy(&mutex);
    return EXIT_SUCCESS;
}