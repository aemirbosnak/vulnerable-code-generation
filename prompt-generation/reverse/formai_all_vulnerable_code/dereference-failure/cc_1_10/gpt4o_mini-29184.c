//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <time.h>

#define NUM_VEHICLES 10
#define NUM_LANES 2

typedef struct vehicle {
    int id;
    int lane;
} vehicle;

sem_t lane_semaphores[NUM_LANES];
pthread_mutex_t print_mutex;

void* vehicle_behavior(void* arg) {
    vehicle* v = (vehicle*)arg;

    // simulate vehicle approach to the lane
    sleep(rand() % 3);

    // Request permission to enter lane
    sem_wait(&lane_semaphores[v->lane]);

    // Critical Section: Vehicle is in the lane
    pthread_mutex_lock(&print_mutex);
    printf("Vehicle %d is in lane %d.\n", v->id, v->lane);
    pthread_mutex_unlock(&print_mutex);
    
    // Simulate the time required to go through the lane
    sleep(rand() % 5 + 1);

    pthread_mutex_lock(&print_mutex);
    printf("Vehicle %d is leaving lane %d.\n", v->id, v->lane);
    pthread_mutex_unlock(&print_mutex);

    // Release the lane
    sem_post(&lane_semaphores[v->lane]);

    free(v);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t vehicles[NUM_VEHICLES];

    // Initialize the lane semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_semaphores[i], 0, 1);  // 1 vehicle can enter at a time
    }

    pthread_mutex_init(&print_mutex, NULL);

    // Create vehicles and assign them a lane randomly
    for (int i = 0; i < NUM_VEHICLES; i++) {
        vehicle* v = malloc(sizeof(vehicle));
        v->id = i + 1;
        v->lane = rand() % NUM_LANES;  // Assign a random lane

        // Create a thread for the vehicle
        if (pthread_create(&vehicles[i], NULL, vehicle_behavior, (void*)v) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_VEHICLES; i++) {
        pthread_join(vehicles[i], NULL);
    }

    // Clean up semaphores and mutex
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lane_semaphores[i]);
    }

    pthread_mutex_destroy(&print_mutex);
    printf("Traffic simulation complete.\n");

    return 0;
}