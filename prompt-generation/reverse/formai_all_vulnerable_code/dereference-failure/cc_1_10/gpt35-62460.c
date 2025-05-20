//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LUGGAGE 50
#define MAX_FLIGHTS 10

// Structure to represent a luggage item
typedef struct Luggage {
    int weight;
} Luggage;

// Structure to represent a flight
typedef struct Flight {
    char* flightNumber;
    Luggage* luggage[MAX_LUGGAGE];
    int numLuggage;
} Flight;

// Function to create a new luggage item
Luggage* createLuggage(int weight) {
    Luggage* luggage = malloc(sizeof(Luggage));
    luggage->weight = weight;
    return luggage;
}

// Function to create a new flight
Flight* createFlight(char* flightNumber) {
    Flight* flight = malloc(sizeof(Flight));
    flight->flightNumber = flightNumber;
    flight->numLuggage = 0;
    return flight;
}

// Function to add luggage to a flight
bool addLuggageToFlight(Flight* flight, Luggage* luggage) {
    if (flight->numLuggage >= MAX_LUGGAGE) {
        return false;
    }
    flight->luggage[flight->numLuggage] = luggage;
    flight->numLuggage++;
    return true;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of flights
    Flight* flights[MAX_FLIGHTS] = { 0 };

    // Add some flights with luggage
    flights[0] = createFlight("AA1234");
    addLuggageToFlight(flights[0], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[0], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[0], createLuggage(rand() % 50 + 1));
    flights[1] = createFlight("UA5678");
    addLuggageToFlight(flights[1], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[1], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[1], createLuggage(rand() % 50 + 1));
    flights[2] = createFlight("DL9101");
    addLuggageToFlight(flights[2], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[2], createLuggage(rand() % 50 + 1));
    addLuggageToFlight(flights[2], createLuggage(rand() % 50 + 1));

    // Simulate the baggage handling process
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flights[i] != NULL) {
            printf("Processing luggage for flight %s\n", flights[i]->flightNumber);
            for (int j = 0; j < flights[i]->numLuggage; j++) {
                printf("  Weight: %d\n", flights[i]->luggage[j]->weight);
            }
            printf("Done processing luggage for flight %s\n", flights[i]->flightNumber);
        }
    }

    // Free all memory used
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flights[i] != NULL) {
            for (int j = 0; j < flights[i]->numLuggage; j++) {
                free(flights[i]->luggage[j]);
            }
            free(flights[i]);
        }
    }

    return 0;
}