//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define CAPACITY 7      // Capacity of the elevator

pthread_mutex_t lock;   // Mutex lock for thread safety

int floor_number = 1;   // Starting floor
int direction = 1;      // 1 for up, -1 for down
int in_elevator = 0;    // Number of people inside the elevator
int people_waiting[10]; // Array to track people waiting on each floor

void display_status() {
    printf("\nFloor: %d\tDirection: %s\tIn Elevator: %d\nPeople Waiting: ",
            floor_number, direction == 1 ? "Up" : "Down", in_elevator);

    for (int i = 1; i <= 10; i++) {
        printf("%d ", people_waiting[i]);
    }
}

void* passenger(void* arg) {
    int* floor = (int*) arg;
    printf("\n\nPassenger waiting on floor %d\n", *floor);
    people_waiting[*floor]++;   // Add passenger to waiting list

    while (floor_number != *floor) {
        /* Wait for elevator */
    }

    pthread_mutex_lock(&lock);
    while (in_elevator == CAPACITY || direction != (*floor > floor_number ? 1 : -1)) {
        /* Wait for elevator in correct direction, stopping if capacity is reached */
    }

    printf("\nPassenger on floor %d gets in elevator going %s", *floor, direction == 1 ? "up" : "down");
    people_waiting[*floor]--;   // Remove passenger from waiting list
    in_elevator++;              // Increase number of passengers in elevator

    pthread_mutex_unlock(&lock);
    while (floor_number != *floor) {
        /* Wait for elevator to reach passenger's destination floor */
    }

    pthread_mutex_lock(&lock);
    printf("\nPassenger on floor %d gets out of elevator on floor %d", *floor, floor_number);
    in_elevator--;  // Decrease number of passengers in elevator
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void* elevator() {
    while (1) {
        pthread_mutex_lock(&lock);

        if (in_elevator == 0) {     // If there are no passengers in the elevator
            if (people_waiting[floor_number] > 0) {
                printf("\nElevator doors open on floor %d for %d passengers", floor_number, people_waiting[floor_number]);
                in_elevator = people_waiting[floor_number];
                people_waiting[floor_number] = 0;
            } else {
                direction = direction == 1 ? -1 : 1;  // Change direction when elevator is empty
            }
        } else {
            if (floor_number == 1 || floor_number == 10) {   // If at bottom or top floor, change direction
                direction = direction == 1 ? -1 : 1;
            } else {
                int passengers_leaving = 0;
                for (int i = 0; i < in_elevator; i++) {
                    if (rand() % 2 == 0) {  // Randomly decide if passenger will leave on this floor
                        passengers_leaving++;
                    }
                }

                if (passengers_leaving > 0) {
                    in_elevator -= passengers_leaving;
                    printf("\nElevator doors open on floor %d. %d passenger(s) get off", floor_number, passengers_leaving);
                }
            }
        }

        floor_number += direction;  // Move the elevator

        display_status();
        pthread_mutex_unlock(&lock);

        sleep(2);   // Wait 2 seconds until next iteration
    }
}

int main() {
    srand(time(NULL));     // Seed random number generator

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, &elevator, NULL);

    int num_passengers = 50;
    pthread_t passenger_threads[num_passengers];

    for (int i = 0; i < num_passengers; i++) {
        int* floor = (int*) malloc(sizeof(int));
        *floor = rand() % 10 + 1;   // Generate random floor for passenger
        pthread_create(&passenger_threads[i], NULL, &passenger, floor);
    }

    for (int i = 0; i < num_passengers; i++) {
        pthread_join(passenger_threads[i], NULL);
    }

    pthread_cancel(elevator_thread);
    pthread_mutex_destroy(&lock);

    return 0;
}