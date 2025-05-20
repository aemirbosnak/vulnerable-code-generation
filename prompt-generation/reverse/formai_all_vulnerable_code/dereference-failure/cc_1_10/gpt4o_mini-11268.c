//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_VEHICLES 10
#define NUM_LANES 2
#define MAX_WAIT_TIME 5
#define SIMULATION_TIME 30

sem_t lanes[NUM_LANES];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int id;
    int lane;
} Vehicle;

void* simulate_vehicle(void* arg) {
    Vehicle* v = (Vehicle*)arg;
    int wait_time = rand() % MAX_WAIT_TIME + 1;

    printf("Vehicle %d is waiting to enter lane %d for %d seconds.\n", v->id, v->lane, wait_time);
    sleep(wait_time);

    // Enter the lane
    sem_wait(&lanes[v->lane]);
    
    // Simulating travel through the lane
    printf("Vehicle %d is traveling in lane %d.\n", v->id, v->lane);
    sleep(rand() % 3 + 1); // travel time

    // Exit the lane
    printf("Vehicle %d has exited lane %d.\n", v->id, v->lane);
    sem_post(&lanes[v->lane]);
    
    free(v);
    return NULL;
}

void initialize_lanes() {
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1);
    }
}

void cleanup_lanes() {
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }
}

int main() {
    srand(time(NULL));
    initialize_lanes();
    
    pthread_t vehicle_threads[NUM_VEHICLES];
    
    for (int i = 0; i < NUM_VEHICLES; i++) {
        Vehicle* v = malloc(sizeof(Vehicle));
        v->id = i + 1;
        v->lane = rand() % NUM_LANES;

        if (pthread_create(&vehicle_threads[i], NULL, simulate_vehicle, v) != 0) {
            perror("Failed to create vehicle thread");
            free(v);
            continue;
        }
    }

    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicle_threads[i], NULL);
    }
    
    cleanup_lanes();
    printf("Traffic simulation completed.\n");
    return 0;
}