//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_CARS 5
#define NUM_LANES 3
#define MAX_CARS_PER_LANE 3
#define SIMULATION_DURATION 10

typedef struct {
    int id;
    int lane;
} Car;

sem_t lane_semaphores[NUM_LANES];
pthread_mutex_t print_mutex;

void* car_thread(void* arg) {
    Car* car = (Car*) arg;
    
    printf("Car %d is ready to enter lane %d.\n", car->id, car->lane);
    
    sem_wait(&lane_semaphores[car->lane]);
    
    pthread_mutex_lock(&print_mutex);
    printf("Car %d entered lane %d.\n", car->id, car->lane);
    pthread_mutex_unlock(&print_mutex);

    // Simulate time spent in lane
    usleep(rand() % 1000000);
    
    pthread_mutex_lock(&print_mutex);
    printf("Car %d is leaving lane %d.\n", car->id, car->lane);
    pthread_mutex_unlock(&print_mutex);
    
    sem_post(&lane_semaphores[car->lane]);
    
    free(car);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t cars[NUM_CARS];
    
    // Initialize semaphores for lanes
    for (int i = 0; i < NUM_LANES; ++i) {
        sem_init(&lane_semaphores[i], 0, MAX_CARS_PER_LANE);
    }

    // Initialize print mutex
    pthread_mutex_init(&print_mutex, NULL);

    // Create Car threads
    for (int i = 0; i < NUM_CARS; ++i) {
        Car* car = (Car*) malloc(sizeof(Car));
        car->id = i;
        car->lane = rand() % NUM_LANES; // randomize lane

        pthread_create(&cars[i], NULL, car_thread, (void*) car);
        usleep(50000); // Slight delay before the next car arrives
    }

    // Wait for all cars to finish
    for (int i = 0; i < NUM_CARS; ++i) {
        pthread_join(cars[i], NULL);
    }

    // Clean up
    for (int i = 0; i < NUM_LANES; ++i) {
        sem_destroy(&lane_semaphores[i]);
    }
    pthread_mutex_destroy(&print_mutex);

    printf("Simulation finished.\n");
    return 0;
}