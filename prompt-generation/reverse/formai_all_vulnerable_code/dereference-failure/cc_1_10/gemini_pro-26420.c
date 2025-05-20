//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a time traveler
typedef struct {
    int year;
    int month;
    int day;
    char *name;
} TimeTraveler;

// Structure to represent a time machine
typedef struct {
    int year;
    int month;
    int day;
    char *name;
    TimeTraveler *passengers[5];
} TimeMachine;

// Function to create a new time traveler
TimeTraveler *create_time_traveler(char *name, int year, int month, int day) {
    TimeTraveler *time_traveler = malloc(sizeof(TimeTraveler));
    time_traveler->name = name;
    time_traveler->year = year;
    time_traveler->month = month;
    time_traveler->day = day;
    return time_traveler;
}

// Function to create a new time machine
TimeMachine *create_time_machine(char *name, int year, int month, int day) {
    TimeMachine *time_machine = malloc(sizeof(TimeMachine));
    time_machine->name = name;
    time_machine->year = year;
    time_machine->month = month;
    time_machine->day = day;
    for (int i = 0; i < 5; i++) {
        time_machine->passengers[i] = NULL;
    }
    return time_machine;
}

// Function to add a passenger to a time machine
void add_passenger(TimeMachine *time_machine, TimeTraveler *time_traveler) {
    for (int i = 0; i < 5; i++) {
        if (time_machine->passengers[i] == NULL) {
            time_machine->passengers[i] = time_traveler;
            break;
        }
    }
}

// Function to print the time traveler's information
void print_time_traveler(TimeTraveler *time_traveler) {
    printf("Name: %s\n", time_traveler->name);
    printf("Year: %d\n", time_traveler->year);
    printf("Month: %d\n", time_traveler->month);
    printf("Day: %d\n", time_traveler->day);
}

// Function to print the time machine's information
void print_time_machine(TimeMachine *time_machine) {
    printf("Name: %s\n", time_machine->name);
    printf("Year: %d\n", time_machine->year);
    printf("Month: %d\n", time_machine->month);
    printf("Day: %d\n", time_machine->day);
    printf("Passengers:\n");
    for (int i = 0; i < 5; i++) {
        if (time_machine->passengers[i] != NULL) {
            print_time_traveler(time_machine->passengers[i]);
        }
    }
}

// Main function
int main() {
    // Create a new time traveler
    TimeTraveler *time_traveler1 = create_time_traveler("John Smith", 1980, 1, 1);

    // Create a new time machine
    TimeMachine *time_machine1 = create_time_machine("Time Traveler 1", 2022, 2, 2);

    // Add the time traveler to the time machine
    add_passenger(time_machine1, time_traveler1);

    // Print the time traveler's information
    printf("Time Traveler 1:\n");
    print_time_traveler(time_traveler1);

    // Print the time machine's information
    printf("Time Machine 1:\n");
    print_time_machine(time_machine1);

    return 0;
}