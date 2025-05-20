//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Elevator states
typedef enum {
    IDLE,
    UP,
    DOWN
} ElevatorState;

// Elevator structure
typedef struct {
    int current_floor;
    ElevatorState state;
    sem_t mutex;
    sem_t up_queue;
    sem_t down_queue;
} Elevator;

// Initialize elevator
void elevator_init(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->state = IDLE;
    sem_init(&elevator->mutex, 0, 1);
    sem_init(&elevator->up_queue, 0, 0);
    sem_init(&elevator->down_queue, 0, 0);
}

// Request elevator to go up
void request_up(Elevator *elevator, int floor) {
    sem_wait(&elevator->mutex);
    elevator->state = UP;
    sem_post(&elevator->up_queue);
    sem_post(&elevator->mutex);
}

// Request elevator to go down
void request_down(Elevator *elevator, int floor) {
    sem_wait(&elevator->mutex);
    elevator->state = DOWN;
    sem_post(&elevator->down_queue);
    sem_post(&elevator->mutex);
}

// Elevator thread function
void *elevator_thread(void *arg) {
    Elevator *elevator = (Elevator *)arg;

    while (1) {
        // Wait for a request
        if (elevator->state == UP) {
            sem_wait(&elevator->up_queue);
        } else if (elevator->state == DOWN) {
            sem_wait(&elevator->down_queue);
        }

        // Move elevator to the next floor
        if (elevator->state == UP) {
            elevator->current_floor++;
        } else if (elevator->state == DOWN) {
            elevator->current_floor--;
        }

        // Check if elevator has reached its destination
        if (elevator->current_floor == 0) {
            elevator->state = IDLE;
        }
    }

    return NULL;
}

// Main function
int main() {
    // Create elevator
    Elevator elevator;
    elevator_init(&elevator);

    // Create elevator thread
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_thread, &elevator);

    // Request elevator to go up
    request_up(&elevator, 5);

    // Request elevator to go down
    request_down(&elevator, 2);

    // Wait for elevator thread to finish
    pthread_join(elevator_thread, NULL);

    return 0;
}