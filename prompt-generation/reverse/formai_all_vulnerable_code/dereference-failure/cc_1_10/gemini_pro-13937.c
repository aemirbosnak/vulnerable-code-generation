//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Elevator data structure
typedef struct {
    int id;
    int current_floor;
    int requested_floors[10];
    int num_requested_floors;
    pthread_mutex_t lock;
    sem_t sem;
} Elevator;

// Global data
int num_elevators;
Elevator *elevators;
pthread_mutex_t floor_lock;
int requested_floors[10]; // Array of floors that have been requested by passengers
int num_requested_floors;

// Function to initialize the elevators
void init_elevators() {
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].id = i;
        elevators[i].current_floor = 0;
        elevators[i].num_requested_floors = 0;
        pthread_mutex_init(&elevators[i].lock, NULL);
        sem_init(&elevators[i].sem, 0, 0);
    }
}

// Function to add a floor request to an elevator
void add_floor_request(Elevator *elevator, int floor) {
    pthread_mutex_lock(&elevator->lock);
    elevator->requested_floors[elevator->num_requested_floors] = floor;
    elevator->num_requested_floors++;
    pthread_mutex_unlock(&elevator->lock);
}

// Function to simulate an elevator moving
void *elevator_thread(void *arg) {
    Elevator *elevator = (Elevator *)arg;

    while (1) {
        // Wait for a floor request
        sem_wait(&elevator->sem);

        // Get the next floor request
        int next_floor;
        pthread_mutex_lock(&elevator->lock);
        next_floor = elevator->requested_floors[0];
        for (int i = 0; i < elevator->num_requested_floors - 1; i++) {
            elevator->requested_floors[i] = elevator->requested_floors[i + 1];
        }
        elevator->num_requested_floors--;
        pthread_mutex_unlock(&elevator->lock);

        // Move the elevator to the next floor
        while (elevator->current_floor != next_floor) {
            if (elevator->current_floor < next_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            sleep(1); // Simulate the elevator moving
        }

        // Open the elevator doors
        printf("Elevator %d has arrived at floor %d\n", elevator->id, elevator->current_floor);
        sleep(1); // Simulate the elevator doors opening

        // Close the elevator doors
        printf("Elevator %d is leaving floor %d\n", elevator->id, elevator->current_floor);
        sleep(1); // Simulate the elevator doors closing
    }

    return NULL;
}

// Function to simulate a passenger requesting an elevator
void *passenger_thread(void *arg) {
    int floor = rand() % 10;
    int elevator_id = rand() % num_elevators;

    // Request the elevator
    pthread_mutex_lock(&floor_lock);
    requested_floors[floor]++;
    num_requested_floors++;
    pthread_mutex_unlock(&floor_lock);

    // Wait for the elevator to arrive
    add_floor_request(&elevators[elevator_id], floor);
    sem_post(&elevators[elevator_id].sem);

    return NULL;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of elevators
    printf("Enter the number of elevators: ");
    scanf("%d", &num_elevators);

    // Allocate memory for the elevators
    elevators = malloc(sizeof(Elevator) * num_elevators);

    // Initialize the elevators
    init_elevators();

    // Create the elevator threads
    pthread_t elevator_threads[num_elevators];
    for (int i = 0; i < num_elevators; i++) {
        pthread_create(&elevator_threads[i], NULL, elevator_thread, &elevators[i]);
    }

    // Create the passenger threads
    pthread_t passenger_threads[100];
    for (int i = 0; i < 100; i++) {
        pthread_create(&passenger_threads[i], NULL, passenger_thread, NULL);
    }

    // Join the elevator threads
    for (int i = 0; i < num_elevators; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    // Join the passenger threads
    for (int i = 0; i < 100; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    return 0;
}