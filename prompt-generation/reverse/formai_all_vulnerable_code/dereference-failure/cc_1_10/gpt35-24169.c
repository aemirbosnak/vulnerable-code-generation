//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define FLOOR_COUNT 10 // number of floors in the building
#define ELEVATOR_CAPACITY 10 // maximum number of people allowed inside the elevator

sem_t mutex; // semaphore for locking the elevator
sem_t floors[FLOOR_COUNT]; // semaphore for each floor

int current_floor = 0; // current position of the elevator
int direction = 1; // 1 for up, -1 for down
int people_inside = 0; // number of people inside the elevator
int people_waiting[FLOOR_COUNT] = {0}; // number of people waiting on each floor

void *elevator(void *arg) {
    while(1) {
        sem_wait(&mutex); // lock the elevator
        
        // check if there are any people inside the elevator
        if (people_inside > 0) {
            current_floor += direction; // move the elevator
            
            // check if the elevator has reached the top or bottom floor
            if (current_floor == FLOOR_COUNT - 1 || current_floor == 0) {
                direction *= -1; // change direction
            }
            
            // let people out of the elevator if they have arrived at their destination floor
            for (int i = 0; i < people_inside; i++) {
                if (current_floor == ((int*)arg)[i]) {
                    printf("Person %d gets off the elevator at floor %d\n", i+1, current_floor);
                    people_inside--;
                }
            }
        }
        
        // let people into the elevator
        while (people_waiting[current_floor] > 0 && people_inside < ELEVATOR_CAPACITY) {
            printf("Person %d gets on the elevator at floor %d\n", people_inside+1, current_floor);
            people_waiting[current_floor]--;
            people_inside++;
        }
        
        sem_post(&mutex); // unlock the elevator
    }
}

void *person(void *arg) {
    int *destination = (int*)arg;
    sem_wait(&floors[current_floor]); // lock the floor
    
    printf("Person arrives at floor %d, going to floor %d\n", current_floor, *destination);
    people_waiting[current_floor]++;
    
    sem_post(&floors[current_floor]); // unlock the floor
    
    while (current_floor != *destination) {
        // wait for the elevator to arrive at this floor
        if (current_floor < *destination) {
            sem_wait(&floors[current_floor+1]);
        } else {
            sem_wait(&floors[current_floor-1]);
        }
    }
    
    sem_wait(&mutex); // lock the elevator
    sem_post(&floors[current_floor]); // unlock the floor
    
    printf("Person %d gets on the elevator at floor %d\n", people_inside+1, current_floor);
    people_inside++;
    
    sem_post(&mutex); // unlock the elevator
    
    while (current_floor != *destination) {
        // wait for the elevator to reach the destination floor
    }
    
    sem_wait(&mutex); // lock the elevator
    
    printf("Person %d gets off the elevator at floor %d\n", people_inside, current_floor);
    people_inside--;
    
    sem_post(&mutex); // unlock the elevator
}

int main() {
    sem_init(&mutex, 0, 1); // initialize semaphore
    
    for (int i = 0; i < FLOOR_COUNT; i++) {
        sem_init(&floors[i], 0, 1); // initialize semaphore for each floor
    }
    
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator, NULL); // create the elevator thread
    
    srand(time(NULL));
    
    while(1) {
        int arrival_floor = rand() % FLOOR_COUNT;
        int destination_floor = rand() % FLOOR_COUNT;
        
        if (arrival_floor != destination_floor) {
            int *arg = malloc(sizeof(int));
            *arg = destination_floor;
            
            pthread_t person_thread;
            pthread_create(&person_thread, NULL, person, arg); // create the person thread
        }
        
        sleep(2); // wait between arrivals
    }
    
    return 0;
}