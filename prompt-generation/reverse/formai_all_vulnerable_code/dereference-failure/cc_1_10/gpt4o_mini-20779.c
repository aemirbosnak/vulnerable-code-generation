//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_CARS 10
#define MAX_CARS_ON_ROAD 5
#define ROAD_LENGTH 50

sem_t roadAccess;
int carsOnRoad = 0;

typedef struct {
    int id;
} Car;

void* simulateCar(void* arg) {
    Car* car = (Car*)arg;
    printf("Car %d is ready to enter the road.\n", car->id);

    // Wait for road access
    sem_wait(&roadAccess);

    // Simulate car entering road
    __sync_fetch_and_add(&carsOnRoad, 1);
    printf("Car %d has entered the road. Cars on road: %d\n", car->id, carsOnRoad);

    // Simulate driving on the road
    for (int i = 0; i < ROAD_LENGTH; i++) {
        printf("Car %d is driving... (Position %d)\n", car->id, i);
        sleep(1); // simulate time taken to drive
    }

    // Simulate car exiting the road
    __sync_fetch_and_sub(&carsOnRoad, 1);
    printf("Car %d has exited the road. Cars on road: %d\n", car->id, carsOnRoad);

    // Signal that road is available
    sem_post(&roadAccess);
    
    free(car);
    return NULL;
}

int main() {
    pthread_t threads[NUM_CARS];
    sem_init(&roadAccess, 0, MAX_CARS_ON_ROAD);
    
    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = malloc(sizeof(Car));
        car->id = i + 1;
        pthread_create(&threads[i], NULL, simulateCar, (void*)car);
        
        // Random delay before the next car arrives
        sleep(rand() % 3); 
    }

    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&roadAccess);
    printf("All cars have exited the road.\n");
    
    return 0;
}