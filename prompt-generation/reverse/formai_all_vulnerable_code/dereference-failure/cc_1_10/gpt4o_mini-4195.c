//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_LANES 2
#define NUM_CARS 10
#define MAX_CARS_PER_LANE 5
#define SIMULATION_TIME 30 // seconds

typedef struct {
    int id;
    int lane;
} Car;

sem_t lane_semaphores[NUM_LANES];

void* car_behavior(void* param) {
    Car* car = (Car*)param;
    int lane = car->lane;

    // Car is attempting to enter the lane
    printf("Car %d is waiting to enter lane %d\n", car->id, lane);
    sem_wait(&lane_semaphores[lane]);
    
    // Simulation of car driving
    printf("Car %d has entered lane %d\n", car->id, lane);
    sleep(rand() % 3 + 1); // Simulate time taken in the lane
    printf("Car %d is leaving lane %d\n", car->id, lane);
    
    // Free lane
    sem_post(&lane_semaphores[lane]);
    free(car);
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize semaphore for each lane
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_semaphores[i], 0, MAX_CARS_PER_LANE);
    }

    pthread_t car_threads[NUM_CARS];
    time_t start_time = time(NULL);
    
    for (int i = 0; i < NUM_CARS; i++) {
        if (difftime(time(NULL), start_time) > SIMULATION_TIME) {
            break; // Exit if simulation time limit reached
        }
        
        Car* car = malloc(sizeof(Car));
        car->id = i + 1;
        car->lane = rand() % NUM_LANES; // Randomly assign a lane
        
        pthread_create(&car_threads[i], NULL, car_behavior, car);
        usleep(rand() % 100000); // Random delay between car entries
    }

    // Wait for all car threads to finish
    for (int i = 0; i < NUM_CARS; i++) {
        if (car_threads[i]) {
            pthread_join(car_threads[i], NULL);
        }
    }

    // Cleanup
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lane_semaphores[i]);
    }

    printf("Traffic simulation completed.\n");
    return 0;
}