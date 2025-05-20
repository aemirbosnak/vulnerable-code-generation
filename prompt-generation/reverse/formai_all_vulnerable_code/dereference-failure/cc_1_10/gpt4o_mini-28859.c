//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 5

// Structure to hold thread data
typedef struct {
    int thread_id;
    char *message;
} thread_data_t;

// Mutex for synchronizing access
pthread_mutex_t mutex;

// Function that each thread will execute
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Simulate work with a slight delay
    sleep(rand() % 3);

    // Locking mutex to ensure exclusive access while printing
    pthread_mutex_lock(&mutex);
    printf("Thread %d: %s\n", data->thread_id, data->message);
    pthread_mutex_unlock(&mutex);

    free(data->message);
    free(data);
    return NULL;
}

// Exit if pthreads fails
void safe_pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg) {
    int result = pthread_create(thread, attr, start_routine, arg);
    if (result != 0) {
        fprintf(stderr, "ERROR: pthread_create failed: %s\n", strerror(result));
        exit(EXIT_FAILURE);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    srand(time(NULL));

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        fprintf(stderr, "ERROR: Mutex initialization failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        if (data == NULL) {
            fprintf(stderr, "ERROR: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        data->thread_id = i;
        data->message = malloc(50 * sizeof(char));
        if (data->message == NULL) {
            fprintf(stderr, "ERROR: malloc for message failed\n");
            exit(EXIT_FAILURE);
        }
        snprintf(data->message, 50, "Hello from thread %d", i);

        // Create thread safely
        safe_pthread_create(&threads[i], NULL, thread_function, data);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        int result = pthread_join(threads[i], NULL);
        if (result != 0) {
            fprintf(stderr, "ERROR: pthread_join failed: %s\n", strerror(result));
            exit(EXIT_FAILURE);
        }
    }

    // Destroy mutex
    if (pthread_mutex_destroy(&mutex) != 0) {
        fprintf(stderr, "ERROR: Mutex destruction failed\n");
        return EXIT_FAILURE;
    }

    printf("All threads completed successfully!\n");
    return EXIT_SUCCESS;
}