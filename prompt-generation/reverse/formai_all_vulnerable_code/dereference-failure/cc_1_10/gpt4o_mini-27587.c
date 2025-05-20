//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define FLOORS 10
#define ELEVATOR_CAPACITY 3

typedef struct {
    int currentFloor;
    int destinationFloor;
    int passengerCount;
} Elevator;

Elevator elevator;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *passenger(void *arg) {
    int passengerID = *((int *) arg);
    int destinationFloor = rand() % FLOORS;

    printf("Passenger %d wants to go to floor %d.\n", passengerID, destinationFloor);
    free(arg);

    pthread_mutex_lock(&lock);

    while (elevator.passengerCount >= ELEVATOR_CAPACITY) {
        printf("Passenger %d is waiting for the elevator.\n", passengerID);
        pthread_cond_wait(&cond, &lock);
    }

    elevator.passengerCount++;
    printf("Passenger %d entered the elevator. Current count: %d\n", passengerID, elevator.passengerCount);

    pthread_mutex_unlock(&lock);

    sleep(2); // Simulate the time for the ride
    pthread_mutex_lock(&lock);
    
    printf("Passenger %d is exiting the elevator at floor %d.\n", passengerID, destinationFloor);
    elevator.passengerCount--;

    if (elevator.passengerCount < ELEVATOR_CAPACITY) {
        pthread_cond_broadcast(&cond);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void *elevator_controller(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (elevator.passengerCount == 0) {
            printf("Elevator is idle at floor %d.\n", elevator.currentFloor);
        } else {
            printf("Elevator is moving from floor %d to floor %d, picking up passengers.\n",
                   elevator.currentFloor, elevator.destinationFloor);
            sleep(1); // Simulate travel time
            elevator.currentFloor = elevator.destinationFloor;
            printf("Elevator has arrived at floor %d.\n", elevator.currentFloor);
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void start_simulation(int passengerCount) {
    pthread_t threads[passengerCount];
    pthread_t elevatorThread;

    elevator.currentFloor = 0;
    elevator.passengerCount = 0;

    pthread_create(&elevatorThread, NULL, elevator_controller, NULL);

    for (int i = 0; i < passengerCount; ++i) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, passenger, id);
        sleep(1); // new passenger arrives every second
    }

    for (int i = 0; i < passengerCount; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Let the elevator finish processing
    sleep(1);
    pthread_cancel(elevatorThread);
    pthread_join(elevatorThread, NULL);
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Elevation of Mystery!\n");
    start_simulation(10);
    printf("All passengers have reached their destinations. The mystery is complete!\n");
    return 0;
}