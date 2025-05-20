//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A structure to hold the arguments to the thread function
typedef struct {
    int tid;        // The thread ID
    int num;        // The number of seconds to sleep
} thread_args;

// The thread function
void *thread_function(void *args) {
    thread_args *arg = (thread_args *)args;

    // Print the thread ID and the number of seconds to sleep
    printf("Thread %d sleeping for %d seconds\n", arg->tid, arg->num);

    // Sleep for the specified number of seconds
    sleep(arg->num);

    // Print a message indicating that the thread has finished sleeping
    printf("Thread %d finished sleeping\n", arg->tid);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num_threads> <num_seconds>\n", argv[0]);
        return 1;
    }

    // Get the number of threads and the number of seconds to sleep
    int num_threads = atoi(argv[1]);
    int num_seconds = atoi(argv[2]);

    // Create an array of thread handles
    pthread_t *threads = malloc(sizeof(pthread_t) * num_threads);

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        thread_args *args = malloc(sizeof(thread_args));
        args->tid = i;
        args->num = num_seconds;
        pthread_create(&threads[i], NULL, thread_function, (void *)args);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the memory allocated for the thread handles
    free(threads);

    return 0;
}