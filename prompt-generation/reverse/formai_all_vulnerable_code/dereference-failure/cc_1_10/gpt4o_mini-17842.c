//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#define NUM_CARS 10
#define NUM_LANES 2
#define NUM_ROUNDS 5

sem_t lanes[NUM_LANES];

void* car(void* arg) {
    int car_id = *((int*)arg);
    for (int i = 0; i < NUM_ROUNDS; i++) {
        int lane_id = rand() % NUM_LANES;

        // Try to enter a lane
        printf("Car %d trying to enter lane %d\n", car_id, lane_id);
        sem_wait(&lanes[lane_id]);
        printf("Car %d entered lane %d\n", car_id, lane_id);

        // Simulate driving in the lane
        int drive_time = rand() % 3 + 1; // Random driving time between 1 to 3 seconds
        sleep(drive_time);

        printf("Car %d leaving lane %d after %d seconds\n", car_id, lane_id, drive_time);
        sem_post(&lanes[lane_id]);
        
        // Random pause before trying to enter a lane again
        sleep(rand() % 3);
    }
    free(arg);
    return NULL;
}

int main() {
    pthread_t cars[NUM_CARS];
    srand(time(NULL));

    // Initialize semaphores for the lanes
    for (int i = 0; i < NUM_LANES; i++) {
        sem_init(&lanes[i], 0, 1); // Initialize each lane with 1 car capacity
    }

    // Create car threads
    for (int i = 0; i < NUM_CARS; i++) {
        int* car_id = malloc(sizeof(int));
        *car_id = i;
        if (pthread_create(&cars[i], NULL, car, car_id) != 0) {
            perror("Failed to create car thread");
            free(car_id);
            return 1;
        }
    }

    // Join car threads
    for (int i = 0; i < NUM_CARS; i++) {
        if (pthread_join(cars[i], NULL) != 0) {
            perror("Failed to join car thread");
            return 1;
        }
    }

    // Clean up semaphores
    for (int i = 0; i < NUM_LANES; i++) {
        sem_destroy(&lanes[i]);
    }

    printf("Traffic simulation completed.\n");
    
    return 0;
}