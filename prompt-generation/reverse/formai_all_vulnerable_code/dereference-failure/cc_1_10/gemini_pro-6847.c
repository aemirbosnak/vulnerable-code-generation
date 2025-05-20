//GEMINI-pro DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int id;
    int* data;
    int size;
} thread_data_t;

void* thread_proc(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;

    // Process the data
    for (int i = 0; i < data->size; i++) {
        data->data[i] *= data->id;
    }

    // Wait for a random amount of time to simulate workload
    sleep(rand() % 5);

    // Signal that the thread has finished
    pthread_exit((void*)data->id);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create an array of random numbers
    int num_threads = 4;
    int data_size = 1000000;
    int* data = malloc(sizeof(int) * data_size);
    for (int i = 0; i < data_size; i++) {
        data[i] = rand();
    }

    // Create an array of thread data structs
    thread_data_t* thread_data = malloc(sizeof(thread_data_t) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].id = i;
        thread_data[i].data = data;
        thread_data[i].size = data_size;
    }

    // Create the threads
    pthread_t* threads = malloc(sizeof(pthread_t) * num_threads);
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_proc, &thread_data[i]);
    }

    // Wait for the threads to finish
    int status;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], (void**)&status);
    }

    // Print the modified data
    for (int i = 0; i < data_size; i++) {
        printf("%d\n", data[i]);
    }

    // Free the allocated memory
    free(data);
    free(thread_data);
    free(threads);

    return 0;
}