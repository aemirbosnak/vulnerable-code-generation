//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers;
} Elevator;

typedef struct {
    int id;
    int requested_floor;
} Passenger;

Elevator elevator;
Passenger *passengers[MAX_CAPACITY];

sem_t elevator_sem; // Semaphore to manage the elevator's capacity
pthread_mutex_t elevator_mutex; // Mutex for critical section

void initialize_elevator() {
    elevator.current_floor = 1;
    elevator.passengers = 0;
}

void *passenger_thread(void *arg) {
    Passenger *p = (Passenger *)arg;

    // Simulating waiting for the elevator
    printf("Passenger %d is waiting on floor %d.\n", p->id, p->requested_floor);
    sleep(1);

    // Request the elevator
    pthread_mutex_lock(&elevator_mutex);
    
    if (elevator.passengers < MAX_CAPACITY) {
        elevator.passengers++;
        printf("Passenger %d enters the elevator on floor %d.\n", p->id, p->requested_floor);
    } else {
        printf("Passenger %d could not enter the elevator, it's full!\n", p->id);
        pthread_mutex_unlock(&elevator_mutex);
        pthread_exit(NULL);
    }
    pthread_mutex_unlock(&elevator_mutex);

    // Move to requested floor
    sleep(1);
    printf("Elevator moving from floor %d to floor %d.\n", elevator.current_floor, p->requested_floor);
    elevator.current_floor = p->requested_floor;
    printf("Elevator arrived at floor %d.\n", elevator.current_floor);

    // Simulating passenger leaving
    pthread_mutex_lock(&elevator_mutex);
    elevator.passengers--;
    printf("Passenger %d exits the elevator.\n", p->id);
    pthread_mutex_unlock(&elevator_mutex);
    
    pthread_exit(NULL);
}

void request_passenger(int id, int floor) {
    Passenger *p = malloc(sizeof(Passenger));
    p->id = id;
    p->requested_floor = floor;

    pthread_t passenger_thread_id;
    pthread_create(&passenger_thread_id, NULL, passenger_thread, (void *)p);
    pthread_detach(passenger_thread_id);
}

int main() {
    initialize_elevator();
    sem_init(&elevator_sem, 0, 1);
    pthread_mutex_init(&elevator_mutex, NULL);

    int i;
    for (i = 0; i < 15; i++) {
        // Simulate passengers requesting elevators
        int random_floor = rand() % MAX_FLOORS + 1; // Floors 1 to 10
        request_passenger(i + 1, random_floor);
        sleep(1);
    }

    sleep(10); // Let the simulation run for a while
    sem_destroy(&elevator_sem);
    pthread_mutex_destroy(&elevator_mutex);
    return 0;
}