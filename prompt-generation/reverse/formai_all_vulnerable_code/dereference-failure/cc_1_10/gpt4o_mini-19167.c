//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_VEHICLES 10
#define INTERSECTION_TIME 5

typedef struct {
    int id;
    char direction; // N, S, E, W
} Vehicle;

pthread_mutex_t intersection_lock;

void *cross_intersection(void *arg) {
    Vehicle *vehicle = (Vehicle *)arg;
    
    pthread_mutex_lock(&intersection_lock);
    
    printf("Vehicle %d from direction %c is crossing the intersection.\n", vehicle->id, vehicle->direction);
    sleep(INTERSECTION_TIME);  // Simulate time taken to cross the intersection
    printf("Vehicle %d from direction %c has crossed the intersection.\n", vehicle->id, vehicle->direction);
    
    pthread_mutex_unlock(&intersection_lock);
    
    free(vehicle);
    return NULL;
}

void spawn_vehicle(int id, char direction) {
    Vehicle *vehicle = malloc(sizeof(Vehicle));
    if (vehicle == NULL) {
        perror("Failed to allocate memory for vehicle");
        exit(EXIT_FAILURE);
    }
    vehicle->id = id;
    vehicle->direction = direction;

    pthread_t tid;
    pthread_create(&tid, NULL, cross_intersection, vehicle);
    pthread_detach(tid);  // Detaches the thread, so we don't need to join it
}

void initialize_traffic_simulation() {
    char directions[] = {'N', 'S', 'E', 'W'};
    srand(time(NULL));
    
    for (int i = 1; i <= NUM_VEHICLES; i++) {
        char direction = directions[rand() % 4];
        spawn_vehicle(i, direction);
        sleep(1); // Delay to simulate vehicle arrivals
    }
}

int main() {
    pthread_mutex_init(&intersection_lock, NULL);
    
    printf("Traffic Flow Simulation Starting...\n");
    initialize_traffic_simulation();
    
    // Allow time for all vehicles to attempt to cross before exiting
    sleep(NUM_VEHICLES * INTERSECTION_TIME);
    
    pthread_mutex_destroy(&intersection_lock);
    printf("Traffic Flow Simulation Ending...\n");
    
    return 0;
}