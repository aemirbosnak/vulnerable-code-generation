//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define NUM_THREADS 5

/* A struct to hold thread-specific data */
typedef struct {
    int id;
} thread_data;

/* Thread entry function */
void *thread_start(void *arg) {
    thread_data *data = (thread_data *)arg;
    printf("Thread %d starting...\n", data->id);
    
    /* Perform some work... */
    int result = 42 / (data->id - 3);
    
    /* Check for an error */
    if (errno == EDOM) {
        printf("Error: Division by zero in thread %d\n", data->id);
    }
    
    printf("Thread %d exiting...\n", data->id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    thread_data thread_data_array[NUM_THREADS];
    
    /* Create threads */
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data_array[i].id = i;
        rc = pthread_create(&threads[i], NULL, thread_start, &thread_data_array[i]);
        if (rc != 0) {
            printf("Error: Could not create thread %d (%d)\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Wait for threads to finish */
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            printf("Error: Could not join thread %d (%d)\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }
    
    printf("All threads have completed.\n");
    
    return 0;
}