//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int floor;
    int id;
} Passenger;

typedef struct {
    Passenger passengers[ELEVATOR_CAPACITY];
    int count;
    int currentFloor;
    pthread_mutex_t mutex;
    sem_t passengerSem;
} Elevator;

Elevator elevator;

void *passenger_thread(void *arg) {
    Passenger *pax = (Passenger *)arg;
    
    printf("Passenger %d waiting on floor %d\n", pax->id, pax->floor);
    sleep(rand() % 3 + 1); // Simulate waiting time

    printf("Passenger %d calls the elevator on floor %d\n", pax->id, pax->floor);
    sem_post(&elevator.passengerSem); // Signal elevator to pick up the passenger

    // Wait for the elevator to arrive
    pthread_mutex_lock(&elevator.mutex);
    while (elevator.currentFloor != pax->floor) {
        pthread_mutex_unlock(&elevator.mutex);
        usleep(500000); // Check every 0.5 seconds
        pthread_mutex_lock(&elevator.mutex);
    }
    printf("Passenger %d enters the elevator.\n", pax->id);
    elevator.passengers[elevator.count++] = *pax; // Add to elevator
    pthread_mutex_unlock(&elevator.mutex);

    sleep(rand() % 3 + 1); // Simulate time in elevator
    return NULL;
}

void *elevator_thread(void *arg) {
    while (1) {
        sem_wait(&elevator.passengerSem); // Wait for a passenger to call
        pthread_mutex_lock(&elevator.mutex);

        if (elevator.count > 0) {
            // For simplicity, just pick a random floor
            elevator.currentFloor = rand() % MAX_FLOORS;
            printf("Elevator is moving to floor %d.\n", elevator.currentFloor);
            sleep(2); // Simulate travel time

            // Drop off passengers
            for (int i = 0; i < elevator.count; i++) {
                if (elevator.passengers[i].floor == elevator.currentFloor) {
                    printf("Passenger %d exits on floor %d\n", elevator.passengers[i].id, elevator.currentFloor);
                }
            }
            elevator.count = 0; // Reset passenger count after dropping off
        }
        
        pthread_mutex_unlock(&elevator.mutex);
        sleep(1); // Rest before checking for new calls
    }
}

int main() {
    srand(time(NULL)); // Seed for random passenger generation
    pthread_t elevatorThread;
    pthread_t passengerThreads[20];
    
    elevator.count = 0;
    elevator.currentFloor = 0;
    pthread_mutex_init(&elevator.mutex, NULL);
    sem_init(&elevator.passengerSem, 0, 0);

    pthread_create(&elevatorThread, NULL, elevator_thread, NULL);
    
    for (int i = 0; i < 20; i++) {
        Passenger *newPassenger = malloc(sizeof(Passenger));
        newPassenger->floor = rand() % MAX_FLOORS;
        newPassenger->id = i + 1;
        pthread_create(&passengerThreads[i], NULL, passenger_thread, newPassenger);
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(passengerThreads[i], NULL);
    }

    // To simulate stopping the elevator, we can terminate the elevator thread (in a real program, more graceful shutdown would be used)
    pthread_cancel(elevatorThread);
    pthread_join(elevatorThread, NULL);
    
    pthread_mutex_destroy(&elevator.mutex);
    sem_destroy(&elevator.passengerSem);

    return 0;
}