//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_THREADS 10

typedef struct {
    int thread_id;
    int sleep_time;
    char message[256];
} thread_data_t;

void* thread_function(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;

    printf("Thread %d started. Message: %s\n", data->thread_id, data->message);
    sleep(data->sleep_time);
    printf("Thread %d finished after %d seconds.\n", data->thread_id, data->sleep_time);

    pthread_exit(NULL);
}

void create_threads(int num_threads, int sleep_time, const char* message) {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].sleep_time = sleep_time;
        strncpy(thread_data[i].message, message, sizeof(thread_data[i].message) - 1);
        thread_data[i].message[sizeof(thread_data[i].message) - 1] = '\0'; // Ensure null termination

        int rc = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_data[i]);
        if (rc) {
            printf("Error: unable to create thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <num_threads> <sleep_time> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_threads = atoi(argv[1]);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads must be between 1 and %d.\n", MAX_THREADS);
        exit(EXIT_FAILURE);
    }

    int sleep_time = atoi(argv[2]);
    if (sleep_time < 0) {
        fprintf(stderr, "Sleep time must be a positive number.\n");
        exit(EXIT_FAILURE);
    }

    const char *message = argv[3];

    printf("Starting %d threads, each will sleep for %d seconds. Message: %s\n",
           num_threads, sleep_time, message);

    create_threads(num_threads, sleep_time, message);

    printf("All threads have finished execution.\n");
    return 0;
}