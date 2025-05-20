//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// Elevator struct
typedef struct {
    int cur_floor;  // Current floor the elevator is on
    int dest_floor; // Destination floor the elevator is going to
    int num_passengers;  // Number of passengers currently in the elevator
    pthread_mutex_t mutex;  // Mutex lock to protect the elevator struct
    pthread_cond_t cond;  // Conditional variable to wait for the elevator
} elevator;

// Passenger struct
typedef struct {
    int start_floor;  // Floor the passenger wants to start from
    int dest_floor;  // Floor the passenger wants to go to
    pthread_mutex_t mutex;  // Mutex lock to protect the passenger struct
    pthread_cond_t cond;  // Conditional variable to wait for the passenger
} passenger;

// Global variables
elevator elev;  // Elevator object
passenger *passengers;  // Array of passenger objects
int num_floors;  // Number of floors in the building
int num_passengers;  // Number of passengers in the building

// Initialize the elevator
void elevator_init(elevator *e, int num_floors) {
    e->cur_floor = 0;
    e->dest_floor = -1;
    e->num_passengers = 0;
    pthread_mutex_init(&e->mutex, NULL);
    pthread_cond_init(&e->cond, NULL);
}

// Initialize a passenger
void passenger_init(passenger *p, int start_floor, int dest_floor) {
    p->start_floor = start_floor;
    p->dest_floor = dest_floor;
    pthread_mutex_init(&p->mutex, NULL);
    pthread_cond_init(&p->cond, NULL);
}

// Elevator thread function
void *elevator_thread(void *arg) {
    elevator *e = (elevator *)arg;

    while (1) {
        // Wait for a passenger to request the elevator
        pthread_mutex_lock(&e->mutex);
        while (e->num_passengers == 0 && e->dest_floor == -1) {
            pthread_cond_wait(&e->cond, &e->mutex);
        }
        pthread_mutex_unlock(&e->mutex);

        // Get the destination floor from the passenger
        int dest_floor;
        pthread_mutex_lock(&e->mutex);
        dest_floor = e->dest_floor;
        e->dest_floor = -1;
        pthread_mutex_unlock(&e->mutex);

        // Move the elevator to the destination floor
        while (e->cur_floor != dest_floor) {
            if (e->cur_floor < dest_floor) {
                e->cur_floor++;
            } else {
                e->cur_floor--;
            }
            sleep(1);
        }

        // Open the elevator doors and let the passenger out
        pthread_mutex_lock(&e->mutex);
        e->num_passengers--;
        pthread_cond_signal(&e->cond);
        pthread_mutex_unlock(&e->mutex);
    }

    return NULL;
}

// Passenger thread function
void *passenger_thread(void *arg) {
    passenger *p = (passenger *)arg;

    // Wait for the elevator to arrive at the passenger's floor
    pthread_mutex_lock(&p->mutex);
    while (elev.cur_floor != p->start_floor) {
        pthread_cond_wait(&p->cond, &p->mutex);
    }
    pthread_mutex_unlock(&p->mutex);

    // Get in the elevator
    pthread_mutex_lock(&elev.mutex);
    elev.num_passengers++;
    elev.dest_floor = p->dest_floor;
    pthread_cond_signal(&elev.cond);
    pthread_mutex_unlock(&elev.mutex);

    // Wait for the elevator to arrive at the passenger's destination floor
    pthread_mutex_lock(&p->mutex);
    while (elev.cur_floor != p->dest_floor) {
        pthread_cond_wait(&p->cond, &p->mutex);
    }
    pthread_mutex_unlock(&p->mutex);

    // Get out of the elevator
    pthread_mutex_lock(&elev.mutex);
    elev.num_passengers--;
    pthread_cond_signal(&elev.cond);
    pthread_mutex_unlock(&elev.mutex);

    return NULL;
}

// Main function
int main() {
    // Initialize the elevator and passengers
    num_floors = 10;
    num_passengers = 10;
    elevator_init(&elev, num_floors);
    passengers = malloc(sizeof(passenger) * num_passengers);
    for (int i = 0; i < num_passengers; i++) {
        passenger_init(&passengers[i], rand() % num_floors, rand() % num_floors);
    }

    // Create the elevator and passenger threads
    pthread_t elevator_tid;
    pthread_create(&elevator_tid, NULL, elevator_thread, &elev);
    pthread_t passenger_tids[num_passengers];
    for (int i = 0; i < num_passengers; i++) {
        pthread_create(&passenger_tids[i], NULL, passenger_thread, &passengers[i]);
    }

    // Join the elevator and passenger threads
    pthread_join(elevator_tid, NULL);
    for (int i = 0; i < num_passengers; i++) {
        pthread_join(passenger_tids[i], NULL);
    }

    // Free the allocated memory
    free(passengers);

    return 0;
}