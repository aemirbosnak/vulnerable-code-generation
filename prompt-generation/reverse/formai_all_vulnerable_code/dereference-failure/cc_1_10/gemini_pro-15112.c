//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define NUM_BAGS 1000
#define NUM_CONVEYORS 5
#define MAX_CONVEYOR_SPEED 10
#define MIN_CONVEYOR_SPEED 1

// Baggage types
enum BaggageType {
    REGULAR,
    PRIORITY,
    FRAGILE
};

// Baggage
struct Baggage {
    int id;
    enum BaggageType type;
    int weight;
    int destination;
};

// Conveyor
struct Conveyor {
    int id;
    int speed;
    int direction;
    struct Baggage *baggage;
};

// Airport
struct Airport {
    struct Conveyor *conveyors;
    struct Baggage *bags;
};

// Functions
struct Airport *create_airport();
void destroy_airport(struct Airport *airport);
void simulate_airport(struct Airport *airport);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an airport
    struct Airport *airport = create_airport();

    // Simulate the airport
    simulate_airport(airport);

    // Destroy the airport
    destroy_airport(airport);

    return 0;
}

struct Airport *create_airport() {
    // Allocate memory for the airport
    struct Airport *airport = malloc(sizeof(struct Airport));

    // Create the conveyors
    airport->conveyors = malloc(sizeof(struct Conveyor) * NUM_CONVEYORS);
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        airport->conveyors[i].id = i;
        airport->conveyors[i].speed = rand() % (MAX_CONVEYOR_SPEED - MIN_CONVEYOR_SPEED + 1) + MIN_CONVEYOR_SPEED;
        airport->conveyors[i].direction = rand() % 2;
        airport->conveyors[i].baggage = NULL;
    }

    // Create the bags
    airport->bags = malloc(sizeof(struct Baggage) * NUM_BAGS);
    for (int i = 0; i < NUM_BAGS; i++) {
        airport->bags[i].id = i;
        airport->bags[i].type = rand() % 3;
        airport->bags[i].weight = rand() % 100;
        airport->bags[i].destination = rand() % 10;
    }

    return airport;
}

void destroy_airport(struct Airport *airport) {
    // Free the conveyors
    free(airport->conveyors);

    // Free the bags
    free(airport->bags);

    // Free the airport
    free(airport);
}

void simulate_airport(struct Airport *airport) {
    // Simulate the airport for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        // Move the bags on the conveyors
        for (int j = 0; j < NUM_CONVEYORS; j++) {
            if (airport->conveyors[j].baggage != NULL) {
                // Move the bag forward on the conveyor
                airport->conveyors[j].baggage->destination -= airport->conveyors[j].speed;

                // If the bag has reached its destination, remove it from the conveyor
                if (airport->conveyors[j].baggage->destination <= 0) {
                    airport->conveyors[j].baggage = NULL;
                }
            }
        }

        // Add new bags to the conveyors
        for (int j = 0; j < NUM_BAGS; j++) {
            // If the bag is not on a conveyor, add it to the first available conveyor
            if (airport->bags[j].destination > 0 && airport->conveyors[j % NUM_CONVEYORS].baggage == NULL) {
                airport->conveyors[j % NUM_CONVEYORS].baggage = &airport->bags[j];
            }
        }
    }
}