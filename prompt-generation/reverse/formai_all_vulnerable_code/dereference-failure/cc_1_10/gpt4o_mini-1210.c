//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_CARS 10
#define NUM_LANES 2
#define ROAD_LENGTH 50

sem_t lanes[NUM_LANES];
pthread_mutex_t print_mutex;

typedef struct {
    int id;
    int lane;
} Car;

void* drive(void* arg) {
    Car* car = (Car*)arg;
    
    // Simulate entering a lane
    sem_wait(&lanes[car->lane]);
    
    // Simulate driving on the road
    for (int i = 0; i < ROAD_LENGTH; i++) {
        pthread_mutex_lock(&print_mutex);
        printf("Car %d is driving in lane %d at position %d\n", car->id, car->lane, i);
        pthread_mutex_unlock(&print_mutex);
        usleep((rand() % 200000) + 100000); // Simulation of time taken to move
    }
    
    // Simulate leaving the lane
    sem_post(&lanes[car->lane]);
    
    // Exit the thread
    free(car);
    return NULL;
}

int main() {
    srand(time(NULL));

    // Initialize semaphores for lanes
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1); // Allows 1 car per lane
    }
    
    pthread_mutex_init(&print_mutex, NULL);
    
    pthread_t cars[NUM_CARS];

    // Create threads for cars
    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = (Car*)malloc(sizeof(Car));
        car->id = i + 1;
        car->lane = rand() % NUM_LANES; // Randomly assign a lane
        pthread_create(&cars[i], NULL, drive, car);
    }

    // Wait for all cars to finish
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }
    pthread_mutex_destroy(&print_mutex);

    printf("All cars have finished driving.\n");

    return 0;
}