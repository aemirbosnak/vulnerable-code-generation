//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define MAX_CARS 10
#define INTERSECTION_TIME 2 // Time in seconds that a car spends in the intersection

sem_t intersection; // Semaphore to control access to the intersection
int northCars = 0, southCars = 0, eastCars = 0, westCars = 0;

void* car(void* arg) {
    int direction = *((int*)arg);
    free(arg);

    // Simulate arrival at intersection
    printf("Car from direction %d is arriving at the intersection.\n", direction);
    sleep(rand() % 3); // Random delay before arriving

    if (sem_wait(&intersection) == 0) {
        // Entering intersection
        printf("Car from direction %d is entering the intersection.\n", direction);
        sleep(INTERSECTION_TIME); // Time spent in the intersection
        printf("Car from direction %d has left the intersection.\n", direction);
        sem_post(&intersection);
    }
    return NULL;
}

void* generateTraffic(void* arg) {
    while (1) {
        int direction = rand() % 4; // Random direction: 0=N, 1=S, 2=E, 3=W
        pthread_t tid;
        int* dirPtr = malloc(sizeof(int)); // Dynamically allocate memory for direction
        *dirPtr = direction;

        if (pthread_create(&tid, NULL, car, dirPtr) != 0) {
            perror("Failed to create thread");
        }
        
        usleep(rand() % 1000000); // Random time between car arrivals (up to 1 second)
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    sem_init(&intersection, 0, 1); // Initialize the semaphore
    pthread_t trafficGenerator;

    // Start generating traffic
    if (pthread_create(&trafficGenerator, NULL, generateTraffic, NULL) != 0) {
        perror("Failed to create traffic generator");
        return 1;
    }

    // Run simulation for 30 seconds
    sleep(30);

    // Clean up
    pthread_cancel(trafficGenerator);
    pthread_join(trafficGenerator, NULL);
    sem_destroy(&intersection);

    printf("Traffic simulation ended.\n");
    return 0;
}