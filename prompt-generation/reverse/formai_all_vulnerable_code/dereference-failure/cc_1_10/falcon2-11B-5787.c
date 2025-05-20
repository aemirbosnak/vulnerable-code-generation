//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 100

int max_x = 1000;
int max_y = 1000;
int current_x = 0;
int current_y = 0;

void *move_drone(void *arg) {
    int x = *(int*)arg;
    int y = *(int*)(((int*)arg) + 1);

    while (1) {
        // Update drone position
        current_x = current_x + x;
        current_y = current_y + y;

        // Check if drone is out of bounds
        if (current_x > max_x) {
            current_x = 0;
        }
        if (current_y > max_y) {
            current_y = 0;
        }
        if (current_x < 0) {
            current_x = max_x;
        }
        if (current_y < 0) {
            current_y = max_y;
        }

        // Print drone position
        printf("Drone position: (%d, %d)\n", current_x, current_y);

        // Sleep for 1 second
        sleep(1);
    }

    return NULL;
}

int main() {
    // Create threads
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Set thread IDs
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
    }

    // Create threads and start them
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, move_drone, (void*)&thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}