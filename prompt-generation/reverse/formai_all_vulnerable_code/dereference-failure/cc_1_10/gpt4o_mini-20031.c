//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define FLOORS 5
#define CAPACITY 3

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
} Person;

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for idle
    Person *passengers[CAPACITY];
    int passenger_count;
    sem_t semaphore;
} Elevator;

Elevator elevator;

void *person_thread(void *arg) {
    Person *person = (Person *)arg;
    printf("Person %d is waiting at floor %d to go to floor %d\n", person->id, person->current_floor, person->destination_floor);
    
    sem_wait(&elevator.semaphore);
    
    if (elevator.passenger_count < CAPACITY) {
        elevator.passengers[elevator.passenger_count++] = person;

        printf("Person %d entered the elevator on floor %d\n", person->id, person->current_floor);
        
        sleep(1); // Simulate travel time
        printf("Elevator on floor %d: Passenger %d is going to floor %d\n", elevator.current_floor, person->id, person->destination_floor);
    
        sleep(1); // Simulate travel time
        printf("Person %d has exited the elevator at floor %d\n", person->id, person->destination_floor);
        
        elevator.passenger_count--;
    }
    
    sem_post(&elevator.semaphore);
    free(person);
    return NULL;
}

void *elevator_thread(void *arg) {
    while (1) {
        for (int floor = 1; floor <= FLOORS; ++floor) {
            elevator.current_floor = floor;
            printf("Elevator is on floor %d\n", floor);
            sleep(2);
        }

        for (int floor = FLOORS; floor >= 1; --floor) {
            elevator.current_floor = floor;
            printf("Elevator is on floor %d\n", floor);
            sleep(2);
        }
    }
    return NULL;
}

int main() {
    pthread_t elevator_tid;
    pthread_t person_tid[10];
    elevator.current_floor = 1;
    elevator.direction = 0;
    elevator.passenger_count = 0;

    sem_init(&elevator.semaphore, 0, 1);

    pthread_create(&elevator_tid, NULL, elevator_thread, NULL);

    for (int i = 0; i < 10; ++i) {
        Person *person = (Person *)malloc(sizeof(Person));
        person->id = i + 1;
        person->current_floor = rand() % FLOORS + 1;
        person->destination_floor = rand() % FLOORS + 1;
        
        pthread_create(&person_tid[i], NULL, person_thread, (void *)person);
        sleep(1); // Delay for next person generation
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(person_tid[i], NULL);
    }

    pthread_cancel(elevator_tid);
    sem_destroy(&elevator.semaphore);
    
    return 0;
}