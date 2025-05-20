//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOOR 10
#define MAX_PASSENGERS 20

pthread_mutex_t mutex;
pthread_cond_t cond[MAX_FLOOR];

int passenger_count[MAX_FLOOR];
int current_floor = 0;
int elevator_status = 1;
int passengers_in_elevator = 0;

void load_passengers(int floor_number) {
    pthread_mutex_lock(&mutex);
    while(passenger_count[floor_number] <= 0 || passengers_in_elevator >= MAX_PASSENGERS || elevator_status == -1) {
        pthread_cond_wait(&cond[floor_number], &mutex);
    }
    int num_passengers = 0;
    while(passenger_count[floor_number] > 0 && passengers_in_elevator < MAX_PASSENGERS && elevator_status == 1) {
        passenger_count[floor_number]--;
        passengers_in_elevator++;
        num_passengers++;
    }
    pthread_mutex_unlock(&mutex);
    printf("Elevator is at floor %d and loaded %d passengers from floor %d\n", current_floor + 1, num_passengers, floor_number + 1);
    sleep(1);
}

void unload_passengers(int floor_number) {
    pthread_mutex_lock(&mutex);
    int num_passengers = 0;
    while(passengers_in_elevator > 0 && current_floor == floor_number && elevator_status == 1) {
        passengers_in_elevator--;
        num_passengers++;
    }
    pthread_mutex_unlock(&mutex);
    printf("Elevator is at floor %d and unloaded %d passengers at floor %d\n", current_floor + 1, num_passengers, floor_number + 1);
    sleep(1);
}

void move_elevator() {
    if(elevator_status == 1) {
        if(current_floor == MAX_FLOOR - 1) {
            elevator_status = -1;
        } else {
            current_floor++;
        }
        printf("Elevator is moving up to floor %d\n", current_floor + 1);
    } else {
        if(current_floor == 0) {
            elevator_status = 1;
        } else {
            current_floor--;
        }
        printf("Elevator is moving down to floor %d\n", current_floor + 1);
    }
    sleep(1);
}

void *elevator_thread(void *arg) {
    while(1) {
        load_passengers(current_floor);
        unload_passengers(current_floor);
        move_elevator();
        for(int i=0;i<MAX_FLOOR;i++) {
            pthread_cond_broadcast(&cond[i]);
        }
    }
}

void *passenger_thread(void *arg) {
    int *floor_number = (int *) arg;
    pthread_mutex_lock(&mutex);
    passenger_count[*floor_number]++;
    pthread_cond_signal(&cond[*floor_number]);
    printf("Passenger arrives at floor %d to go up\n", *floor_number + 1);
    pthread_mutex_unlock(&mutex);
    sleep(1);
    pthread_mutex_lock(&mutex);
    while(current_floor != *floor_number || elevator_status == -1) {
        pthread_cond_wait(&cond[*floor_number], &mutex);
    }
    printf("Passenger in elevator going up from floor %d to floor %d\n", *floor_number + 1, current_floor + 1);
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t elevator;
    pthread_create(&elevator, NULL, elevator_thread, NULL);
    pthread_t passenger[MAX_FLOOR][MAX_PASSENGERS];
    for(int i=0;i<MAX_FLOOR;i++) {
        for(int j=0;j<MAX_PASSENGERS;j++) {
            int *arg = (int *) malloc(sizeof(*arg));
            *arg = i;
            pthread_create(&passenger[i][j], NULL, passenger_thread, arg);
        }
    }
    pthread_join(elevator, NULL);
    for(int i=0;i<MAX_FLOOR;i++) {
        for(int j=0;j<MAX_PASSENGERS;j++) {
            pthread_join(passenger[i][j], NULL);
        }
    }
    return 0;
}