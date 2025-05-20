//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: artistic
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
    int direction; // 1 for up, -1 for down
    int passengers[MAX_CAPACITY];
    int passenger_count;
    pthread_mutex_t lock;
} Elevator;

typedef struct {
    int id;
    int desired_floor;
} Person;

Elevator elevator;
sem_t sem;

void* elevator_function(void* arg) {
    while (1) {
        sem_wait(&sem); // Wait for a signal to operate

        pthread_mutex_lock(&elevator.lock);
        if (elevator.passenger_count > 0) {
            while (elevator.passenger_count > 0) {
                printf("Elevator at floor %d, carrying %d passengers...\n",
                       elevator.current_floor, elevator.passenger_count);
                for (int i = 0; i < elevator.passenger_count; i++) {
                    if (elevator.passengers[i] == elevator.current_floor) {
                        printf("   Passenger %d getting off at floor %d.\n",
                               i + 1, elevator.current_floor);
                        elevator.passenger_count--;
                        // Shift passengers to fill the emptied spot
                        for (int j = i; j < elevator.passenger_count; j++) {
                            elevator.passengers[j] = elevator.passengers[j + 1];
                        }
                        i--; // Adjust index after removal
                    }
                }
                
                if (elevator.passenger_count > 0) {
                    elevator.current_floor += elevator.direction;
                    if (elevator.current_floor >= MAX_FLOORS) {
                        elevator.current_floor = MAX_FLOORS - 1;
                        elevator.direction = -1; // Go down
                    } else if (elevator.current_floor < 0) {
                        elevator.current_floor = 0;
                        elevator.direction = 1; // Go up
                    }
                    sleep(1); // Simulate time taken to move to next floor
                }
            }
        }
        pthread_mutex_unlock(&elevator.lock);
    }
    return NULL;
}

void* person_function(void* arg) {
    Person* person = (Person*)arg;

    printf("Person %d waiting to go to floor %d...\n", person->id, person->desired_floor);
    sleep(rand() % 3 + 1); // Random wait time before entering elevator

    pthread_mutex_lock(&elevator.lock);
    if (elevator.passenger_count < MAX_CAPACITY) {
        elevator.passengers[elevator.passenger_count++] = person->desired_floor;
        printf("   Person %d entered the elevator.\n", person->id);
        sem_post(&sem); // Signal elevator to operate
    } else {
        printf("   Person %d could not enter. Elevator full!\n", person->id);
    }
    pthread_mutex_unlock(&elevator.lock);
    free(person);
    return NULL;
}

int main() {
    srand(time(NULL));
    elevator.current_floor = 0;
    elevator.direction = 1; // Start going up
    elevator.passenger_count = 0;
    pthread_mutex_init(&elevator.lock, NULL);
    sem_init(&sem, 0, 0);

    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);

    for (int i = 0; i < 20; i++) {
        Person* person = malloc(sizeof(Person));
        person->id = i + 1;
        person->desired_floor = rand() % MAX_FLOORS; // Random floor from 0 to MAX_FLOORS - 1
        pthread_t person_thread;
        pthread_create(&person_thread, NULL, person_function, person);
        pthread_detach(person_thread); // No need to join the thread
    }

    // Let the simulation run for a while
    sleep(30);
    
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&elevator.lock);
    sem_destroy(&sem);

    printf("Elevator simulation has ended. All tasks complete.\n");
    return 0;
}