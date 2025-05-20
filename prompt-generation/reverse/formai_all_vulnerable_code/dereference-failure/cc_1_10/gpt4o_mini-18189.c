//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_FLOORS 5
#define ELEVATOR_CAPACITY 4

typedef struct {
    int current_floor;
    int requested_floor;
    int passenger_count;
    int passengers[ELEVATOR_CAPACITY];
} Elevator;

sem_t sem_waiting[MAX_FLOORS];
pthread_mutex_t mutex;
int floor_requests[MAX_FLOORS] = {0};

void* elevator_function(void* arg) {
    Elevator* elevator = (Elevator*)arg;
    
    while (1) {
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (floor_requests[i] > 0) {
                elevator->requested_floor = i;
                floor_requests[i]--;
                printf("Elevator moving to floor %d.\n", elevator->requested_floor);
                elevator->current_floor = elevator->requested_floor;
                sleep(1);  // Simulate the time taken to travel between floors
                printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
                
                // Allow passenger exit and enter
                if (elevator->passenger_count > 0) {
                    printf("Passengers exiting from floor %d.\n", elevator->current_floor);
                }
                
                elevator->passenger_count = rand() % (ELEVATOR_CAPACITY + 1); // Randomize passenger entry
                printf("Passengers entering at floor %d: %d\n", elevator->current_floor, elevator->passenger_count);
                
                sleep(1); // Simulate boarding time
                break; // Break to start the movement to the next floor
            }
        }
    }
    
    return NULL;
}

void request_floor(int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        floor_requests[floor]++;
        printf("Requesting elevator to floor %d.\n", floor);
        sem_post(&sem_waiting[floor]);
    } else {
        printf("Invalid floor request!\n");
    }
}

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < MAX_FLOORS; i++) {
        sem_init(&sem_waiting[i], 0, 0);
    }
    
    Elevator elevator = {0, -1, 0, {0}};
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator_function, (void*)&elevator);
    
    char command[10];
    
    while (1) {
        printf("Enter the floor you'd like to go to (0-%d) or 'exit' to quit: ", MAX_FLOORS - 1);
        scanf("%s", command);
        
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        int requested_floor = atoi(command);
        request_floor(requested_floor);
    }
    
    pthread_cancel(elevator_thread);
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&mutex);
    
    for (int i = 0; i < MAX_FLOORS; i++) {
        sem_destroy(&sem_waiting[i]);
    }
    
    return 0;
}