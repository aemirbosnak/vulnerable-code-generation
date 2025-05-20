//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_VEHICLES 10

sem_t intersection;  // Semaphore to control access to the intersection
int north_south_count = 0;  // Count of vehicles from north-south
int east_west_count = 0;    // Count of vehicles from east-west

typedef struct {
    int id;
    char direction; // 'N', 'S', 'E', 'W'
} Vehicle;

void* vehicle_func(void* arg) {
    Vehicle* vehicle = (Vehicle*)arg;
    sleep(rand() % 3); // Simulate time to reach the intersection

    printf("Vehicle %d (%c) is approaching the intersection.\n", vehicle->id, vehicle->direction);
    
    if (vehicle->direction == 'N' || vehicle->direction == 'S') {
        // North-South vehicles
        sem_wait(&intersection);
        north_south_count++;
        
        printf("Vehicle %d (%c) is passing through the intersection. (North-South)\n", vehicle->id, vehicle->direction);
        sleep(1); // Simulate the time taken to cross
        north_south_count--;
        sem_post(&intersection);
    } else {
        // East-West vehicles
        sem_wait(&intersection);
        east_west_count++;
        
        printf("Vehicle %d (%c) is passing through the intersection. (East-West)\n", vehicle->id, vehicle->direction);
        sleep(1); // Simulate the time taken to cross
        east_west_count--;
        sem_post(&intersection);
    }

    printf("Vehicle %d (%c) has cleared the intersection.\n", vehicle->id, vehicle->direction);
    free(vehicle);
    return NULL;
}

int main() {
    srand(time(0)); // Seed the random number generator
    pthread_t vehicles[NUM_VEHICLES];
    sem_init(&intersection, 0, 1); // Initialize the semaphore

    // Create and start vehicle threads
    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle* vehicle = malloc(sizeof(Vehicle));
        vehicle->id = i + 1;
        int dir = rand() % 4; // Randomly assign direction

        switch (dir) {
            case 0: vehicle->direction = 'N'; break; // North
            case 1: vehicle->direction = 'S'; break; // South
            case 2: vehicle->direction = 'E'; break; // East
            case 3: vehicle->direction = 'W'; break; // West
        }

        pthread_create(&vehicles[i], NULL, vehicle_func, vehicle);
    }

    // Wait for all vehicle threads to finish
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    sem_destroy(&intersection); // Clean up semaphore
    return 0;
}