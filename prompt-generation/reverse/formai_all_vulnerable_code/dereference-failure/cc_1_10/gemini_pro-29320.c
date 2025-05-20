//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years to travel
#define MAX_YEARS 100

// Define the minimum number of years to travel
#define MIN_YEARS -100

// Define the time interval between each step in years
#define TIME_INTERVAL 1

// Define the number of steps to take
#define NUM_STEPS 10

// Define the initial year
#define INITIAL_YEAR 2023

// Define the maximum speed of time travel in years per second
#define MAX_SPEED 100

// Define the minimum speed of time travel in years per second
#define MIN_SPEED -100

// Define the acceleration of time travel in years per second per second
#define ACCELERATION 1

// Define the maximum number of passengers
#define MAX_PASSENGERS 10

// Define the number of passengers
#define NUM_PASSENGERS 5

// Define the passenger names
char* passengerNames[] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Define the passenger ages
int passengerAges[] = {20, 21, 22, 23, 24};

// Define the passenger genders
char* passengerGenders[] = {"Female", "Male", "Female", "Male", "Female"};

// Define the passenger destinations
char* passengerDestinations[] = {"Paris", "London", "Rome", "Berlin", "Madrid"};

// Define the passenger arrival times
time_t passengerArrivalTimes[] = {1678492800, 1680163200, 1681836400, 1683509600, 1685182800};

// Define the time machine
struct TimeMachine {
    int year;
    float speed;
    float acceleration;
    int numPassengers;
    struct Passenger* passengers;
};

// Define the passenger
struct Passenger {
    char* name;
    int age;
    char* gender;
    char* destination;
    time_t arrivalTime;
};

// Create a new time machine
struct TimeMachine* create_time_machine() {
    struct TimeMachine* timeMachine = malloc(sizeof(struct TimeMachine));
    timeMachine->year = INITIAL_YEAR;
    timeMachine->speed = 0;
    timeMachine->acceleration = 0;
    timeMachine->numPassengers = 0;
    timeMachine->passengers = NULL;
    return timeMachine;
}

// Destroy the time machine
void destroy_time_machine(struct TimeMachine* timeMachine) {
    free(timeMachine->passengers);
    free(timeMachine);
}

// Add a passenger to the time machine
void add_passenger(struct TimeMachine* timeMachine, struct Passenger* passenger) {
    timeMachine->passengers = realloc(timeMachine->passengers, (timeMachine->numPassengers + 1) * sizeof(struct Passenger));
    timeMachine->passengers[timeMachine->numPassengers++] = *passenger;
}

// Remove a passenger from the time machine
void remove_passenger(struct TimeMachine* timeMachine, int index) {
    for (int i = index; i < timeMachine->numPassengers - 1; i++) {
        timeMachine->passengers[i] = timeMachine->passengers[i + 1];
    }
    timeMachine->numPassengers--;
}

// Print the time machine
void print_time_machine(struct TimeMachine* timeMachine) {
    printf("Time machine:\n");
    printf("Year: %d\n", timeMachine->year);
    printf("Speed: %.2f years/second\n", timeMachine->speed);
    printf("Acceleration: %.2f years/second^2\n", timeMachine->acceleration);
    printf("Number of passengers: %d\n", timeMachine->numPassengers);
    for (int i = 0; i < timeMachine->numPassengers; i++) {
        printf("Passenger %d:\n", i + 1);
        printf("Name: %s\n", timeMachine->passengers[i].name);
        printf("Age: %d\n", timeMachine->passengers[i].age);
        printf("Gender: %s\n", timeMachine->passengers[i].gender);
        printf("Destination: %s\n", timeMachine->passengers[i].destination);
        printf("Arrival time: %s\n", ctime(&timeMachine->passengers[i].arrivalTime));
    }
}

// Time travel
void time_travel(struct TimeMachine* timeMachine, int years) {
    // Update the year
    timeMachine->year += years;

    // Update the speed
    timeMachine->speed += timeMachine->acceleration * TIME_INTERVAL;

    // Update the passengers' arrival times
    for (int i = 0; i < timeMachine->numPassengers; i++) {
        timeMachine->passengers[i].arrivalTime += years * 3600 * 24;
    }
}

// Main function
int main() {
    // Create a new time machine
    struct TimeMachine* timeMachine = create_time_machine();

    // Add passengers to the time machine
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        struct Passenger passenger;
        passenger.name = passengerNames[i];
        passenger.age = passengerAges[i];
        passenger.gender = passengerGenders[i];
        passenger.destination = passengerDestinations[i];
        passenger.arrivalTime = passengerArrivalTimes[i];
        add_passenger(timeMachine, &passenger);
    }

    // Print the time machine
    print_time_machine(timeMachine);

    // Time travel
    for (int i = 0; i < NUM_STEPS; i++) {
        // Get the years to travel
        int years;
        printf("Enter the years to travel (between %d and %d): ", MIN_YEARS, MAX_YEARS);
        scanf("%d", &years);

        // Check if the years are valid
        if (years < MIN_YEARS || years > MAX_YEARS) {
            printf("Invalid years!\n");
            continue;
        }

        // Time travel
        time_travel(timeMachine, years);

        // Print the time machine
        print_time_machine(timeMachine);
    }

    // Destroy the time machine
    destroy_time_machine(timeMachine);

    return 0;
}