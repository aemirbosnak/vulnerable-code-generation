//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define NUM_ELEVATORS 2

typedef struct {
    int current_floor;
    int request_floor;
    pthread_cond_t cond;
    pthread_mutex_t mutex;
} Elevator;

Elevator elevators[NUM_ELEVATORS];

void* elevator_function(void* arg) {
    Elevator* elevator = (Elevator*)arg;

    while (1) {
        pthread_mutex_lock(&elevator->mutex);
        
        while (elevator->request_floor == -1) {
            pthread_cond_wait(&elevator->cond, &elevator->mutex);
        }
        
        int target_floor = elevator->request_floor;
        elevator->request_floor = -1;

        pthread_mutex_unlock(&elevator->mutex);

        // Simulate moving to the requested floor
        printf("Elevator at Floor %d moving to Floor %d\n", elevator->current_floor, target_floor);
        
        while (elevator->current_floor != target_floor) {
            if (elevator->current_floor < target_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }
            printf("Elevator is now at Floor %d\n", elevator->current_floor);
            sleep(1); // Simulate travel time
        }

        printf("Elevator arrived at Floor %d\n", elevator->current_floor);
    }
    return NULL;
}

void request_elevator(int floor) {
    static int elevator_index = 0;
    Elevator* elevator = &elevators[elevator_index];

    pthread_mutex_lock(&elevator->mutex);
    elevator->request_floor = floor;
    pthread_cond_signal(&elevator->cond);
    elevator_index = (elevator_index + 1) % NUM_ELEVATORS;
    pthread_mutex_unlock(&elevator->mutex);
}

void initialize_elevators() {
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].request_floor = -1;
        pthread_cond_init(&elevators[i].cond, NULL);
        pthread_mutex_init(&elevators[i].mutex, NULL);
        pthread_create(NULL, NULL, elevator_function, (void*)&elevators[i]);
    }
}

int main() {
    initialize_elevators();

    int floor_request;
    while (1) {
        printf("Enter floor request (0-%d) or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &floor_request);

        if (floor_request == -1) {
            break;
        }

        if (floor_request < 0 || floor_request >= MAX_FLOORS) {
            printf("Invalid floor. Please enter a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        request_elevator(floor_request);
    }

    printf("Exiting elevator simulation.\n");
    return 0;
}