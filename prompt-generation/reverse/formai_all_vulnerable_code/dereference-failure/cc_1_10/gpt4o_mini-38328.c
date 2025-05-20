//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define NUM_CARS 5
#define NUM_LANES 2
#define INTERSECTION_TIME 3
#define MAX_SIM_TIME 30

sem_t lanes[NUM_LANES];

void* car(void* arg) {
    int car_id = *(int*)arg;
    int lane = car_id % NUM_LANES;
    
    printf("Car %d is approaching the intersection.\n", car_id);
    sem_wait(&lanes[lane]); // Request lane access
    printf("Car %d has entered lane %d.\n", car_id, lane);
    
    // Simulate car passing through the intersection
    sleep(INTERSECTION_TIME);
    
    printf("Car %d is leaving the intersection.\n", car_id);
    sem_post(&lanes[lane]); // Release lane access

    free(arg); // Free allocated memory
    return NULL;
}

int main() {
    srand(time(0));
    pthread_t cars[NUM_CARS];
    
    // Initialize semaphores for each lane
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1);
    }
    
    // Start traffic simulation for a defined max time
    int sim_time = 0;
    while (sim_time < MAX_SIM_TIME) {
        // Concurrently spawn car threads
        for (int i = 0; i < NUM_CARS; i++) {
            // Create thread for each car
            int* car_id = malloc(sizeof(int)); // Allocate memory for the car ID
            *car_id = i;
            pthread_create(&cars[i], NULL, car, car_id);
            sleep(rand() % 2); // Random delay between car arrivals
        }

        // Join threads to ensure they complete before the next cycle
        for (int i = 0; i < NUM_CARS; i++) {
            pthread_join(cars[i], NULL);
        }
        
        sim_time++;
    }

    // Clean up semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }
    
    printf("Traffic simulation has ended.\n");
    
    return 0;
}