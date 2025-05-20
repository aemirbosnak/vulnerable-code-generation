//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CARS 5
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 3

sem_t semaphore;

typedef struct {
    int id;
    int direction; // 0 - North, 1 - East, 2 - South, 3 - West
} Car;

void *car_behavior(void *arg) {
    Car *car = (Car *)arg;

    while (1) {
        printf("Car %d in direction %d is waiting to cross.\n", car->id, car->direction);
        sem_wait(&semaphore); // Request access to the intersection

        printf("Car %d is crossing the intersection.\n", car->id);
        sleep(GREEN_LIGHT_DURATION); // Simulate the time taken to cross

        printf("Car %d has crossed the intersection.\n", car->id);
        sem_post(&semaphore); // Release access
        sleep(RED_LIGHT_DURATION); // Simulate waiting time before attempting to cross again
    }

    free(car);
    return NULL;
}

int main() {
    printf("Welcome to the Traffic Flow Simulation!\n");
    
    sem_init(&semaphore, 0, MAX_CARS); // Initialize semaphore with the maximum number of cars allowed concurrently
    
    pthread_t threads[MAX_CARS];

    // Create cars and assign behavior
    for (int i = 0; i < MAX_CARS; i++) {
        Car *car = (Car *)malloc(sizeof(Car));
        car->id = i + 1;
        car->direction = rand() % 4; // Randomize direction for creativity

        printf("Creating car %d in direction %d.\n", car->id, car->direction);
        
        if (pthread_create(&threads[i], NULL, car_behavior, car) != 0) {
            printf("Error creating thread for car %d!\n", car->id);
            free(car);
        }
    }

    // Join threads to ensure they finish before exiting
    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); // Clean up the semaphore
    printf("Traffic Flow Simulation ended gracefully.\n");
    
    return 0;
}