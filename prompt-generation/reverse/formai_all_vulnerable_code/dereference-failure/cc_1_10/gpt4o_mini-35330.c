//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_FLOORS 5
#define MAX_PASSENGERS 10

typedef struct {
    int current_floor;
    int destination_floor;
    bool is_moving;
} Elevator;

typedef struct {
    int id;
    int floor;
    int destination;
} Passenger;

Elevator elevator;
Passenger *passengers[MAX_PASSENGERS];
int passenger_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *passenger_routine(void *arg) {
    Passenger *passenger = (Passenger *)arg;

    pthread_mutex_lock(&mutex);
    if (passenger_count < MAX_PASSENGERS) {
        passengers[passenger_count++] = passenger;
        printf("Passenger %d calling elevator from floor %d to %d.\n", 
               passenger->id, passenger->floor, passenger->destination);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void move_elevator() {
    while (true) {
        pthread_mutex_lock(&mutex);
        
        if (passenger_count > 0) {
            for (int i = 0; i < passenger_count; i++) {
                if (elevator.current_floor != passengers[i]->floor) {
                    elevator.is_moving = true;
                    elevator.current_floor += (elevator.current_floor < passengers[i]->floor) ? 1 : -1;
                    printf("Elevator moving to floor %d...\n", elevator.current_floor);
                    sleep(1); // Simulate time taken to move to the next floor
                }
                else {
                    elevator.is_moving = false;
                    printf("Elevator arrived at floor %d for Passenger %d.\n", elevator.current_floor, passengers[i]->id);
                    elevator.destination_floor = passengers[i]->destination;
                    printf("Passenger %d entering the elevator...\n", passengers[i]->id);
                    // Remove passenger from list after they've entered
                    for (int j = i; j < passenger_count - 1; j++) {
                        passengers[j] = passengers[j + 1];
                    }
                    passenger_count--;
                    i--; // adjust index since we removed an element
                }
            }
            
            if (elevator.destination_floor != elevator.current_floor) {
                elevator.is_moving = true;
                elevator.current_floor += (elevator.current_floor < elevator.destination_floor) ? 1 : -1;
                printf("Elevator moving to floor %d...\n", elevator.current_floor);
                sleep(1);
            }
            else {
                elevator.is_moving = false;
                printf("Elevator arrived at destination floor %d.\n", elevator.current_floor);
                elevator.destination_floor = elevator.current_floor; // Reset destination when arrived
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate time when elevator is idle
    }
}

int main() {
    pthread_t elevator_thread;

    elevator.current_floor = 0;
    elevator.destination_floor = 0;
    elevator.is_moving = false;

    // Create the elevator thread
    pthread_create(&elevator_thread, NULL, (void *)move_elevator, NULL);

    // Simulating passengers calling the elevator
    for (int i = 0; i < 10; i++) {
        Passenger *new_passenger = (Passenger *)malloc(sizeof(Passenger));
        new_passenger->id = i;
        new_passenger->floor = rand() % MAX_FLOORS;
        new_passenger->destination = rand() % MAX_FLOORS;
        pthread_t passenger_thread;
        pthread_create(&passenger_thread, NULL, passenger_routine, (void *)new_passenger);
        pthread_detach(passenger_thread); // No need to join
        sleep(2); // Wait a bit before new passenger calls
    }

    pthread_join(elevator_thread, NULL); // Wait for the elevator thread to finish
    return 0;
}