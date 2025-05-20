//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_RUNNERS 5
#define FINISH_LINE 100

pthread_mutex_t mutex;
int distances[NUM_RUNNERS] = {0}; // Distance traveled by each runner

void* runner(void* arg) {
    int runner_id = *(int*)arg;
    free(arg); // Free the allocated memory for runner_id

    while (distances[runner_id] < FINISH_LINE) {
        usleep(rand() % 100000); // Sleep for a random time to simulate running

        pthread_mutex_lock(&mutex);
        distances[runner_id] += (rand() % 10) + 1; // Increase distance
        printf("Runner %d ran! Current distance: %d\n", runner_id + 1, distances[runner_id]);
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    printf("Runner %d has finished the race!\n", runner_id + 1);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t runners[NUM_RUNNERS];
    pthread_mutex_init(&mutex, NULL);

    printf("Welcome to the Great C Threading Race!\n");
    
    for (int i = 0; i < NUM_RUNNERS; i++) {
        int* arg = malloc(sizeof(*arg)); // Allocate memory for runner_id to prevent data race
        *arg = i; // Set the runner id
        if (pthread_create(&runners[i], NULL, runner, arg) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    // Wait for all runners to finish
    for (int i = 0; i < NUM_RUNNERS; i++) {
        pthread_join(runners[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("All runners have completed the race!\n");
    return 0;
}