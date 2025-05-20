//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define the number of threads to create */
#define NUM_THREADS 5

/* Define a struct to store the thread's ID and name */
typedef struct {
    int id;
    char* name;
} thread_data;

/* This function will be executed by each thread */
void* thread_function(void* arg) {
    thread_data* data = (thread_data*) arg;

    printf("Hello, I am thread %d with the name '%s'\n", data->id, data->name);

    /* Do some work, like sleeping for a random amount of time */
    int sleep_time = rand() % 5;
    printf("Thread %d is sleeping for %d seconds\n", data->id, sleep_time);
    sleep(sleep_time);

    printf("Thread %d is done\n", data->id);

    /* Exit the thread */
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data* data_array[NUM_THREADS];

    /* Create an array of thread data */
    char* names[NUM_THREADS] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data* data = malloc(sizeof(thread_data));
        data->id = i;
        data->name = names[i];
        data_array[i] = data;
    }

    /* Create the threads */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*) data_array[i]);
    }

    /* Wait for the threads to finish */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Free the thread data */
    for (int i = 0; i < NUM_THREADS; i++) {
        free(data_array[i]);
    }

    printf("All done!\n");

    /* Exit the main thread */
    pthread_exit(NULL);
}