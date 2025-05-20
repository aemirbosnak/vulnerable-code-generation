//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 20

typedef struct {
    int thread_id;
    int **shared_resource;
    pthread_mutex_t *mutex_lock;
} thread_data_t;

void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int thread_id = data->thread_id;
    int **shared_resource = data->shared_resource;
    pthread_mutex_t *mutex_lock = data->mutex_lock;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        int wait_time = rand() % 3;
        sleep(wait_time); // Simulate computation time

        pthread_mutex_lock(mutex_lock);
        shared_resource[thread_id][i] = thread_id * 10 + i; // Modify shared resource
        printf("Thread %d wrote %d to shared_resource[%d][%d]\n", thread_id, shared_resource[thread_id][i], thread_id, i);
        pthread_mutex_unlock(mutex_lock);
    }

    pthread_exit(NULL);
}

void initialize_shared_resource(int ***resource, int num_threads, int num_iterations) {
    *resource = malloc(num_threads * sizeof(int *));
    for (int i = 0; i < num_threads; i++) {
        (*resource)[i] = malloc(num_iterations * sizeof(int));
    }
}

void cleanup_shared_resource(int **resource, int num_threads) {
    for (int i = 0; i < num_threads; i++) {
        free(resource[i]);
    }
    free(resource);
}

int main() {
    srand(time(NULL));
    
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    int **shared_resource;
    pthread_mutex_t mutex_lock;

    // Initialize mutex
    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        fprintf(stderr, "Mutex init failed\n");
        return EXIT_FAILURE;
    }

    // Initialize shared resource
    initialize_shared_resource(&shared_resource, NUM_THREADS, NUM_ITERATIONS);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].shared_resource = shared_resource;
        thread_data[i].mutex_lock = &mutex_lock;

        if (pthread_create(&threads[i], NULL, thread_function, (void *)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Display the contents of shared resource
    printf("Contents of shared_resource:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        for (int j = 0; j < NUM_ITERATIONS; j++) {
            printf("shared_resource[%d][%d]: %d\n", i, j, shared_resource[i][j]);
        }
    }

    // Cleanup resources
    cleanup_shared_resource(shared_resource, NUM_THREADS);
    pthread_mutex_destroy(&mutex_lock);

    return EXIT_SUCCESS;
}