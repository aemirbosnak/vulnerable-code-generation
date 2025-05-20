//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define FLOORS 10
#define MAX_PASSENGERS 5

pthread_mutex_t mutex_key = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t elevator_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t elevator_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t waiting_passengers = PTHREAD_COND_INITIALIZER;

int elevator = 0;
int passengers_num = 0;

void* passenger(void* arg) {
    int* curr_floor = (int*) arg;
    sleep(rand() % 5 + 1); // simulate waiting before calling elevator
    printf("Passenger on floor %d is calling the elevator.\n", *curr_floor);
    pthread_mutex_lock(&mutex_key);

    while (elevator != *curr_floor || passengers_num == MAX_PASSENGERS) {
        pthread_cond_wait(&waiting_passengers, &mutex_key);
    }
    passengers_num++;
    printf("Passenger on floor %d enters elevator.\n", *curr_floor);
    if (passengers_num == MAX_PASSENGERS) {
        pthread_cond_signal(&elevator_full);
    }

    pthread_mutex_unlock(&mutex_key);
    return NULL;
}

void* elevator_func(void* arg) {
    int curr_floor = 0;
    int direction = 1;

    while (1) {
        pthread_mutex_lock(&mutex_key);

        while (passengers_num == 0) {
            pthread_cond_wait(&elevator_empty, &mutex_key);
        }

        printf("Elevator arrived at floor %d\n", curr_floor);

        if (curr_floor == FLOORS - 1) {
            direction = -1;
        } else if (curr_floor == 0) {
            direction = 1;
        }

        curr_floor += direction;
        elevator = curr_floor;
        printf("Elevator going to floor %d\n", curr_floor);

        pthread_cond_broadcast(&waiting_passengers);

        if (passengers_num == MAX_PASSENGERS) {
            pthread_cond_wait(&elevator_full, &mutex_key);
        } else {
            pthread_cond_broadcast(&elevator_empty);
        }

        passengers_num = 0;

        pthread_mutex_unlock(&mutex_key);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t elevator_thread;
    pthread_t floor_threads[FLOORS];

    pthread_create(&elevator_thread, NULL, elevator_func, NULL);

    for (int i = 0; i < FLOORS; i++) {
        int* curr_floor = malloc(sizeof(int));
        *curr_floor = i;
        pthread_create(&floor_threads[i], NULL, passenger, curr_floor);
    }

    pthread_join(elevator_thread, NULL);

    for (int i = 0; i < FLOORS; i++) {
        pthread_join(floor_threads[i], NULL);
    }

    return 0;
}