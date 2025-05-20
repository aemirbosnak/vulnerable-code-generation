//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_VEHICLES 10
#define NUM_DIRECTIONS 4
#define MAX_WAIT 5

typedef struct {
    int id;
    int direction; // 0: North, 1: East, 2: South, 3: West
} Vehicle;

sem_t semaphores[NUM_DIRECTIONS]; // One semaphore for each direction
int waiting_vehicles[NUM_DIRECTIONS] = {0}; // Counting waiting vehicles for each direction

void* approach_intersection(void* arg) {
    Vehicle* veh = (Vehicle*)arg;
    int dir = veh->direction;

    printf("Vehicle %d approaching from direction %d\n", veh->id, dir);
    waiting_vehicles[dir]++;

    // Wait for the semaphore for this direction
    sem_wait(&semaphores[dir]);

    printf("Vehicle %d entering intersection from direction %d\n", veh->id, dir);
    sleep(rand() % MAX_WAIT + 1); // Simulate some time spent in the intersection

    printf("Vehicle %d exiting intersection from direction %d\n", veh->id, dir);
    waiting_vehicles[dir]--;
    
    sem_post(&semaphores[(dir + 1) % NUM_DIRECTIONS]); // Allow next direction
    free(veh); // Free the memory allocated for the vehicle
    return NULL;
}

void* manage_traffic(void* arg) {
    for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
        sem_init(&semaphores[dir], 0, 0); // Initialize semaphore to 0
    }

    while (1) {
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (waiting_vehicles[dir] > 0) {
                sem_post(&semaphores[dir]); // Allow vehicles from this direction to go
                sleep(1); // Give some time for vehicles to clear
                break; // Restart the checking from the current direction
            }
        }
    }
    return NULL;
}

int main() {
    pthread_t traffic_manager;
    pthread_t vehicle_threads[NUM_VEHICLES];

    srand(time(NULL));

    // Create the traffic management thread
    pthread_create(&traffic_manager, NULL, manage_traffic, NULL);

    // Simulate vehicles approaching from random directions
    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle* veh = malloc(sizeof(Vehicle));
        veh->id = i + 1;
        veh->direction = rand() % NUM_DIRECTIONS; // Random direction for each vehicle

        pthread_create(&vehicle_threads[i], NULL, approach_intersection, (void*)veh);
        sleep(rand() % 3); // Random time interval before next vehicle arrives
    }

    // Wait for all vehicles to finish
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicle_threads[i], NULL);
    }

    // Terminate the traffic management thread
    pthread_cancel(traffic_manager);
    pthread_join(traffic_manager, NULL);

    // Clean up semaphores
    for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
        sem_destroy(&semaphores[dir]);
    }

    printf("Traffic simulation finished.\n");
    return 0;
}