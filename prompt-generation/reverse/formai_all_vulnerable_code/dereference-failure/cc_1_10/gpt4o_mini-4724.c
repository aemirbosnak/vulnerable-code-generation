//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_CARS 5
#define NUM_LANES 3
#define MAX_WAIT_TIME 5

sem_t lanes[NUM_LANES];
pthread_mutex_t mutex;

typedef struct {
    int id;
    int lane;
} Car;

void* drive(void* arg) {
    Car* car = (Car*)arg;
    int wait_time = rand() % MAX_WAIT_TIME + 1;

    printf("Car %d is waiting to enter Lane %d for %d seconds.\n", car->id, car->lane, wait_time);
    
    // Simulate waiting for a lane
    sleep(wait_time);
    sem_wait(&lanes[car->lane]);
    
    // We have entered the lane
    printf("Car %d has entered Lane %d.\n", car->id, car->lane);
    
    // Simulate the driving time
    int drive_time = rand() % 5 + 1;
    sleep(drive_time);
    
    // Car exits the lane
    printf("Car %d has exited Lane %d after driving for %d seconds.\n", car->id, car->lane, drive_time);
    sem_post(&lanes[car->lane]);
    
    free(car);
    return NULL;
}

int main() {
    srand(time(0));

    // Initialize semaphores for lanes
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1); // Each lane can hold one car
    }

    pthread_t cars[NUM_CARS];
    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = (Car*)malloc(sizeof(Car));
        car->id = i + 1;
        car->lane = rand() % NUM_LANES; // Assign a random lane

        pthread_create(&cars[i], NULL, drive, (void*)car);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Clean up semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }

    return 0;
}