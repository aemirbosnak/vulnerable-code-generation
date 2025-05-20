//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

// Define the thread function
void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    data->func(data->arg);
    return NULL;
}

// Define the main function
int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int i, ret;

    // Create the threads
    for (i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].func = &thread_func;
        data[i].arg = &i;
        ret = pthread_create(&threads[i], NULL, &thread_func, &data[i]);
        if (ret!= 0) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    // Join the threads
    for (i = 0; i < MAX_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret!= 0) {
            printf("Error joining thread %d\n", i);
            return 1;
        }
    }

    return 0;
}