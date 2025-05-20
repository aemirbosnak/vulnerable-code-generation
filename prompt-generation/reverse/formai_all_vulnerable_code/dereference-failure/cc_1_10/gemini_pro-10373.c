//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3
#define NUM_PASSENGERS 100

// Passenger states
#define WAITING 0
#define BOARDING 1
#define RIDING 2
#define EXITING 3

// Elevator states
#define IDLE 0
#define MOVING 1
#define OPENING 2
#define CLOSING 3

// Thread parameters
typedef struct {
    int id;
    int destination;
    int state;
} passenger_t;

typedef struct {
    int id;
    int current_floor;
    int target_floor;
    int state;
} elevator_t;

// Mutexes and condition variables
pthread_mutex_t elevator_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t passenger_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t elevator_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t passenger_cond = PTHREAD_COND_INITIALIZER;

// Passenger threads
void *passenger_thread(void *args) {
    passenger_t *passenger = (passenger_t *)args;

    // Wait for elevator
    pthread_mutex_lock(&passenger_mutex);
    while (passenger->state == WAITING) {
        pthread_cond_wait(&passenger_cond, &passenger_mutex);
    }
    pthread_mutex_unlock(&passenger_mutex);

    // Board elevator
    pthread_mutex_lock(&elevator_mutex);
    passenger->state = BOARDING;
    pthread_cond_signal(&elevator_cond);
    while (passenger->state == BOARDING) {
        pthread_cond_wait(&passenger_cond, &elevator_mutex);
    }
    pthread_mutex_unlock(&elevator_mutex);

    // Ride elevator
    passenger->state = RIDING;
    while (passenger->state == RIDING) {
        sleep(1);
    }

    // Exit elevator
    pthread_mutex_lock(&elevator_mutex);
    passenger->state = EXITING;
    pthread_cond_signal(&elevator_cond);
    while (passenger->state == EXITING) {
        pthread_cond_wait(&passenger_cond, &elevator_mutex);
    }
    pthread_mutex_unlock(&elevator_mutex);

    return NULL;
}

// Elevator threads
void *elevator_thread(void *args) {
    elevator_t *elevator = (elevator_t *)args;

    while (1) {
        // Wait for passengers
        pthread_mutex_lock(&elevator_mutex);
        while (elevator->state == IDLE) {
            pthread_cond_wait(&elevator_cond, &elevator_mutex);
        }
        pthread_mutex_unlock(&elevator_mutex);

        // Move elevator
        elevator->state = MOVING;
        while (elevator->current_floor != elevator->target_floor) {
            sleep(1);
            elevator->current_floor++;
        }

        // Open elevator doors
        elevator->state = OPENING;
        sleep(1);

        // Let passengers on and off
        pthread_mutex_lock(&elevator_mutex);
        elevator->state = CLOSING;
        pthread_cond_broadcast(&passenger_cond);
        while (elevator->state == CLOSING) {
            pthread_cond_wait(&elevator_cond, &elevator_mutex);
        }
        pthread_mutex_unlock(&elevator_mutex);

        // Move elevator
        elevator->target_floor = -1;
        elevator->state = IDLE;
    }

    return NULL;
}

int main() {
    // Create passenger threads
    pthread_t passenger_threads[NUM_PASSENGERS];
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passenger_t *passenger = malloc(sizeof(passenger_t));
        passenger->id = i;
        passenger->destination = rand() % NUM_FLOORS;
        passenger->state = WAITING;
        pthread_create(&passenger_threads[i], NULL, passenger_thread, passenger);
    }

    // Create elevator threads
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevator_t *elevator = malloc(sizeof(elevator_t));
        elevator->id = i;
        elevator->current_floor = 0;
        elevator->target_floor = -1;
        elevator->state = IDLE;
        pthread_create(&elevator_threads[i], NULL, elevator_thread, elevator);
    }

    // Join threads
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passenger_threads[i], NULL);
    }
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}