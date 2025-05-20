//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define NO_OF_FLOORS 10              // Define number of floors
#define MAX_PASSENGERS 10           // Define maximum number of passengers in elevator
#define ELEVATOR_CAPACITY 5         // Define capacity of elevator
#define WAIT_TIME 1                 // Define wait time between floors

int current_floor = 0;              // Initialize current floor to 0
bool direction_up = true;           // Initialize direction as up
bool doors_open = false;            // Initialize doors as closed

int passengers_waiting[NO_OF_FLOORS] = {0};    // Initialize passengers waiting at each floor
int passengers_in_elevator[ELEVATOR_CAPACITY] = {0};    // Initialize passengers in elevator
int no_of_passengers_in_elevator = 0;            // Initialize number of passengers in elevator

pthread_mutex_t elevator_mutex;     // Initialize mutex for elevator access

// Function to move elevator up
void move_up() {
    printf("Elevator moving up from floor %d\n", current_floor);
    usleep(WAIT_TIME * 1000000);    // Wait time between floors
    current_floor++;
}

// Function to move elevator down
void move_down() {
    printf("Elevator moving down from floor %d\n", current_floor);
    usleep(WAIT_TIME * 1000000);    // Wait time between floors
    current_floor--;
}

// Function to load passengers into elevator
void load_elevator() {
    int i = 0;
    while (i < ELEVATOR_CAPACITY && no_of_passengers_in_elevator < MAX_PASSENGERS && passengers_waiting[current_floor] > 0) {
        passengers_in_elevator[no_of_passengers_in_elevator] = 1;
        no_of_passengers_in_elevator++;
        passengers_waiting[current_floor]--;
        i++;
    }
}

// Function to unload passengers from elevator
void unload_elevator() {
    int i = 0;
    while (i < ELEVATOR_CAPACITY && no_of_passengers_in_elevator > 0 && passengers_in_elevator[i] == 1) {
        no_of_passengers_in_elevator--;
        passengers_in_elevator[i] = 0;
        i++;
    }
}

// Function to open elevator doors
void open_doors() {
    printf("Elevator doors opening on floor %d\n", current_floor);
    doors_open = true;
}

// Function to close elevator doors
void close_doors() {
    printf("Elevator doors closing on floor %d\n", current_floor);
    doors_open = false;
}

// Function for elevator thread
void *elevator(void *arg) {
    while (true) {
        pthread_mutex_lock(&elevator_mutex);   // Acquire mutex to access elevator
        
        if (current_floor == 0) {
            direction_up = true;
        } else if (current_floor == NO_OF_FLOORS-1) {
            direction_up = false;
        }
        
        if (direction_up) {
            if (passengers_waiting[current_floor] > 0 || no_of_passengers_in_elevator > 0) {
                open_doors();
                unload_elevator();
                load_elevator();
                close_doors();
                if (current_floor == NO_OF_FLOORS-1) {
                    direction_up = false;
                } else {
                    move_up();
                }
            } else {
                move_up();
            }
        } else {
            if (passengers_waiting[current_floor] > 0 || no_of_passengers_in_elevator > 0) {
                open_doors();
                unload_elevator();
                load_elevator();
                close_doors();
                if (current_floor == 0) {
                    direction_up = true;
                } else {
                    move_down();
                }
            } else {
                move_down();
            }
        }
        
        pthread_mutex_unlock(&elevator_mutex); // Release mutex for other threads
        
        usleep(WAIT_TIME * 1000000);    // Wait time between elevator movements
    }
}   

// Function for passenger thread
void *passenger(void *arg) {
    int floor = *(int*)arg;
    while (true) {
        usleep(WAIT_TIME * 1000000);    // Wait for random amount of time before arriving at floor
        pthread_mutex_lock(&elevator_mutex);   // Acquire mutex to access elevator
        
        if (current_floor == floor && no_of_passengers_in_elevator < ELEVATOR_CAPACITY && doors_open) {
            passengers_waiting[floor]--;
            passengers_in_elevator[no_of_passengers_in_elevator] = 1;
            no_of_passengers_in_elevator++;
            printf("Passenger boarded at floor %d\n", floor);
        } else {
            passengers_waiting[floor]++;
        }
        
        pthread_mutex_unlock(&elevator_mutex); // Release mutex for other threads
    }
}

// Main function
int main() {
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator, NULL);    // Start elevator thread
    
    pthread_t passenger_threads[NO_OF_FLOORS];
    int i;
    for (i = 0; i < NO_OF_FLOORS; i++) {
        int *floor = malloc(sizeof(int));
        *floor = i;
        pthread_create(&passenger_threads[i], NULL, passenger, (void*) floor);   // Start passenger threads
    }
    
    pthread_join(elevator_thread, NULL);    // Wait for elevator thread to finish
    
    for (i = 0; i < NO_OF_FLOORS; i++) {
        pthread_join(passenger_threads[i], NULL);    // Wait for all passenger threads to finish
    }
    
    return 0;
}