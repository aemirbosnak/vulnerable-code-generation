//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread data structure
typedef struct {
    char* input_string;
    char* output_string;
} thread_data;

// Function to be executed by each thread
void* process_string(void* arg) {
    thread_data* data = (thread_data*) arg;

    // Lock the mutex before accessing shared data
    pthread_mutex_lock(&mutex);

    // Reverse the input string
    char* temp = data->input_string;
    data->input_string = data->output_string;
    data->output_string = temp;

    // Unlock the mutex after accessing shared data
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    // Initialize random input strings
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].input_string = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
        data[i].output_string = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));

        sprintf(data[i].input_string, "Thread %d input string", i);
        strcpy(data[i].output_string, "");
    }

    // Create threads and pass thread data as argument
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, process_string, &data[i]);
    }

    // Join threads and print output strings
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);

        printf("Thread %d output string: %s\n", i, data[i].output_string);
    }

    return 0;
}