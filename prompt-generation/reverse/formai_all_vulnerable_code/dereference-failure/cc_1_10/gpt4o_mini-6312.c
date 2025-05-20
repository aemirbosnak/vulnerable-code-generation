//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 3

typedef struct {
    int current_floor;
    int requested_floors[ELEVATOR_CAPACITY];
    int num_requests;
    sem_t sem;
} Elevator;

typedef struct {
    int id;
    int destination_floor;
} Passenger;

Elevator elevator;

void* elevator_run(void* arg) {
    while(1) {
        sem_wait(&elevator.sem);

        // Check if there are requests
        if (elevator.num_requests > 0) {
            for (int i = 0; i < elevator.num_requests; i++) {
                int requested_floor = elevator.requested_floors[i];

                // Move to the requested floor
                printf("Elevator moving from floor %d to floor %d...\n", elevator.current_floor, requested_floor);
                elevator.current_floor = requested_floor;
                sleep(2);  // Simulate the time taken to move between floors
                printf("Elevator arrived at floor %d.\n", elevator.current_floor);
            
                // Remove the fulfilled request
                elevator.requested_floors[i] = -1; 
            }
            elevator.num_requests = 0; // Reset the number of requests
        }
        // Let the elevator wait for some time before checking for new requests
        sleep(1);
    }
    return NULL;
}

void request_elevator(int floor, int passenger_id) {
    sem_post(&elevator.sem);

    if (elevator.num_requests < ELEVATOR_CAPACITY) {
        elevator.requested_floors[elevator.num_requests] = floor;
        elevator.num_requests++;
        printf("Passenger %d requested the elevator to floor %d.\n", passenger_id, floor);
    } else {
        printf("Elevator capacity reached. Passenger %d could not request floor %d.\n", passenger_id, floor);
    }
}

void* passenger_run(void* arg) {
    Passenger* passenger = (Passenger*)arg; 
    sleep(rand() % 5 + 1); // Random wait before requesting
    request_elevator(passenger->destination_floor, passenger->id);
    free(passenger); // Free allocated memory for passenger
    return NULL;
}

int main() {
    pthread_t elevator_thread;
    pthread_t passenger_threads[5];
    
    elevator.current_floor = 0;
    elevator.num_requests = 0;
    sem_init(&elevator.sem, 0, 1);

    // Start the elevator thread
    pthread_create(&elevator_thread, NULL, elevator_run, NULL);

    // Simulate passengers
    for (int i = 0; i < 5; i++) {
        Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
        passenger->id = i + 1;
        passenger->destination_floor = rand() % MAX_FLOORS;
        pthread_create(&passenger_threads[i], NULL, passenger_run, passenger);
    }

    // Wait for passenger threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    // Cleanup */
    sem_destroy(&elevator.sem);
    return 0;
}