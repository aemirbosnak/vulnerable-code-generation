//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <time.h>

#define NUM_CARS 10
#define MAX_TRAFFIC_LIGHT_DELAY 5
#define GREEN_LIGHT_DURATION 3
#define RED_LIGHT_DURATION 2

sem_t red_light;
sem_t green_light;

typedef struct {
    int id;
    int position;
} Car;

void* car_behavior(void* arg) {
    Car* car = (Car*)arg;
    while (true) {
        printf("Car %d is driving towards the intersection. (Position: %d)\n", car->id, car->position);
        sleep(1);
        car->position++;
        
        if (car->position >= 10) {
            printf("Car %d has passed the intersection!\n", car->id);
            break;
        }

        // Check at each position if the car approaches the traffic light
        if (car->position == 5) {
            printf("Car %d is waiting at the traffic light.\n", car->id);
            sem_wait(&red_light); // Wait if it's a red light
            printf("Car %d sees green light! Proceeding through the intersection.\n", car->id);
            sleep(GREEN_LIGHT_DURATION);
            sem_post(&green_light); // Signal the next car
        }
    }

    free(car);
    return NULL;
}

void* traffic_light_behavior(void* arg) {
    while (true) {
        printf("Traffic light is now RED.\n");
        sleep(RED_LIGHT_DURATION);
        
        sem_post(&red_light); // Allow cars to proceed
        printf("Traffic light is now GREEN.\n");
        sleep(GREEN_LIGHT_DURATION);
        sem_wait(&green_light); // Wait for the last car to pass
    }
    return NULL;
}

int main() {
    pthread_t cars[NUM_CARS];
    pthread_t traffic_light;
    
    sem_init(&red_light, 0, 0); // Starts with red light (no cars can go)
    sem_init(&green_light, 0, 0); // Starts with no cars passed

    // Start traffic light thread
    pthread_create(&traffic_light, NULL, traffic_light_behavior, NULL);

    // Create car threads
    for (int i = 0; i < NUM_CARS; ++i) {
        Car* car = malloc(sizeof(Car));
        car->id = i + 1;
        car->position = 0;
        pthread_create(&cars[i], NULL, car_behavior, car);
    }

    // Join car threads
    for (int i = 0; i < NUM_CARS; ++i) {
        pthread_join(cars[i], NULL);
    }

    // Join traffic light thread (although it runs forever, we won't reach here)
    // pthread_join(traffic_light, NULL); // Uncomment if you want to join

    // Clean up
    sem_destroy(&red_light);
    sem_destroy(&green_light);

    return 0;
}