//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_LANES 3
#define NUM_CARS 5
#define SIMULATION_TIME 30 // seconds

typedef struct {
    int id;
    int lane;
} Car;

Car *cars[NUM_CARS];
pthread_mutex_t lane_mutex[NUM_LANES];

void *car_actions(void *arg) {
    Car *car = (Car *) arg;
    int lane = car->lane;

    printf("Car %d is starting in lane %d.\n", car->id, lane);

    srand(time(NULL) + car->id); // Seed random number generator

    int time_to_cross = rand() % 5 + 1; // Random time between 1-5 seconds

    sleep(time_to_cross); // Simulate time taken to cross the intersection

    printf("Car %d has crossed the intersection from lane %d in %d seconds.\n", car->id, lane, time_to_cross);

    pthread_exit(NULL);
}

void *traffic_control(void *arg) {
    int lane = *(int *)arg;

    while (1) {
        pthread_mutex_lock(&lane_mutex[lane]);

        // Simulate traffic light control
        printf("Traffic light for lane %d is green.\n", lane);
        sleep(5); // Green light duration

        printf("Traffic light for lane %d is red.\n", lane);
        sleep(2); // Red light duration

        pthread_mutex_unlock(&lane_mutex[lane]);
        sleep(1); // Wait before changing to the next lane
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t car_threads[NUM_CARS];
    pthread_t traffic_threads[NUM_LANES];
    int lane_ids[NUM_LANES];
    time_t start_time, current_time;

    // Initialize mutexes for each lane
    for (int i = 0; i < NUM_LANES; i++) {
        pthread_mutex_init(&lane_mutex[i], NULL);
        lane_ids[i] = i;
        pthread_create(&traffic_threads[i], NULL, traffic_control, (void *)&lane_ids[i]);
    }

    // Create car threads
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i] = (Car *)malloc(sizeof(Car));
        cars[i]->id = i+1;
        cars[i]->lane = rand() % NUM_LANES;

        pthread_create(&car_threads[i], NULL, car_actions, (void *)cars[i]);
    }

    // Monitor simulation time
    start_time = time(NULL);
    while (1) {
        current_time = time(NULL);
        if (difftime(current_time, start_time) >= SIMULATION_TIME) {
            printf("Simulation ended after %d seconds.\n", SIMULATION_TIME);
            break;
        }
        sleep(1); // Sleep to prevent busy waiting
    }

    // Clean up threads and allocated resources
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_cancel(car_threads[i]);
        free(cars[i]);
    }

    for (int i = 0; i < NUM_LANES; i++) {
        pthread_cancel(traffic_threads[i]);
        pthread_mutex_destroy(&lane_mutex[i]);
    }

    return 0;
}