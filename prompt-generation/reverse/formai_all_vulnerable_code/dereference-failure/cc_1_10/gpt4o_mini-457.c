//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define ROAD_LENGTH 20
#define NUM_VEHICLES 5
#define TIMESTEP 500000 // Time step in microseconds

char road[ROAD_LENGTH];
sem_t sem;

void* vehicle_movement(void* id) {
    int car_id = *(int*) id;
    int position = rand() % ROAD_LENGTH; // Initial position
    road[position] = 'A' + car_id; // Placeholder character for vehicle

    while (1) {
        usleep(TIMESTEP);
        
        // Check if vehicle can move forward
        sem_wait(&sem);
        if (position < ROAD_LENGTH - 1 && road[position + 1] == ' ') {
            road[position] = ' '; // Leave previous position
            position++; // Move forward
            road[position] = 'A' + car_id; // Take new position
        }
        sem_post(&sem);

        // Display road
        printf("\r%s\n", road);
        fflush(stdout);
        
        // Simulation stop condition (for this example, arbitrary limit)
        if (position >= ROAD_LENGTH - 1) break; 
    }

    // Clear out the vehicle from the road completely
    sem_wait(&sem);
    road[position] = ' ';
    sem_post(&sem);
    free(id);
    return NULL;
}

int main() {
    srand(time(NULL));
    sem_init(&sem, 0, 1); // Initialize semaphore
    pthread_t vehicles[NUM_VEHICLES];

    // Initialize road
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = ' ';
    }

    // Create vehicles
    for (int i = 0; i < NUM_VEHICLES; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&vehicles[i], NULL, vehicle_movement, id);
    }

    // Wait for all vehicles to finish
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    sem_destroy(&sem); // Clean up semaphore
    return 0;
}