//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

#define MAX_PASSENGERS 10
#define ELEVATOR_CAPACITY 5
#define NUM_FLOORS 10

typedef enum {
    IDLE,
    LOADING,
    UNLOADING,
    MOVING
} State;

typedef struct {
    int id;
    int destination;
} Passenger;

typedef struct {
    sem_t mutex;
    sem_t floor_queue[NUM_FLOORS];
    sem_t door;
    sem_t elevator;
    State state;
    int curr_floor;
    int num_passengers;
    Passenger passengers[ELEVATOR_CAPACITY];
} Elevator;

Elevator* elevator;

Passenger createPassenger(int id) {
    Passenger p;
    p.id = id;
    p.destination = rand() % NUM_FLOORS;
    return p;
}

void* passengerArrives(void* arg) {
    int id = *(int*)arg;

    printf("Passenger %d has arrived at floor %d\n", id, elevator->curr_floor);

    sem_wait(&elevator->mutex);
    sem_wait(&elevator->floor_queue[elevator->curr_floor]);

    if (elevator->num_passengers < ELEVATOR_CAPACITY) {
        Passenger p = createPassenger(id);
        elevator->passengers[elevator->num_passengers] = p;
        elevator->num_passengers++;
        printf("Passenger %d has entered the elevator\n", id);

        if (elevator->num_passengers == ELEVATOR_CAPACITY) {
            sem_post(&elevator->door);
        }
    }
    sem_post(&elevator->floor_queue[elevator->curr_floor]);
    sem_post(&elevator->mutex);
    pthread_exit(0);
}

void* runElevator(void* arg) {
    while (true) {
        sem_wait(&elevator->door);
        elevator->state = LOADING;
        printf("Elevator door is closing...\n");
        sleep(2);

        if (elevator->state == IDLE) {
            int target_floor = elevator->passengers[0].destination;
            if (target_floor > elevator->curr_floor) {
                elevator->state = MOVING;
                printf("Elevator is moving from floor %d to floor %d\n", elevator->curr_floor, target_floor);
                sleep(3 * (target_floor - elevator->curr_floor));
            }
        }

        sem_wait(&elevator->mutex);

        int i, j;
        for (i = 0; i < elevator->num_passengers; i++) {
            if (elevator->passengers[i].destination == elevator->curr_floor) {
                printf("Passenger %d has exited the elevator\n", elevator->passengers[i].id);
                for (j = i; j < elevator->num_passengers-1; j++) {
                    elevator->passengers[j] = elevator->passengers[j+1];
                }
                elevator->num_passengers--;
                i--;
            }
        }

        if (elevator->num_passengers == 0) {
            sem_wait(&elevator->floor_queue[elevator->curr_floor]);
            sem_post(&elevator->floor_queue[elevator->curr_floor]);
            elevator->state = IDLE;
            printf("Elevator is idle at floor %d\n", elevator->curr_floor);
        } else {
            int target_floor = elevator->passengers[0].destination;
            if (target_floor > elevator->curr_floor) {
                elevator->state = MOVING;
                printf("Elevator is moving from floor %d to floor %d\n", elevator->curr_floor, target_floor);
                sleep(3 * (target_floor - elevator->curr_floor));
            }
            else if (target_floor < elevator->curr_floor) {
                elevator->state = MOVING;
                printf("Elevator is moving from floor %d to floor %d\n", elevator->curr_floor, target_floor);
                sleep(3 * (elevator->curr_floor - target_floor));
            }
        }

        if (elevator->state == MOVING) {
            sem_post(&elevator->floor_queue[elevator->curr_floor]);
            elevator->curr_floor = elevator->passengers[0].destination;
            sem_wait(&elevator->floor_queue[elevator->curr_floor]);
            elevator->state = UNLOADING;
            printf("Elevator has arrived at floor %d and is unloading\n", elevator->curr_floor);
            sleep(2);
        }

        sem_post(&elevator->mutex);
        sem_post(&elevator->elevator);
        sleep(2);
    }
    pthread_exit(0);
}

void* runFloor(void* arg) {
    int floor = *(int*)arg;
    while (true) {
        Passenger p = createPassenger(rand() % MAX_PASSENGERS);
        printf("Passenger %d has arrived on floor %d and is waiting for the elevator\n", p.id, floor);

        sem_wait(&elevator->floor_queue[floor]);
        sem_post(&elevator->floor_queue[floor]);

        sem_wait(&elevator->mutex);
        if (elevator->num_passengers == 0) {
            sem_wait(&elevator->elevator);
        }
        sem_post(&elevator->mutex);

        pthread_t passenger_thread;
        pthread_create(&passenger_thread, NULL, passengerArrives, (void*)&p.id);

        if (elevator->num_passengers == ELEVATOR_CAPACITY) {
            sem_wait(&elevator->door);
        }
        sleep(2 * (rand() % 5));
    }
    pthread_exit(0);
}

int main() {
    srand(time(NULL));

    elevator = malloc(sizeof(Elevator));
    elevator->state = IDLE;
    elevator->curr_floor = 0;
    elevator->num_passengers = 0;
    sem_init(&elevator->mutex, 0, 1);
    sem_init(&elevator->door, 0, 1);
    sem_init(&elevator->elevator, 0, 0);

    int i;
    for (i = 0; i < NUM_FLOORS; i++) {
        sem_init(&elevator->floor_queue[i], 0, 1);
    }

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, runElevator, NULL);

    pthread_t floor_threads[NUM_FLOORS];
    for (i = 0; i < NUM_FLOORS; i++) {
        int* floor = malloc(sizeof(int));
        *floor = i;
        pthread_create(&floor_threads[i], NULL, runFloor, (void*)floor);
    }

    for (i = 0; i < NUM_FLOORS; i++) {
        pthread_join(floor_threads[i], NULL);
    }
    pthread_join(elevator_thread, NULL);

    return 0;
}