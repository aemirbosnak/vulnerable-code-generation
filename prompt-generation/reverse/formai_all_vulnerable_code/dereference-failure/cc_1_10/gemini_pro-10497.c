//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define NUM_LOCATIONS 10

// Global variables
int weather[NUM_LOCATIONS];
sem_t weather_sems[NUM_LOCATIONS];

// Thread function
void *weather_thread(void *arg) {
    int location = *(int *)arg;

    while (1) {
        // Wait for the weather to change
        sem_wait(&weather_sems[location]);

        // Generate a new weather condition
        weather[location] = rand() % 4;

        // Print the new weather condition
        printf("Weather in location %d: %d\n", location, weather[location]);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }

    return NULL;
}

int main() {
    // Initialize the weather
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        weather[i] = rand() % 4;
    }

    // Initialize the semaphores
    for (int i = 0; i < NUM_LOCATIONS; i++) {
        sem_init(&weather_sems[i], 0, 0);
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *location = malloc(sizeof(int));
        *location = i;
        pthread_create(&threads[i], NULL, weather_thread, location);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}