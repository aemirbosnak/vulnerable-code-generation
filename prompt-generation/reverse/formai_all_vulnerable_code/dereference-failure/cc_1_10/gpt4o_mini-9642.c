//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <pthread.h>

#define ROAD_LENGTH 100   // Length of the road
#define NUM_VEHICLES 5    // Number of vehicles in the simulation

typedef struct {
    int id;
    int position;
    int speed; // Speed of the vehicle
} Vehicle;

Vehicle *vehicles[NUM_VEHICLES];
pthread_mutex_t road_lock;

void *move_vehicle(void *arg) {
    Vehicle *v = (Vehicle *)arg;
    while (1) {
        pthread_mutex_lock(&road_lock);
        
        if (v->position + v->speed < ROAD_LENGTH) {
            v->position += v->speed;
            printf("Vehicle %d moved to position %d\n", v->id, v->position);
        } else {
            printf("Vehicle %d has reached the end of the road\n", v->id);
            pthread_mutex_unlock(&road_lock);
            break; // Exit the loop if the vehicle reached the end
        }
        
        pthread_mutex_unlock(&road_lock);
        sleep(1); // Simulate time delay for moving
    }
    return NULL;
}

void create_vehicle(int id, int speed) {
    Vehicle *v = (Vehicle *)malloc(sizeof(Vehicle));
    v->id = id;
    v->position = 0;
    v->speed = speed;
    vehicles[id] = v;

    pthread_t tid;
    pthread_create(&tid, NULL, move_vehicle, v);
}

void cleanup_vehicles() {
    for (int i = 0; i < NUM_VEHICLES; i++) {
        if (vehicles[i] != NULL) {
            free(vehicles[i]);
        }
    }
}

int main() {
    pthread_mutex_init(&road_lock, NULL);
    
    // Creating vehicles with varying speeds
    for (int i = 0; i < NUM_VEHICLES; i++) {
        int speed = rand() % 5 + 1; // Random speed between 1 and 5
        create_vehicle(i, speed);
    }

    // Main loop for simulation duration
    sleep(15); // Let the simulation run for 15 seconds
    
    // Cleanup
    cleanup_vehicles();
    pthread_mutex_destroy(&road_lock);

    printf("Traffic simulation completed.\n");
    return 0;
}