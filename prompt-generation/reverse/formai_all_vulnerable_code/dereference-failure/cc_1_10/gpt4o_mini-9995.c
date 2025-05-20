//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CARS 10
#define INTERSECTION_SIZE 5

typedef struct {
    int id;
    int position;
    int speed;
} Car;

Car* cars[MAX_CARS];
pthread_mutex_t lock;

void* car_behavior(void* arg) {
    Car* car = (Car*)arg;

    while (1) {
        sleep(rand() % 3); // Random delay before moving
        pthread_mutex_lock(&lock); 

        if (car->position < INTERSECTION_SIZE) {
            car->position += car->speed;
            printf("Car %d is at position %d\n", car->id, car->position);
        } else {
            printf("Car %d has exited the intersection.\n", car->id);
            free(car);
            pthread_mutex_unlock(&lock);
            return NULL;
        }

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void create_cars(int num_cars) {
    srand(time(NULL));
    for (int i = 0; i < num_cars; i++) {
        Car* car = (Car*)malloc(sizeof(Car));
        car->id = i + 1;
        car->position = 0; // Start at position 0
        car->speed = rand() % 3 + 1; // Speed between 1 and 3

        cars[i] = car;
        pthread_t tid;
        pthread_create(&tid, NULL, car_behavior, car);
        pthread_detach(tid); // Detach thread to avoid joining
    }
}

int main() {
    printf("=== Futuristic Traffic Flow Simulation ===\n");
    printf("Initializing...\n");

    pthread_mutex_init(&lock, NULL);

    create_cars(MAX_CARS);

    // Simulate for a set amount of time
    sleep(20); // Run simulation for 20 seconds

    pthread_mutex_destroy(&lock);
    printf("Simulation ended. All cars have left the intersection.\n");

    return 0;
}