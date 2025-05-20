//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int target_floor;
    int passengers;
} Elevator;

typedef struct {
    int id;
    int destination_floor;
} Passenger;

Elevator elevator;
Passenger passengers[ELEVATOR_CAPACITY];
sem_t passenger_sem;
pthread_mutex_t elevator_mutex;

void* elevator_function(void* arg);
void* passenger_function(void* arg);
void request_pickup(int passenger_id);
void board_passenger(int passenger_id);
void move_elevator(int target_floor);
void unload_passengers();
void display_elevator_status();

int main() {
    srand(time(NULL));
    
    // Initialize elevator
    elevator.current_floor = 0;
    elevator.target_floor = -1;
    elevator.passengers = 0;

    pthread_mutex_init(&elevator_mutex, NULL);
    sem_init(&passenger_sem, 0, 0);

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);

    // Create passengers
    for (int i = 0; i < 15; i++) {
        Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
        passenger->id = i;
        passenger->destination_floor = rand() % MAX_FLOORS;

        pthread_t passenger_thread;
        pthread_create(&passenger_thread, NULL, passenger_function, (void*)passenger);
        pthread_detach(passenger_thread);
    }

    pthread_join(elevator_thread, NULL);
    sem_destroy(&passenger_sem);
    pthread_mutex_destroy(&elevator_mutex);
    
    return 0;
}

void* elevator_function(void* arg) {
    while (1) {
        sem_wait(&passenger_sem);
        pthread_mutex_lock(&elevator_mutex);
        
        if (elevator.target_floor != -1) {
            move_elevator(elevator.target_floor);
            unload_passengers();
        } else {
            printf("Elevator is idle at floor %d.\n", elevator.current_floor);
        }

        pthread_mutex_unlock(&elevator_mutex);
        sleep(1);
    }
    return NULL;
}

void* passenger_function(void* arg) {
    Passenger* passenger = (Passenger*)arg;
    int wait_time = rand() % 5 + 1;
    sleep(wait_time); // Simulates delay before requesting the elevator
    printf("Passenger %d is requesting a ride to floor %d.\n", passenger->id, passenger->destination_floor);
    request_pickup(passenger->id);
    free(passenger);
    return NULL;
}

void request_pickup(int passenger_id) {
    pthread_mutex_lock(&elevator_mutex);
    
    if (elevator.passengers < ELEVATOR_CAPACITY) {
        printf("Passenger %d boarded the elevator.\n", passenger_id);
        elevator.passengers++;
        // Assume elevator goes directly to this passenger's destination for simplicity
        elevator.target_floor = elevator.current_floor;
        
        printf("Elevator now going to pick up more passengers.\n");
        sem_post(&passenger_sem);
    } else {
        printf("Elevator is full! Passenger %d cannot board.\n", passenger_id);
    }
    
    pthread_mutex_unlock(&elevator_mutex);
}

void move_elevator(int target_floor) {
    while (elevator.current_floor != target_floor) {
        printf("Elevator moving from floor %d to floor %d...\n", elevator.current_floor, target_floor);
        elevator.current_floor += (target_floor > elevator.current_floor) ? 1 : -1;
        sleep(1);
    }
    printf("Elevator has arrived at floor %d.\n", elevator.current_floor);
    elevator.target_floor = -1; // Clear target after moving
}

void unload_passengers() {
    printf("Unloading passengers at floor %d.\n", elevator.current_floor);
    elevator.passengers = 0; // All passengers exit for simplicity
    display_elevator_status();
}

void display_elevator_status() {
    printf("Elevator status: Currently at floor %d with %d passengers.\n",
           elevator.current_floor, elevator.passengers);
}