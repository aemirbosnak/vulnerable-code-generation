//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <stdio.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

// Define the thread function prototype
void *thread_func(void *arg);

// Define the main function
int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    // Create the threads
    for (i = 0; i < MAX_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->id = i + 1;
        data->func = &thread_func;
        data->arg = NULL;
        pthread_create(&threads[i], NULL, &thread_func, data);
    }

    // Join the threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Define the thread function
void *thread_func(void *arg) {
    thread_data_t *data = arg;
    int id = data->id;

    // Print the thread ID
    printf("Thread %d started.\n", id);

    // Sleep for a random amount of time
    usleep(rand() % 1000000);

    // Print the thread ID again
    printf("Thread %d finished.\n", id);

    // Free the thread data
    free(data);

    return NULL;
}