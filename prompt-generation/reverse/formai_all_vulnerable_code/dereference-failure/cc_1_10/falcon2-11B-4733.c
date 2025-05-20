//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_cars = 100;
int num_lanes = 4;
int car_length = 5;
int car_speed = 10;
int distance_to_move = 1000;
int time_per_move = 5;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *car_simulation(void *arg) {
    int *lane = (int *)arg;
    int car_id = *lane;
    int current_lane = *lane;
    int current_position = 0;

    for (int i = 0; i < distance_to_move; i += car_speed) {
        // Lock mutex to prevent race condition
        pthread_mutex_lock(&lock);

        // Move car to the next lane
        current_position += car_length;
        if (current_position >= distance_to_move) {
            current_position -= distance_to_move;
            *lane = (*lane + 1) % num_lanes;
        }

        // Unlock mutex
        pthread_mutex_unlock(&lock);

        // Sleep for time_per_move
        usleep(time_per_move * 1000);
    }
}

int main() {
    pthread_t *threads = malloc(num_cars * sizeof(pthread_t));
    int *lanes = malloc(num_cars * sizeof(int));

    // Initialize lanes
    for (int i = 0; i < num_cars; i++) {
        lanes[i] = i;
    }

    // Create threads for each car
    for (int i = 0; i < num_cars; i++) {
        pthread_create(&threads[i], NULL, car_simulation, &lanes[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_cars; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory
    free(threads);
    free(lanes);

    return 0;
}