//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int target_floor;
    int passengers[MAX_CAPACITY];
    int passenger_count;
} Elevator;

Elevator elevator;
sem_t sem;

void* elevator_function(void* arg) {
    while (true) {
        sem_wait(&sem);
        
        if (elevator.passenger_count == 0) {
            printf("Elevator is idle on floor %d.\n", elevator.current_floor);
            sleep(1);
        } else {
            if (elevator.target_floor > elevator.current_floor) {
                elevator.current_floor++;
            } else {
                elevator.current_floor--;
            }

            printf("Elevator moving to floor %d...\n", elevator.current_floor);
            sleep(1);

            if (elevator.current_floor == elevator.target_floor) {
                printf("Elevator arrived at floor %d.\n", elevator.current_floor);
                
                // Unload passengers
                for(int i = 0; i < elevator.passenger_count; i++) {
                    printf("Passenger %d exited the elevator on floor %d.\n", elevator.passengers[i], elevator.current_floor);
                }
                elevator.passenger_count = 0;
            }
        }
        
        sem_post(&sem);
    }
    return NULL;
}

void call_elevator(int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor!\n");
        return;
    }

    sem_wait(&sem);
    elevator.target_floor = floor;
    sem_post(&sem);
    printf("Elevator called to floor %d.\n", floor);
}

void load_passenger(int passenger_id) {
    sem_wait(&sem);
    if (elevator.passenger_count < MAX_CAPACITY) {
        elevator.passengers[elevator.passenger_count] = passenger_id;
        elevator.passenger_count++;
        printf("Passenger %d entered the elevator.\n", passenger_id);
    } else {
        printf("Elevator is full! Passenger %d cannot enter.\n", passenger_id);
    }
    sem_post(&sem);
}

void unload_passenger(int passenger_id) {
    sem_wait(&sem);
    int found = false;
    for (int i = 0; i < elevator.passenger_count; i++) {
        if (elevator.passengers[i] == passenger_id) {
            found = true;
            elevator.passengers[i] = elevator.passengers[elevator.passenger_count - 1];
            elevator.passenger_count--;
            printf("Passenger %d exited the elevator.\n", passenger_id);
            break;
        }
    }
    if (!found) {
        printf("Passenger %d is not in the elevator!\n", passenger_id);
    }
    sem_post(&sem);
}

void* passenger_function(void* arg) {
    int passenger_id = *((int*)arg);
    free(arg);
    // Call elevator to a random floor
    int floor = rand() % MAX_FLOORS;
    call_elevator(floor);

    // Load the passenger into the elevator
    load_passenger(passenger_id);
    
    // Simulate random waiting and unloading
    sleep(rand() % 5);
    unload_passenger(passenger_id);
    return NULL;
}

int main() {
    elevator.current_floor = 0;
    elevator.target_floor = 0;
    elevator.passenger_count = 0;
    sem_init(&sem, 0, 1);
    
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);

    int num_passengers = 10;
    pthread_t passenger_threads[num_passengers];
    
    for (int i = 0; i < num_passengers; i++) {
        int* passenger_id = malloc(sizeof(int));
        *passenger_id = i + 1; // Passengers are 1 indexed
        pthread_create(&passenger_threads[i], NULL, passenger_function, passenger_id);
    }

    // Wait for all passenger threads to finish
    for (int i = 0; i < num_passengers; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    // Clean up and exit
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    sem_destroy(&sem);
    return 0;
}