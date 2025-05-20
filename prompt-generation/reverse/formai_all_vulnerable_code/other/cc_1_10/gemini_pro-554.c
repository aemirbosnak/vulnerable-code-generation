//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of floors and elevators
#define NUM_FLOORS 10
#define NUM_ELEVATORS 2

// Define the states of an elevator
#define ELEVATOR_IDLE 0
#define ELEVATOR_MOVING 1
#define ELEVATOR_DOOR_OPEN 2

// Define the direction of an elevator
#define ELEVATOR_UP 1
#define ELEVATOR_DOWN -1

// Structure to represent an elevator
typedef struct {
    int state;
    int direction;
    int current_floor;
    int destination_floor;
    sem_t mutex;
    sem_t door_mutex;
    sem_t wait_for_elevator;
} elevator_t;

// Array of elevators
elevator_t elevators[NUM_ELEVATORS];

// Semaphore to protect the array of elevators
sem_t elevators_mutex;

// Function to initialize an elevator
void elevator_init(elevator_t *elevator) {
    elevator->state = ELEVATOR_IDLE;
    elevator->direction = ELEVATOR_UP;
    elevator->current_floor = 1;
    elevator->destination_floor = 1;
    sem_init(&elevator->mutex, 0, 1);
    sem_init(&elevator->door_mutex, 0, 1);
    sem_init(&elevator->wait_for_elevator, 0, 0);
}

// Function to move an elevator
void *elevator_move(void *arg) {
    elevator_t *elevator = (elevator_t *)arg;

    while (1) {
        // Acquire the mutex to protect the elevator
        sem_wait(&elevator->mutex);

        // If the elevator is idle, wait for someone to press the button
        if (elevator->state == ELEVATOR_IDLE) {
            sem_wait(&elevator->wait_for_elevator);
        }

        // If the elevator is moving, continue moving in the same direction
        else if (elevator->state == ELEVATOR_MOVING) {
            if (elevator->direction == ELEVATOR_UP) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
        }

        // If the elevator has reached its destination floor, open the doors
        if (elevator->current_floor == elevator->destination_floor) {
            elevator->state = ELEVATOR_DOOR_OPEN;
            sem_post(&elevator->door_mutex);
        }

        // Release the mutex to protect the elevator
        sem_post(&elevator->mutex);
    }

    return NULL;
}

// Function to press the elevator button
void press_elevator_button(int floor) {
    // Acquire the mutex to protect the array of elevators
    sem_wait(&elevators_mutex);

    // Find an idle elevator
    int i;
    for (i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].state == ELEVATOR_IDLE) {
            break;
        }
    }

    // If an idle elevator was found, send it to the requested floor
    if (i < NUM_ELEVATORS) {
        elevators[i].destination_floor = floor;
        sem_post(&elevators[i].wait_for_elevator);
    }

    // Release the mutex to protect the array of elevators
    sem_post(&elevators_mutex);
}

// Function to enter the elevator
void enter_elevator(int floor) {
    // Acquire the mutex to protect the elevator
    sem_wait(&elevators_mutex);

    // Find an elevator that is on the current floor and moving in the desired direction
    int i;
    for (i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].current_floor == floor && elevators[i].direction == ELEVATOR_UP) {
            break;
        }
    }

    // If an elevator was found, enter it
    if (i < NUM_ELEVATORS) {
        sem_wait(&elevators[i].door_mutex);
        sem_post(&elevators[i].mutex);
    }

    // Release the mutex to protect the array of elevators
    sem_post(&elevators_mutex);
}

// Function to exit the elevator
void exit_elevator(int floor) {
    // Acquire the mutex to protect the elevator
    sem_wait(&elevators_mutex);

    // Find the elevator that is on the current floor
    int i;
    for (i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].current_floor == floor) {
            break;
        }
    }

    // If an elevator was found, exit it
    if (i < NUM_ELEVATORS) {
        sem_post(&elevators[i].door_mutex);
        sem_post(&elevators[i].mutex);
    }

    // Release the mutex to protect the array of elevators
    sem_post(&elevators_mutex);
}

// Main function
int main() {
    // Initialize the elevators
    int i;
    for (i = 0; i < NUM_ELEVATORS; i++) {
        elevator_init(&elevators[i]);
    }

    // Create threads for the elevators
    pthread_t elevator_threads[NUM_ELEVATORS];
    for (i = 0; i < NUM_ELEVATORS; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_move, &elevators[i]);
    }

    // Press the elevator button on the first floor
    press_elevator_button(1);

    // Enter the elevator on the first floor
    enter_elevator(1);

    // Exit the elevator on the fifth floor
    exit_elevator(5);

    // Press the elevator button on the fifth floor
    press_elevator_button(5);

    // Wait for the elevator to arrive on the fifth floor
    sem_wait(&elevators[0].wait_for_elevator);

    // Enter the elevator on the fifth floor
    enter_elevator(5);

    // Exit the elevator on the first floor
    exit_elevator(1);

    // Wait for the elevator threads to finish
    for (i = 0; i < NUM_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    return 0;
}