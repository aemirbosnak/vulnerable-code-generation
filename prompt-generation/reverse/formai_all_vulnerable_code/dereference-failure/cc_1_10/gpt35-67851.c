//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// number of floors
#define FLOORS 6

// number of elevators
#define ELEVATORS 2

// status of an elevator
typedef enum ElevatorStatus {
    IDLE,
    MOVING,
    STOPPED
} ElevatorStatus;

// direction of an elevator
typedef enum ElevatorDirection {
    UP,
    DOWN
} ElevatorDirection;

// elevator struct
typedef struct Elevator {
    int id; // elevator ID
    int currentFloor; // current floor of the elevator
    ElevatorDirection direction; // direction of the elevator
    ElevatorStatus status; // status of the elevator
    int passengers; // number of passengers in the elevator
} Elevator;

// floor struct
typedef struct Floor {
    int floorNumber; // floor number
    int passengersWaiting; // number of passengers waiting on the floor
    pthread_mutex_t mutex; // mutex for accessing passengersWaiting
    pthread_cond_t condition; // condition variable for signalling elevator arrival
} Floor;

// global variables
Elevator elevators[ELEVATORS];
Floor floors[FLOORS];

// function to simulate passenger arrival on a floor
void *passengerArrival(void *arg) {
    int arrivalFloor = *(int *)arg;
    printf("Passenger has arrived on floor %d\n", arrivalFloor);
    pthread_mutex_lock(&floors[arrivalFloor].mutex);
    floors[arrivalFloor].passengersWaiting++;
    pthread_cond_signal(&floors[arrivalFloor].condition);
    pthread_mutex_unlock(&floors[arrivalFloor].mutex);
}

// function to simulate elevator operation (i.e. move between floors, pick-up/drop-off passengers)
void *elevatorOperation(void *arg) {
    Elevator *elevator = (Elevator *)arg;
    while (true) {
        if (elevator->status == MOVING) {
            printf("Elevator %d is moving\n", elevator->id);
            usleep(500000); // simulate elevator speed
            if (elevator->direction == UP) {
                elevator->currentFloor++;
            } else {
                elevator->currentFloor--;
            }
            if (elevator->currentFloor == FLOORS - 1) {
                elevator->direction = DOWN;
            } else if (elevator->currentFloor == 0) {
                elevator->direction = UP;
            }
        } else {
            printf("Elevator %d is stopped\n", elevator->id);
            pthread_mutex_lock(&floors[elevator->currentFloor].mutex);
            while (floors[elevator->currentFloor].passengersWaiting == 0) {
                pthread_cond_wait(&floors[elevator->currentFloor].condition, &floors[elevator->currentFloor].mutex);
            }
            printf("Elevator %d doors are opening on floor %d\n", elevator->id, elevator->currentFloor);
            int passengers = floors[elevator->currentFloor].passengersWaiting;
            floors[elevator->currentFloor].passengersWaiting = 0;
            pthread_mutex_unlock(&floors[elevator->currentFloor].mutex);
            printf("Elevator %d has picked up %d passengers from floor %d\n", elevator->id, passengers, elevator->currentFloor);
            elevator->passengers += passengers;
            printf("Elevator %d is now carrying %d passengers\n", elevator->id, elevator->passengers);
            elevator->status = MOVING;
        }
        usleep(500000); // simulate elevator operation speed
    }
}

int main() {
    // initialize elevators
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].id = i;
        elevators[i].currentFloor = 0;
        elevators[i].direction = UP;
        elevators[i].status = IDLE;
        elevators[i].passengers = 0;
    }

    // initialize floors
    for (int i = 0; i < FLOORS; i++) {
        floors[i].floorNumber = i;
        floors[i].passengersWaiting = 0;
        pthread_mutex_init(&floors[i].mutex, NULL);
        pthread_cond_init(&floors[i].condition, NULL);
    }

    // create passenger threads
    pthread_t passengerThreads[FLOORS][10];
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < 10; j++) {
            int *arg = malloc(sizeof(*arg));
            *arg = i;
            pthread_create(&passengerThreads[i][j], NULL, passengerArrival, arg);
        }
    }

    // create elevator threads
    pthread_t elevatorThreads[ELEVATORS];
    for (int i = 0; i < ELEVATORS; i++) {
        pthread_create(&elevatorThreads[i], NULL, elevatorOperation, &elevators[i]);
    }

    // wait for threads to complete
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < 10; j++) {
            pthread_join(passengerThreads[i][j], NULL);
        }
    }
    for (int i = 0; i < ELEVATORS; i++) {
        pthread_join(elevatorThreads[i], NULL);
    }

    return 0;
}