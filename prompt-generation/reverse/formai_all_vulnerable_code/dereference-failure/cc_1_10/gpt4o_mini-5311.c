//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define NUM_PASSENGERS 5

typedef struct {
    int current_floor;
    int requested_floor;
} Passenger;

typedef struct {
    int current_floor;
    sem_t sem;
    Passenger passengers[NUM_PASSENGERS];
    int num_passengers;
} Elevator;

void* elevator_thread(void* arg);
void* passenger_thread(void* arg);
void simulate_passenger(Passenger* passenger, Elevator* elevator);
void print_elevator_status(Elevator* elevator);

int main() {
    pthread_t elevatorThread;
    pthread_t passengerThreads[NUM_PASSENGERS];
    Elevator elevator = {0, 0, {{0, 0}}, 0};

    sem_init(&elevator.sem, 0, 1);

    // Create elevator thread
    pthread_create(&elevatorThread, NULL, elevator_thread, &elevator);
    
    // Create passenger threads
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
        passenger->current_floor = rand() % MAX_FLOORS;
        passenger->requested_floor = rand() % MAX_FLOORS;

        pthread_create(&passengerThreads[i], NULL, passenger_thread, (void*)passenger);
    }

    // Join passenger threads
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        pthread_join(passengerThreads[i], NULL);
    }

    // Clean up
    pthread_cancel(elevatorThread);
    pthread_join(elevatorThread, NULL);
    sem_destroy(&elevator.sem);

    return 0;
}

void* elevator_thread(void* arg) {
    Elevator* elevator = (Elevator*)arg;
    while (1) {
        sem_wait(&elevator->sem);
        
        // Print elevator status
        print_elevator_status(elevator);

        for (int i = 0; i < elevator->num_passengers; i++) {
            Passenger passenger = elevator->passengers[i];
            if (elevator->current_floor == passenger.requested_floor) {
                printf("Passenger at floor %d is getting off.\n", passenger.requested_floor);
                elevator->num_passengers--;
                for (int j = i; j < elevator->num_passengers; j++) {
                    elevator->passengers[j] = elevator->passengers[j + 1];
                }
                i--; // Adjust index after removing passenger
            }
        }

        // If there are no passengers, wait
        if (elevator->num_passengers == 0) {
            sleep(1);
            sem_post(&elevator->sem);
            continue;
        }

        // Move to next floor
        elevator->current_floor = (elevator->current_floor + 1) % MAX_FLOORS;
        printf("Elevator moving to floor %d.\n", elevator->current_floor);
        sleep(1);
        sem_post(&elevator->sem);
    }
    
    return NULL;
}

void* passenger_thread(void* arg) {
    Passenger* passenger = (Passenger*)arg;
    Elevator elevator;
    
    sleep(rand() % 3); // Simulating waiting time for the elevator

    simulate_passenger(passenger, &elevator);

    free(passenger);
    return NULL;
}

void simulate_passenger(Passenger* passenger, Elevator* elevator) {
    sem_wait(&elevator->sem);

    elevator->passengers[elevator->num_passengers] = *passenger;
    elevator->num_passengers++;
  
    printf("Passenger requests elevator from floor %d to floor %d.\n",
        passenger->current_floor, passenger->requested_floor);

    sem_post(&elevator->sem);
}

void print_elevator_status(Elevator* elevator) {
    printf("Elevator status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Number of Passengers: %d\n", elevator->num_passengers);
    for (int i = 0; i < elevator->num_passengers; i++) {
        printf("Passenger %d: from %d to %d\n", i + 1, elevator->passengers[i].current_floor, elevator->passengers[i].requested_floor);
    }
    printf("\n");
}