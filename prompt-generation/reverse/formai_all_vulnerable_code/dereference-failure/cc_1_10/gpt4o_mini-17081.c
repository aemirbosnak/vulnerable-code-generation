//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define ROAD_LENGTH 10
#define NUM_CARS 5
#define MAX_SPEED 1
#define MIN_SPEED 1

sem_t semaphores[ROAD_LENGTH];
int road[ROAD_LENGTH] = {0}; // 0: empty, 1: occupied

void* car(void* param) {
    int car_id = *(int*)param;
    int position = 0;

    while (position < ROAD_LENGTH) {
        printf("Car %d is at position %d\n", car_id, position);
        
        // Attempt to enter the road section
        sem_wait(&semaphores[position]);

        // Simulate car occupying the road segment
        road[position] = car_id;
        printf("Car %d entered position %d\n", car_id, position);
        
        // Move forward
        usleep((rand() % (MAX_SPEED)) * 100000); // random sleep to simulate traffic
        road[position] = 0; // Leave road segment
        
        sem_post(&semaphores[position]); // Free up the road segment
        
        position++;
    }

    printf("Car %d has left the road\n", car_id);
    free(param);
    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t cars[NUM_CARS];
    
    // Initialize the semaphores
    for (int i = 0; i < ROAD_LENGTH; i++) {
        sem_init(&semaphores[i], 0, 1); // each segment starts with 1 car capacity
    }

    // Create cars
    for (int i = 0; i < NUM_CARS; i++) {
        int* car_id = malloc(sizeof(int));
        *car_id = i + 1;
        pthread_create(&cars[i], NULL, car, car_id);
    }

    // Wait for all cars to finish
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Destroy semaphores
    for (int i = 0; i < ROAD_LENGTH; i++) {
        sem_destroy(&semaphores[i]);
    }

    printf("All cars have finished their journey.\n");
    return 0;
}