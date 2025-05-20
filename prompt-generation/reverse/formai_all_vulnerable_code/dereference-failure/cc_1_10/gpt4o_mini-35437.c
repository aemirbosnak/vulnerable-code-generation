//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define NUM_CARS 5
#define NUM_LANES 2
#define INTERSECTION_TIME 3

sem_t lanes[NUM_LANES];

void* car(void* arg) {
    int car_id = *((int*)arg);
    free(arg);

    int lane_id = car_id % NUM_LANES; // Simple allocation to lanes
    printf("Car %d is approaching lane %d.\n", car_id, lane_id);

    // Attempt to occupy a lane
    sem_wait(&lanes[lane_id]);
    
    // Enter intersection
    printf("Car %d is entering the intersection on lane %d.\n", car_id, lane_id);
    sleep(INTERSECTION_TIME); // Simulate time taken to cross the intersection

    // Exit intersection
    printf("Car %d has exited the intersection from lane %d.\n", car_id, lane_id);
    
    // Release the lane
    sem_post(&lanes[lane_id]);

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t cars[NUM_CARS];
    
    // Initialize lane semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1); // Each lane can hold 1 car at a time
    }

    // Create cars
    for (int i = 0; i < NUM_CARS; i++) {
        int* car_id = malloc(sizeof(int));
        *car_id = i;
        pthread_create(&cars[i], NULL, car, car_id);
        usleep(rand() % 1000000); // Random delay between car arrivals
    }

    // Wait for all cars to finish
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Cleanup semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }

    printf("All cars have crossed the intersection safely.\n");
    return 0;
}