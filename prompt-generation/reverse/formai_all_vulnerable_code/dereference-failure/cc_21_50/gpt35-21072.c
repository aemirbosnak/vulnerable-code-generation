//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ELEVATOR_CAPACITY 10 // Maximum number of people allowed in the elevator
#define MAX_FLOORS 20 // Total number of floors in the building
#define MIN_FLOORS 5 // Minimum number of floors in the building
#define MAX_TRAVEL_TIME 10 // Maximum travel time between floors
#define MIN_TRAVEL_TIME 1 // Minimum travel time between floors
#define MAX_WAIT_TIME 5 // Maximum wait time for the elevator
#define MIN_WAIT_TIME 1 // Minimum wait time for the elevator

// A structure to represent a person
typedef struct {
    int current_floor;
    int destination_floor;
} Person;

// A structure to represent an elevator
typedef struct {
    int capacity;
    int current_floor;
    int destination_floor;
    int occupied_space;
    int *passenger_list; // A pointer to an array of passenger floors
} Elevator;

// Main function
int main() {
    // Initialization
    srand(time(NULL)); // To generate random numbers
    int num_floors = rand() % (MAX_FLOORS - MIN_FLOORS + 1) + MIN_FLOORS; // Random number of floors
    int num_people = rand() % (num_floors * ELEVATOR_CAPACITY) + 1; // Random number of people
    Person *person_list = malloc(num_people * sizeof(Person)); // An array of persons
    Elevator elevator = {ELEVATOR_CAPACITY, 1, 1, 0, malloc(ELEVATOR_CAPACITY * sizeof(int))}; // The elevator
    printf("Number of floors: %d\nNumber of people: %d\n", num_floors, num_people);

    // Generate random people and their destinations
    for(int i = 0; i < num_people; i++) {
        person_list[i].current_floor = rand() % num_floors + 1;
        do {
            person_list[i].destination_floor = rand() % num_floors + 1;
        } while(person_list[i].destination_floor == person_list[i].current_floor);
    }

    // Elevator simulation
    while(1) {
        // Check if there are any people waiting on the current floor
        int passengers_waiting = 0;
        for(int i = 0; i < num_people; i++) {
            if(person_list[i].current_floor == elevator.current_floor) {
                passengers_waiting++;
                if(elevator.occupied_space < ELEVATOR_CAPACITY) { // If there is space in the elevator
                    elevator.passenger_list[elevator.occupied_space++] = person_list[i].destination_floor; // Add the passenger to the elevator
                    printf("Person %d enters elevator at floor %d\n", i+1, elevator.current_floor);
                    person_list[i].current_floor = 0; // Set the person's current floor to 0 (i.e. inside the elevator)
                }
            }
        }

        // If there are no passengers waiting on the current floor and the elevator is empty, wait for some time
        if(passengers_waiting == 0 && elevator.occupied_space == 0) {
            printf("Elevator is empty. Waiting...\n");
            int wait_time = rand() % (MAX_WAIT_TIME - MIN_WAIT_TIME + 1) + MIN_WAIT_TIME; // Random wait time
            for(int i = 0; i < wait_time; i++) {
                printf("%d ", wait_time-i);
                fflush(stdout); // To immediately print the countdown
                sleep(1);
            }
            printf("\n");
            continue;
        }

        // Select the next destination floor
        int shortest_distance = num_floors;
        for(int i = 0; i < elevator.occupied_space; i++) {
            int distance = abs(elevator.current_floor - elevator.passenger_list[i]);
            if(distance < shortest_distance) {
                shortest_distance = distance;
                elevator.destination_floor = elevator.passenger_list[i];
            }
        }

        // Update elevator's position
        int travel_time = rand() % (MAX_TRAVEL_TIME - MIN_TRAVEL_TIME + 1) + MIN_TRAVEL_TIME; // Random travel time
        printf("Elevator going %s from floor %d to floor %d. Estimated travel time: %d seconds...\n", elevator.destination_floor > elevator.current_floor ? "up" : "down", elevator.current_floor, elevator.destination_floor, travel_time);
        for(int i = 0; i < travel_time; i++) {
            printf("%d ", travel_time-i);
            fflush(stdout); // To immediately print the countdown
            sleep(1);
        }
        printf("\n");
        elevator.current_floor = elevator.destination_floor;
        printf("Elevator arriving at floor %d\n", elevator.current_floor);

        // Let passengers exit the elevator
        int passengers_exiting = 0;
        for(int i = 0; i < elevator.occupied_space; i++) {
            if(elevator.passenger_list[i] == elevator.current_floor) {
                passengers_exiting++;
                printf("Person at floor %d exits elevator\n", elevator.current_floor);
                for(int j = i; j < elevator.occupied_space-1; j++) {
                    elevator.passenger_list[j] = elevator.passenger_list[j+1];
                }
                elevator.occupied_space--;
            }
        }

        // Let new passengers enter the elevator
        int passengers_boarding = 0;
        for(int i = 0; i < num_people; i++) {
            if(person_list[i].current_floor == elevator.current_floor) {
                passengers_boarding++;
                if(elevator.occupied_space < ELEVATOR_CAPACITY) { // If there is space in the elevator
                    elevator.passenger_list[elevator.occupied_space++] = person_list[i].destination_floor; // Add the passenger to the elevator
                    printf("Person %d enters elevator at floor %d\n", i+1, elevator.current_floor);
                    person_list[i].current_floor = 0; // Set the person's current floor to 0 (i.e. inside the elevator)
                }
            }
        }

        // If there are no passengers waiting and no passengers in the elevator, exit the simulation
        if(passengers_waiting == 0 && elevator.occupied_space == 0) {
            printf("No passengers remaining. Exiting the simulation...\n");
            break;
        }
    }

    // Free memory
    free(person_list);
    free(elevator.passenger_list);

    // Terminate the program
    return 0;
}