//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define FLOORS 10  // number of floors in the building
#define MAX_PASS 10 // maximum number of passengers allowed in the elevator

pthread_mutex_t mutex;     // mutex for synchronization
pthread_cond_t door_cond;  // condition variable for opening and closing of door

int curr_floor = 0;        // current floor of the elevator
int direction = 1;         // direction of the elevator, up or down
int occupancy = 0;         // current occupancy of the elevator

void * elevator (void * arg);
void * passenger (void * arg);

int main () {
    pthread_t elevator_thread, passenger_thread;

    // initialize mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&door_cond, NULL);

    // create elevator thread
    pthread_create(&elevator_thread, NULL, elevator, NULL);

    // create passenger threads
    int i;
    for (i = 0; i < FLOORS; i++) {
        int * floor = (int *)malloc(sizeof(int));
        *floor = i;
        pthread_create(&passenger_thread, NULL, passenger, (void *)floor);
        usleep(10000);
    }

    // join elevator thread
    pthread_join(elevator_thread, NULL);

    // destroy mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&door_cond);

    return 0;
}

void * elevator (void * arg) {
    while (1) {
        // wait for passengers to enter
        pthread_mutex_lock(&mutex);
        while (occupancy == 0) {
            pthread_cond_wait(&door_cond, &mutex);
        }

        // close door
        printf("Closing door at floor %d\n", curr_floor);
        occupancy = 0;

        // move elevator
        curr_floor += direction;
        printf("Moving %s from floor %d to floor %d\n",
               direction > 0 ? "up" : "down", curr_floor - direction, curr_floor);

        // open door
        printf("Opening door at floor %d\n", curr_floor);
        pthread_cond_broadcast(&door_cond);
        pthread_mutex_unlock(&mutex);

        // wait for passengers to exit
        usleep(500000);
    }
}

void * passenger (void * arg) {
    int * floor = (int *)arg;

    while (1) {
        // wait for elevator
        pthread_mutex_lock(&mutex);
        while (curr_floor != *floor) {
            pthread_cond_wait(&door_cond, &mutex);
        }

        // enter elevator
        if (occupancy < MAX_PASS) {
            printf("Passenger %lu entering elevator at floor %d\n",
                   pthread_self(), curr_floor);
            occupancy++;
        } else {
            printf("Passenger %lu waiting at floor %d\n",
                   pthread_self(), curr_floor);
        }

        // signal elevator
        pthread_cond_signal(&door_cond);
        pthread_mutex_unlock(&mutex);

        // wait for elevator
        usleep(1000000);

        // wait for elevator
        pthread_mutex_lock(&mutex);
        while (curr_floor != *floor + FLOORS - 1) {
            pthread_cond_wait(&door_cond, &mutex);
        }

        // exit elevator
        printf("Passenger %lu exiting elevator at floor %d\n",
               pthread_self(), curr_floor);
        occupancy--;

        // signal elevator
        pthread_cond_signal(&door_cond);
        pthread_mutex_unlock(&mutex);
    }
}