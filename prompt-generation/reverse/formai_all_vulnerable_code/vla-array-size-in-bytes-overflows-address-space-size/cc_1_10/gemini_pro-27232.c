//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>

// Global variables
int cpu_usage[4]; // Array to store CPU usage for each core
sem_t mutex; // Mutex to protect shared variables
int num_threads; // Number of threads to create
int num_cores; // Number of CPU cores

// Thread function
void *thread_func(void *arg) {
    // Get the thread ID
    int tid = *(int *)arg;

    // Get the CPU usage for the current core
    int core = sched_getcpu();
    cpu_usage[core]++;

    // Sleep for a random amount of time
    srand(time(NULL));
    int sleep_time = rand() % 1000;
    usleep(sleep_time * 1000);

    // Lock the mutex
    sem_wait(&mutex);

    // Update the global CPU usage
    cpu_usage[core] += sleep_time;

    // Unlock the mutex
    sem_post(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Get the number of CPU cores
    num_cores = sysconf(_SC_NPROCESSORS_ONLN);

    // Initialize the mutex
    sem_init(&mutex, 0, 1);

    // Create the threads
    pthread_t threads[num_cores];
    for (int i = 0; i < num_cores; i++) {
        int *tid = malloc(sizeof(int));
        *tid = i;
        pthread_create(&threads[i], NULL, thread_func, tid);
    }

    // Join the threads
    for (int i = 0; i < num_cores; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the CPU usage
    printf("CPU Usage:\n");
    for (int i = 0; i < num_cores; i++) {
        printf("Core %d: %d%%\n", i, cpu_usage[i]);
    }

    // Destroy the mutex
    sem_destroy(&mutex);

    return 0;
}