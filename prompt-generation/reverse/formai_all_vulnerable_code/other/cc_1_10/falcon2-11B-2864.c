//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 5
#define MAX_ELEVATORS 2
#define ELEVATOR_SPEED 1

#define ELEVATOR_IDLE 0
#define ELEVATOR_GOING_DOWN 1
#define ELEVATOR_GOING_UP 2

struct elevator {
    int floor;
    int passengers;
    int state;
};

struct elevator elevators[MAX_ELEVATORS];
int elevator_count = 0;

sem_t elevators_available[MAX_ELEVATORS];
sem_t elevators_not_full[MAX_ELEVATORS];

sem_t passengers_waiting[MAX_FLOORS];
sem_t passengers_disembarking[MAX_FLOORS];

struct timeval start_time;
struct timeval end_time;

void wait_until_floor_is_available(int floor, int elevator_id) {
    sem_wait(&elevators_available[elevator_id]);
    printf("Elevator %d is available on floor %d\n", elevator_id, floor);
}

void wait_until_elevator_is_empty(int elevator_id) {
    sem_wait(&elevators_not_full[elevator_id]);
    printf("Elevator %d is empty\n", elevator_id);
}

void wait_until_passenger_disembarks(int floor) {
    sem_wait(&passengers_disembarking[floor]);
    printf("Passenger has disembarked on floor %d\n", floor);
}

void wait_until_passenger_arrives(int floor) {
    sem_wait(&passengers_waiting[floor]);
    printf("Passenger has arrived on floor %d\n", floor);
}

int main() {
    sem_init(&elevators_available[0], 0, 0);
    sem_init(&elevators_not_full[0], 0, 0);

    sem_init(&passengers_waiting[0], 0, 0);
    sem_init(&passengers_disembarking[0], 0, 0);

    gettimeofday(&start_time, NULL);

    while(1) {
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].state == ELEVATOR_IDLE) {
                elevator_count++;
                elevators[i].floor = 0;
                elevators[i].passengers = 0;
                elevators[i].state = ELEVATOR_GOING_DOWN;
                sem_post(&elevators_available[i]);
                break;
            }
        }

        for (int i = 0; i < MAX_FLOORS; i++) {
            if (i == elevators[0].floor && elevators[0].passengers < MAX_PASSENGERS) {
                sem_wait(&passengers_waiting[i]);
                elevators[0].passengers++;
                sem_post(&passengers_disembarking[i]);
            } else if (i == elevators[1].floor && elevators[1].passengers < MAX_PASSENGERS) {
                sem_wait(&passengers_waiting[i]);
                elevators[1].passengers++;
                sem_post(&passengers_disembarking[i]);
            } else {
                sem_wait(&passengers_waiting[i]);
            }
        }

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].state == ELEVATOR_GOING_UP) {
                elevators[i].floor--;
                sem_wait(&elevators_not_full[i]);
                if (elevators[i].floor == 0) {
                    elevators[i].state = ELEVATOR_IDLE;
                    sem_post(&elevators_available[i]);
                } else {
                    sem_post(&elevators_not_full[i]);
                }
            } else if (elevators[i].state == ELEVATOR_GOING_DOWN) {
                elevators[i].floor++;
                sem_wait(&elevators_not_full[i]);
                if (elevators[i].floor == MAX_FLOORS) {
                    elevators[i].state = ELEVATOR_IDLE;
                    sem_post(&elevators_available[i]);
                } else {
                    sem_post(&elevators_not_full[i]);
                }
            }
        }

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].state == ELEVATOR_GOING_UP || elevators[i].state == ELEVATOR_GOING_DOWN) {
                wait_until_passenger_arrives(elevators[i].floor);
                elevators[i].state = ELEVATOR_GOING_UP;
            } else if (elevators[i].state == ELEVATOR_IDLE) {
                wait_until_floor_is_available(elevators[i].floor, i);
                elevators[i].state = ELEVATOR_GOING_UP;
            }
        }

        for (int i = 0; i < MAX_FLOORS; i++) {
            if (elevators[0].floor == i && elevators[0].passengers >= MAX_PASSENGERS) {
                wait_until_elevator_is_empty(0);
                elevators[0].floor = 0;
                elevators[0].passengers = 0;
                elevators[0].state = ELEVATOR_GOING_UP;
                sem_post(&elevators_available[0]);
            } else if (elevators[1].floor == i && elevators[1].passengers >= MAX_PASSENGERS) {
                wait_until_elevator_is_empty(1);
                elevators[1].floor = 0;
                elevators[1].passengers = 0;
                elevators[1].state = ELEVATOR_GOING_UP;
                sem_post(&elevators_available[1]);
            }
        }

        for (int i = 0; i < MAX_ELEVATORS; i++) {
            if (elevators[i].state == ELEVATOR_GOING_UP) {
                wait_until_passenger_disembarks(elevators[i].floor);
                elevators[i].state = ELEVATOR_GOING_UP;
            } else if (elevators[i].state == ELEVATOR_GOING_DOWN) {
                wait_until_passenger_disembarks(elevators[i].floor);
                elevators[i].state = ELEVATOR_GOING_DOWN;
            }
        }

        gettimeofday(&end_time, NULL);
        double elapsed_time = difftime(end_time.tv_sec, start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Elapsed time: %f seconds\n", elapsed_time);
    }
}