//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the number of time periods
#define NUM_TIME_PERIODS 10

// Define the time range
#define MIN_TIME 1900
#define MAX_TIME 2100

// Define the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Define the time periods
int time_periods[NUM_TIME_PERIODS] = {
    1900, 1920, 1940, 1960, 1980, 2000, 2020, 2040, 2060, 2080, 2100
};

// Define the thread data structure
typedef struct {
    int id;
    int start_time;
    int end_time;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
    // Get the thread data
    thread_data_t *data = (thread_data_t *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for the condition variable to be signaled
    while (data->start_time > time_periods[data->id]) {
        pthread_cond_wait(&cond, &mutex);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Simulate time travel
    for (int i = data->start_time; i <= data->end_time; i++) {
        // Print the time period
        printf("Thread %d: %d\n", data->id, i);

        // Sleep for 1 second
        sleep(1);
    }

    return NULL;
}

int main() {
    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = malloc(sizeof(thread_data_t));
        data->id = i;
        data->start_time = time_periods[i];
        data->end_time = time_periods[i + 1] - 1;
        pthread_create(&threads[i], NULL, thread_function, data);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}