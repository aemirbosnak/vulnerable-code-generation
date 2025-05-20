//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travelers
#define MAX_TRAVELERS 10

// Define the maximum number of years a traveler can travel
#define MAX_YEARS 100

// Define the maximum number of destinations a traveler can visit
#define MAX_DESTINATIONS 10

// Define the structure of a time traveler
typedef struct {
    int id;
    int year_of_birth;
    int year_of_travel;
    int destination;
} time_traveler;

// Define the structure of a time travel simulator
typedef struct {
    int num_travelers;
    time_traveler travelers[MAX_TRAVELERS];
} time_travel_simulator;

// Create a new time travel simulator
time_travel_simulator* create_time_travel_simulator(int num_travelers) {
    time_travel_simulator* simulator = malloc(sizeof(time_travel_simulator));
    simulator->num_travelers = num_travelers;
    for (int i = 0; i < num_travelers; i++) {
        simulator->travelers[i].id = i;
        simulator->travelers[i].year_of_birth = 1900 + rand() % 100;
        simulator->travelers[i].year_of_travel = 1900 + rand() % 100;
        simulator->travelers[i].destination = rand() % MAX_DESTINATIONS;
    }
    return simulator;
}

// Destroy a time travel simulator
void destroy_time_travel_simulator(time_travel_simulator* simulator) {
    free(simulator);
}

// Run a time travel simulation
void run_time_travel_simulation(time_travel_simulator* simulator) {
    for (int i = 0; i < simulator->num_travelers; i++) {
        time_traveler* traveler = &simulator->travelers[i];
        printf("Traveler %d:\n", traveler->id);
        printf("  Year of birth: %d\n", traveler->year_of_birth);
        printf("  Year of travel: %d\n", traveler->year_of_travel);
        printf("  Destination: %d\n", traveler->destination);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new time travel simulator
    time_travel_simulator* simulator = create_time_travel_simulator(MAX_TRAVELERS);

    // Run the time travel simulation
    run_time_travel_simulation(simulator);

    // Destroy the time travel simulator
    destroy_time_travel_simulator(simulator);

    return 0;
}