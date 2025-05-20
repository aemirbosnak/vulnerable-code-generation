//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CARS 10
#define ROAD_LENGTH 50
#define MAX_SPEED 5
#define MIN_SPEED 1

typedef struct Car {
    int car_id;
    int position;
    int speed;
    bool is_waiting;
} Car;

Car* cars[NUM_CARS];
sem_t road_sem;

void* drive(void* arg) {
    Car* car = (Car*)arg;
    while (car->position < ROAD_LENGTH) {
        car->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
        if (!car->is_waiting) {
            sem_wait(&road_sem);
            car->position += car->speed;
            printf("Car %d is now at position %d with speed %d\n", 
                    car->car_id, car->position, car->speed);
            sem_post(&road_sem);
        } else {
            printf("Car %d is waiting at position %d\n", car->car_id, car->position);
        }
        sleep(1);
    }
    printf("Car %d has reached the end of the road!\n", car->car_id);
    return NULL;
}

void* traffic_control(void* arg) {
    while (true) {
        sleep(5); // Control signal every 5 seconds
        sem_wait(&road_sem);
        for (int i = 0; i < NUM_CARS; i++) {
            if (cars[i]->position >= ROAD_LENGTH) {
                continue;
            }
            // Adjust waiting based on position
            if (cars[i]->position > ROAD_LENGTH - 10) {
                cars[i]->is_waiting = true;
            } else {
                cars[i]->is_waiting = false;
            }
        }
        sem_post(&road_sem);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    sem_init(&road_sem, 0, 1);

    pthread_t car_threads[NUM_CARS];
    pthread_t control_thread;

    // Initialize and create car threads
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i] = (Car*)malloc(sizeof(Car));
        cars[i]->car_id = i + 1;
        cars[i]->position = 0;
        cars[i]->speed = 0;
        cars[i]->is_waiting = false;
        pthread_create(&car_threads[i], NULL, drive, (void*)cars[i]);
    }

    // Create traffic control thread
    pthread_create(&control_thread, NULL, traffic_control, NULL);

    // Join car threads
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(car_threads[i], NULL);
        free(cars[i]);
    }

    // Cleanup and exit
    pthread_cancel(control_thread);
    sem_destroy(&road_sem);

    return 0;
}