//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define FLOORS 10
#define MAX_CAPACITY 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct Elevator {
    int curr_floor;
    int direction;
    int capacity;
    int passengers[MAX_CAPACITY];
} elevator = {0, 1, 0, {0}};

bool floor_requests[FLOORS] = {false};

void* elevator_thread(void* arg) {
    while(true) {
        // check if there are any floor requests
        bool has_request = false;
        pthread_mutex_lock(&mutex);
        for(int i = 0; i < FLOORS; i++) {
            if(floor_requests[i]) {
                has_request = true;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);

        if(!has_request) continue;

        // move the elevator to the requested floor
        if(elevator.direction == 1) {
            for(int i = elevator.curr_floor; i < FLOORS; i++) {
                if(floor_requests[i]) {
                    elevator.curr_floor = i;
                    printf("Elevator moving up to floor %d\n", i);
                    usleep(500000);
                }
            }
            elevator.direction = -1;
        }
        else {
            for(int i = elevator.curr_floor; i >= 0; i--) {
                if(floor_requests[i]) {
                    elevator.curr_floor = i;
                    printf("Elevator moving down to floor %d\n", i);
                    usleep(500000);
                }
            }
            elevator.direction = 1;
        }

        // let passengers leave the elevator
        for(int i = 0; i < elevator.capacity; i++) {
            if(elevator.passengers[i] == elevator.curr_floor) {
                elevator.passengers[i] = 0;
                elevator.capacity--;
            }
        }

        // let waiting passengers inside the elevator
        for(int i = 0; i < elevator.capacity; i++) {
            pthread_mutex_lock(&mutex);
            if(floor_requests[elevator.passengers[i]]) {
                floor_requests[elevator.passengers[i]] = false;
                usleep(500000);
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    pthread_exit(NULL);
}

void* passenger_thread(void* arg) {
    int floor = *(int*)arg;

    // wait for elevator
    printf("Passenger on floor %d waiting for elevator...\n", floor);
    while(elevator.curr_floor != floor) {
        usleep(300000);
    }

    // board the elevator
    pthread_mutex_lock(&mutex);
    if(elevator.capacity < MAX_CAPACITY) {
        elevator.passengers[elevator.capacity++] = floor;
        printf("Passenger on floor %d boarded the elevator\n", floor);
        floor_requests[floor] = false;
    }
    pthread_mutex_unlock(&mutex);

    // wait until the elevator reaches the desired floor
    while(elevator.curr_floor != floor) {
        usleep(300000);
    }

    // exit the elevator
    pthread_mutex_lock(&mutex);
    for(int i = 0; i < elevator.capacity; i++) {
        if(elevator.passengers[i] == floor) {
            elevator.passengers[i] = 0;
            elevator.capacity--;
            printf("Passenger on floor %d exited the elevator\n", floor);
            break;
        }
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t elevator_t, passenger_t[FLOORS];
    pthread_create(&elevator_t, NULL, elevator_thread, NULL);

    for(int i = 0; i < FLOORS; i++) {
        int* arg = (int*)malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&passenger_t[i], NULL, passenger_thread, arg);
    }

    pthread_join(elevator_t, NULL);

    for(int i = 0; i < FLOORS; i++) {
        pthread_join(passenger_t[i], NULL);
    }

    return 0;
}