//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

// Structure to store boot time data
typedef struct {
    char *name;
    unsigned long long start_time;
    unsigned long long end_time;
} boot_time_data;

// Mutex to protect shared data
pthread_mutex_t mutex;

// Thread function to measure boot time of a program
void *measure_boot_time(void *arg) {
    boot_time_data *data = (boot_time_data *)arg;

    // Get the start time
    struct timeval start_timeval;
    gettimeofday(&start_timeval, NULL);
    data->start_time = start_timeval.tv_sec * 1000000 + start_timeval.tv_usec;

    // Run the program
    system(data->name);

    // Get the end time
    struct timeval end_timeval;
    gettimeofday(&end_timeval, NULL);
    data->end_time = end_timeval.tv_sec * 1000000 + end_timeval.tv_usec;

    // Lock the mutex to protect shared data
    pthread_mutex_lock(&mutex);

    // Print the boot time
    printf("%s: %llu microseconds\n", data->name, data->end_time - data->start_time);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads to measure boot time of multiple programs
    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++) {
        boot_time_data *data = malloc(sizeof(boot_time_data));
        data->name = argv[i];
        pthread_create(&threads[i - 1], NULL, measure_boot_time, data);
    }

    // Join threads
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}