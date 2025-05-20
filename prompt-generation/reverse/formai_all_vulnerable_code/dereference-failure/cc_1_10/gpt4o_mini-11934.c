//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define ROAD_LENGTH 30
#define MAX_VEHICLES 10
#define SIMULATION_DURATION 20 // in seconds

typedef struct {
    int position; // Position on the road
    char type; // 'C' for car, 'B' for bus
} Vehicle;

Vehicle* vehicles[MAX_VEHICLES];
pthread_mutex_t mutex; // Mutex for thread-safe operations

void* move_vehicle(void* arg) {
    Vehicle* vehicle = (Vehicle*)arg;

    while (1) {
        // Lock the mutex for thread-safe operations
        pthread_mutex_lock(&mutex);
        
        // Move the vehicle
        if (vehicle->position < ROAD_LENGTH - 1) {
            vehicle->position++; // Move forward
        } else {
            vehicle->position = 0; // Reset to the start of the road
        }

        // Display the road with vehicles
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (i == vehicle->position) {
                printf("%c ", vehicle->type);
            } else {
                printf(". ");
            }
        }
        printf("\n");
        
        // Unlock the mutex after moving
        pthread_mutex_unlock(&mutex);

        // Sleep to simulate time passing
        usleep(250000); // Sleep for 250 milliseconds
    }

    return NULL;
}

void create_vehicle(int index, char type) {
    Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
    vehicle->position = rand() % ROAD_LENGTH; // Random starting position
    vehicle->type = type;
    vehicles[index] = vehicle;

    pthread_t thread;
    pthread_create(&thread, NULL, move_vehicle, (void*)vehicle);
    pthread_detach(thread);
}

void clean_up() {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (vehicles[i] != NULL) {
            free(vehicles[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    
    printf("Traffic Flow Simulation Start!\n");
    
    // Create random vehicles
    for (int i = 0; i < MAX_VEHICLES; i++) {
        // Randomly decide whether to create a car or a bus
        char type = (rand() % 2) == 0 ? 'C' : 'B';
        create_vehicle(i, type);
    }

    // Run the simulation for a specified duration
    sleep(SIMULATION_DURATION);
    
    printf("Simulation Ended!\n");

    // Clean up the vehicle memory
    clean_up();

    pthread_mutex_destroy(&mutex);

    return 0;
}