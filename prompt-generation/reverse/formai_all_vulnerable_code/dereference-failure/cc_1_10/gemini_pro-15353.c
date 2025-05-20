//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Road segments
#define ROAD_A 0
#define ROAD_B 1

// Maximum number of cars
#define MAX_CARS 10

// Car structure
typedef struct {
    int id;
    int road;
    int direction;
    int state;
} car_t;

// Traffic light structure
typedef struct {
    int state;
    int timer;
} traffic_light_t;

// Semaphores
sem_t road_a_semaphore;
sem_t road_b_semaphore;
sem_t traffic_light_semaphore;

// Traffic light thread
void *traffic_light_thread(void *arg) {
    traffic_light_t *traffic_light = (traffic_light_t *)arg;

    while (1) {
        // Change the traffic light state
        switch (traffic_light->state) {
            case RED:
                traffic_light->state = GREEN;
                traffic_light->timer = 10;
                break;
            case YELLOW:
                traffic_light->state = RED;
                traffic_light->timer = 5;
                break;
            case GREEN:
                traffic_light->state = YELLOW;
                traffic_light->timer = 5;
                break;
        }

        // Sleep for the specified time
        sleep(traffic_light->timer);

        // Post the semaphore for the appropriate road
        switch (traffic_light->state) {
            case RED:
                sem_post(&road_a_semaphore);
                break;
            case GREEN:
                sem_post(&road_b_semaphore);
                break;
        }
    }

    return NULL;
}

// Car thread
void *car_thread(void *arg) {
    car_t *car = (car_t *)arg;

    while (1) {
        // Wait for the semaphore for the appropriate road
        switch (car->road) {
            case ROAD_A:
                sem_wait(&road_a_semaphore);
                break;
            case ROAD_B:
                sem_wait(&road_b_semaphore);
                break;
        }

        // Enter the intersection
        car->state = GREEN;

        // Sleep for the specified time
        sleep(1);

        // Exit the intersection
        car->state = RED;

        // Post the semaphore for the appropriate road
        switch (car->road) {
            case ROAD_A:
                sem_post(&road_b_semaphore);
                break;
            case ROAD_B:
                sem_post(&road_a_semaphore);
                break;
        }
    }

    return NULL;
}

int main() {
    // Initialize the semaphores
    sem_init(&road_a_semaphore, 0, 1);
    sem_init(&road_b_semaphore, 0, 0);
    sem_init(&traffic_light_semaphore, 0, 1);

    // Initialize the traffic light
    traffic_light_t traffic_light;
    traffic_light.state = RED;
    traffic_light.timer = 5;

    // Create the traffic light thread
    pthread_t traffic_light_thread_id;
    pthread_create(&traffic_light_thread_id, NULL, traffic_light_thread, &traffic_light);

    // Create the car threads
    pthread_t car_thread_id[MAX_CARS];
    for (int i = 0; i < MAX_CARS; i++) {
        car_t car;
        car.id = i;
        car.road = ROAD_A;
        car.direction = 1;
        car.state = RED;
        pthread_create(&car_thread_id[i], NULL, car_thread, &car);
    }

    // Join the threads
    pthread_join(traffic_light_thread_id, NULL);
    for (int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_thread_id[i], NULL);
    }

    // Destroy the semaphores
    sem_destroy(&road_a_semaphore);
    sem_destroy(&road_b_semaphore);
    sem_destroy(&traffic_light_semaphore);

    return 0;
}