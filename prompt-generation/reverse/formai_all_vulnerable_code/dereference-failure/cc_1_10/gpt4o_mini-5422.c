//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define MAX_CARS 50
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 2

sem_t intersection;             // Semaphore for controlling access to the intersection
int cars_waiting[4];            // Array to store waiting cars for each direction
int total_cars_passing[4] = {0}; // Total cars passed for each direction

void* car(void* arg) {
    int direction = *((int*)arg);
    free(arg);

    // Simulate car arrival; they will wait for the semaphore when trying to access the intersection
    printf("Car from direction %d is waiting to enter the intersection.\n", direction);
    sem_wait(&intersection);      // Wait for light to be green

    printf("Car from direction %d is now passing through the intersection.\n", direction);
    sleep(1); // Simulate the time taken to cross the intersection

    total_cars_passing[direction]++;
    
    printf("Car from direction %d has passed through the intersection.\n", direction);
    sem_post(&intersection);      // Release the semaphore
    return NULL;
}

void* traffic_light(void* arg) {
    while (1) {
        for (int i = 0; i < 4; i++) {
            printf("Traffic light for direction %d is GREEN for %d seconds.\n", i, GREEN_LIGHT_DURATION);
            sleep(GREEN_LIGHT_DURATION); // Light is green for traffic
            // Allow cars to pass while the light is green
            for (int j = 0; j < cars_waiting[i]; j++) {
                int* direction = malloc(sizeof(int));
                *direction = i;
                pthread_t car_thread;
                pthread_create(&car_thread, NULL, car, direction);
                pthread_detach(car_thread);
            }
            cars_waiting[i] = 0; // Reset the waiting count after the light
            printf("Traffic light for direction %d is now RED for %d seconds.\n", i, RED_LIGHT_DURATION);
            sleep(RED_LIGHT_DURATION); // Light is red for waiting
        }
    }
    return NULL;
}

int main() {
    srand(time(0));
    sem_init(&intersection, 0, 1); // Initialize semaphore with 1 permit
    pthread_t light_thread;

    pthread_create(&light_thread, NULL, traffic_light, NULL);
    
    // Simulating random car arrivals
    while (1) {
        int direction = rand() % 4; // Random direction for new car
        cars_waiting[direction]++;
        printf("New car arriving from direction %d. Total waiting: %d\n", direction, cars_waiting[direction]);
        sleep(rand() % 3 + 1); // Random wait before the next car arrival
    }
    
    pthread_join(light_thread, NULL);
    sem_destroy(&intersection);
    return 0;
}