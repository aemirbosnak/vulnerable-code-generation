//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FLOORS 10 // number of floors in the building
#define ELEVATOR_CAPACITY 5 // max capacity of the elevator

// Shared variables
int current_floor = 0; // starting at ground floor
int num_people = 0; // number of people inside the elevator
bool going_up = true; // initially going up
bool stopped = false; // initially not stopped
sem_t elevator_lock; // semaphore for elevator mutex
sem_t waiting_lock[NUM_FLOORS]; // semaphore for waiting mutex on each floor
sem_t elevator_move; // semaphore for signaling elevator movement
sem_t elevator_stop; // semaphore for signaling elevator stop

// Function to simulate elevator movement to a floor
void move_to_floor(int target_floor) {
    sem_wait(&elevator_lock); // lock elevator to simulate movement
    stopped = true; // stop elevator on the way to target floor
    while (current_floor != target_floor) {
        printf("Elevator is moving from floor %d...\n", current_floor);
        if (going_up) {
            current_floor++;
        } else {
            current_floor--;
        }
    }
    stopped = false; // resume elevator after reaching target floor
    sem_post(&elevator_move); // signal elevator movement to threads waiting on that
    sem_wait(&elevator_stop); // wait for elevator to stop at the floor
    sem_post(&elevator_lock); // unlock elevator after movement
}

// Function to simulate person waiting on a floor and entering the elevator
void *person_thread(void *arg) {
    int floor = *(int *)arg;
    printf("Person %d is waiting on floor %d\n", pthread_self(), floor);
    sem_wait(&waiting_lock[floor]); // wait for elevator to arrive at the floor
    sem_wait(&elevator_lock); // lock elevator to enter
    printf("Person %d entered the elevator\n", pthread_self());
    num_people++;
    sem_post(&elevator_lock); // unlock elevator after entering
    sem_post(&elevator_move); // signal elevator movement to threads waiting on that
    return NULL;
}

// Function to simulate elevator picking up people from a floor
void pickup_people(int floor) {
    sem_wait(&elevator_lock); // lock elevator to pick up people
    printf("Elevator arrived on floor %d\n", floor);
    sem_post(&waiting_lock[floor]); // signal person thread waiting on the floor
    while (num_people < ELEVATOR_CAPACITY) {
        sem_wait(&elevator_move); // wait for elevator movement signal
        if (stopped) { // check if elevator stopped on the way
            sem_post(&elevator_stop); // signal that elevator stopped at a floor
            sem_wait(&elevator_move); // wait for next movement signal
        }
        sem_wait(&elevator_lock); // lock elevator to pick up people
        printf("Elevator has %d people inside\n", num_people);
        sem_post(&elevator_lock); // unlock elevator after counting people
    }
    sem_post(&elevator_lock); // unlock elevator after picking up people
}

int main() {
    // Initialize semaphores
    sem_init(&elevator_lock, 0, 1);
    sem_init(&elevator_move, 0, 0);
    sem_init(&elevator_stop, 0, 0);
    for (int i = 0; i < NUM_FLOORS; i++) {
        sem_init(&waiting_lock[i], 0, 0);
    }

    // Create person threads for each floor
    pthread_t person_threads[NUM_FLOORS][ELEVATOR_CAPACITY];
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
            int *arg = malloc(sizeof(*arg));
            *arg = i;
            pthread_create(&person_threads[i][j], NULL, &person_thread, arg);
        }
    }

    // Move elevator to each floor and pick up people
    for (int i = 0; i < NUM_FLOORS; i++) {
        pickup_people(i);
        if (going_up && current_floor == NUM_FLOORS - 1) { // reached top floor
            going_up = false; // change direction to down
        } else if (!going_up && current_floor == 0) { // reached ground floor
            going_up = true; // change direction to up
        }
        move_to_floor((going_up ? current_floor + 1 : current_floor - 1));
    }

    // Join person threads after stopping the elevator on the top floor
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
            pthread_join(person_threads[i][j], NULL);
        }
    }

    // Destroy semaphores
    sem_destroy(&elevator_lock);
    sem_destroy(&elevator_move);
    sem_destroy(&elevator_stop);
    for (int i = 0; i < NUM_FLOORS; i++) {
        sem_destroy(&waiting_lock[i]);
    }

    return 0;
}