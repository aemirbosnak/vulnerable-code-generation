//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_CARS 10
#define MAX_LANES 3
#define ROAD_LENGTH 20
#define TIME_DELAY 500000 // in microseconds

sem_t lanes[MAX_LANES];
pthread_mutex_t lock;

typedef struct {
    int id;
    int lane;
} Car;

void* drive(void* arg) {
    Car* car = (Car*)arg;
    
    for (int position = 0; position < ROAD_LENGTH; position++) {
        sem_wait(&lanes[car->lane]);
        pthread_mutex_lock(&lock);

        printf("Car %d is in Lane %d at position %d\n", car->id, car->lane, position);
        
        pthread_mutex_unlock(&lock);
        sem_post(&lanes[car->lane]);

        usleep(TIME_DELAY); // Simulating car movement speed
    }
    printf("Car %d has exited the road.\n", car->id);
    free(car);
    pthread_exit(NULL);
}

int main() {
    pthread_t cars[NUM_CARS];
    pthread_mutex_init(&lock, NULL);
    
    // Initialize semaphores for each lane
    for (int i = 0; i < MAX_LANES; i++) {
        sem_init(&lanes[i], 0, 1); // 1 car can occupy each lane at a time
    }

    // Randomly assign cars to lanes
    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = (Car*)malloc(sizeof(Car));
        car->id = i+1;
        car->lane = rand() % MAX_LANES; // Random lane assignment

        // Create a thread for each car
        if (pthread_create(&cars[i], NULL, drive, (void*)car) != 0) {
            perror("Failed to create thread");
            free(car);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(cars[i], NULL);
    }

    // Clean up
    for (int i = 0; i < MAX_LANES; i++) {
        sem_destroy(&lanes[i]);
    }
    pthread_mutex_destroy(&lock);

    return 0;
}