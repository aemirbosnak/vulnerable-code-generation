//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_CARS 5
#define NUM_LANES 3
#define MAX_TURN_TIME 3

sem_t lane_semaphores[NUM_LANES];

typedef struct {
    int id;
    int lane;
} Car;

void* drive(void* arg) {
    Car* car = (Car*)arg;
    
    printf("Car %d is approaching lane %d.\n", car->id, car->lane);
    sem_wait(&lane_semaphores[car->lane]); // Try to enter the lane
    
    printf("Car %d has entered lane %d.\n", car->id, car->lane);
    int turn_time = rand() % MAX_TURN_TIME + 1;

    // Simulate the car driving in the lane
    sleep(turn_time);
    printf("Car %d is leaving lane %d after %d seconds.\n", car->id, car->lane, turn_time);

    sem_post(&lane_semaphores[car->lane]); // Exit the lane
    free(car);
    return NULL;
}

void create_cars(int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        Car* new_car = (Car*)malloc(sizeof(Car));
        new_car->id = i;
        new_car->lane = rand() % NUM_LANES;  // Randomly select a lane

        pthread_t thread;
        pthread_create(&thread, NULL, drive, new_car);
        pthread_detach(thread); // Detach to allow independent execution
    }
}

int main() {
    srand(time(0));
    
    // Initialize semaphores for each lane
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_semaphores[i], 0, 1); // Each lane can handle one car at a time
    }

    printf("Welcome to the Fantastical Traffic Simulation!\n");
    while (1) {
        create_cars(NUM_CARS);
        sleep(2); // Simulate a delay before the next batch of cars
    }

    // Cleanup: Destroy semaphores (unreachable in this code, kept for completeness)
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lane_semaphores[i]);
    }

    return 0;
}