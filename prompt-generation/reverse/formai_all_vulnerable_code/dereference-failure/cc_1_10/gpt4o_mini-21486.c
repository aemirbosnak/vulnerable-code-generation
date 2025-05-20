//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define TOTAL_FLOORS 5
#define ELEVATOR_CAPACITY 3

sem_t sem_request;
pthread_mutex_t lock;
int current_floor = 0;

typedef struct {
    int id;
    int from_floor;
    int to_floor;
} Person;

void* elevator_function(void* arg) {
    while (1) {
        sem_wait(&sem_request);
        
        pthread_mutex_lock(&lock);
        
        // Simulate the elevator movement
        printf("\nElevator is currently on floor %d...\n", current_floor);
        printf("Moving to requested floor...\n");
        sleep(1);
        
        // Randomly move to another floor
        current_floor = (current_floor + 1) % TOTAL_FLOORS;
        
        printf("Elevator arriving at floor %d!\n", current_floor);
        
        pthread_mutex_unlock(&lock);
    }
}

void request_elevator(Person *person) {
    printf("Person %d has requested the elevator from floor %d to floor %d...\n",
           person->id, person->from_floor, person->to_floor);
    
    sem_post(&sem_request);
}

int main() {
    pthread_t elevator_thread;
    sem_init(&sem_request, 0, 0);
    pthread_mutex_init(&lock, NULL);
    
    // Create elevator thread
    pthread_create(&elevator_thread, NULL, elevator_function, NULL);
    
    // Simulate people requesting the elevator
    for (int i = 0; i < 10; i++) {
        Person* person = malloc(sizeof(Person));
        person->id = i + 1;
        person->from_floor = rand() % TOTAL_FLOORS;
        person->to_floor = rand() % TOTAL_FLOORS;
        while (person->to_floor == person->from_floor) {
            person->to_floor = rand() % TOTAL_FLOORS; // Ensure destination is different
        }
        
        request_elevator(person);
        sleep(1); // Simulate time between requests
        free(person);
    }

    // Cleanup
    pthread_join(elevator_thread, NULL);
    sem_destroy(&sem_request);
    pthread_mutex_destroy(&lock);
    
    return 0;
}