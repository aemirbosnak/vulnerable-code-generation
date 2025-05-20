//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_CARS 10
#define MAX_WAIT 3

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct {
    int id;
    int direction; // 0 = North, 1 = East, 2 = South, 3 = West
} Car;

void* car_behavior(void* arg) {
    Car* car = (Car*)arg;
    
    // Simulate finding a space at the intersection
    int wait_time = rand() % MAX_WAIT + 1; // Random wait time between 1 and MAX_WAIT seconds
    printf("Car %d from direction %d is approaching the intersection and will wait for %d seconds.\n",
           car->id, car->direction, wait_time);
    
    sleep(wait_time);

    pthread_mutex_lock(&mutex);
    printf("Car %d from direction %d is now entering the intersection.\n", car->id, car->direction);
    // Simulating time spent in crossing the intersection
    sleep(1);
    printf("Car %d from direction %d has exited the intersection.\n", car->id, car->direction);
    pthread_mutex_unlock(&mutex);

    free(car); // Free memory allocated for Car
    return NULL;
}

int main() {
    pthread_t threads[NUM_CARS];
    srand(time(NULL));

    for (int i = 0; i < NUM_CARS; i++) {
        Car* car = malloc(sizeof(Car));
        if (car == NULL) {
            perror("Failed to allocate memory for car");
            exit(EXIT_FAILURE);
        }
        car->id = i + 1;
        car->direction = rand() % 4; // Random direction for the car
        
        if (pthread_create(&threads[i], NULL, car_behavior, car) != 0) {
            perror("Failed to create thread");
            free(car);
            exit(EXIT_FAILURE);
        }
        
        // Sleep before creating the next car to simulate arriving at different times
        sleep(rand() % 2);
    }

    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All cars have crossed the intersection.\n");

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}