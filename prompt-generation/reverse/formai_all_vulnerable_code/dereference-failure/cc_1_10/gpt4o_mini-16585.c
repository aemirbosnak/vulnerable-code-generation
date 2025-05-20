//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_CARS 10
#define ROAD_LENGTH 50
#define NUM_LANES 2

typedef struct Car {
    int id;
    int position;
    int lane;
} Car;

Car *cars[MAX_CARS];
sem_t lane_semaphore[NUM_LANES];

void *car_movement(void *arg) {
    Car *car = (Car *)arg;
    int step_size = 1 + rand() % 3; // Cars move 1 to 3 steps at a time
    
    while (car->position < ROAD_LENGTH) {
        sem_wait(&lane_semaphore[car->lane]);
        
        // Move car
        car->position += step_size;
        printf("Car %d in lane %d is at position %d.\n", car->id, car->lane, car->position);
        
        sem_post(&lane_semaphore[car->lane]);
        
        // Simulate some random driving time
        usleep((rand() % 500) * 1000);
    }
    
    printf("Car %d has reached the end of lane %d!\n", car->id, car->lane);
    
    return NULL;
}

void setup_lanes() {
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_semaphore[i], 0, 1);
    }
}

void cleanup_lanes() {
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lane_semaphore[i]);
    }
}

int main() {
    srand(time(NULL));
    
    setup_lanes();
    
    pthread_t car_threads[MAX_CARS];
    
    // Creating cars
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = (Car *)malloc(sizeof(Car));
        
        cars[i]->id = i + 1;
        cars[i]->position = 0;
        cars[i]->lane = rand() % NUM_LANES; // Randomly assigning lane
        
        pthread_create(&car_threads[i], NULL, car_movement, (void *)cars[i]);
        usleep(100000); // Slight delay to stagger car starts
    }
    
    // Waiting for all cars to finish
    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_threads[i], NULL);
        free(cars[i]);
    }
    
    cleanup_lanes();
    
    printf("All cars have completed their journey!\n");
    return 0;
}