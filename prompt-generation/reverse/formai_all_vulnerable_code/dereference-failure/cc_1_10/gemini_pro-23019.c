//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Baggage types
#define REGULAR 0
#define FRAGILE 1
#define OVERSIZED 2

// Baggage status
#define CHECKED_IN 0
#define LOADED 1
#define UNLOADED 2
#define DELIVERED 3

// Airport gates
#define GATE_A1 0
#define GATE_A2 1
#define GATE_B1 2
#define GATE_B2 3
#define GATE_C1 4
#define GATE_C2 5

// Simulation parameters
#define NUM_BAGS 100
#define NUM_GATES 6
#define SIMULATION_TIME 1000

// Baggage structure
typedef struct baggage {
    int type;
    int status;
    int gate;
    char *description;
} baggage;

// Airport gate structure
typedef struct gate {
    int num_bags;
    baggage *bags[NUM_BAGS];
} gate;

// Airport simulation
typedef struct airport {
    gate gates[NUM_GATES];
    baggage bags[NUM_BAGS];
} airport;

// Create a new airport
airport *create_airport() {
    airport *apt = malloc(sizeof(airport));
    for (int i = 0; i < NUM_GATES; i++) {
        apt->gates[i].num_bags = 0;
    }
    return apt;
}

// Create a new baggage
baggage *create_baggage(int type, int gate, char *description) {
    baggage *bag = malloc(sizeof(baggage));
    bag->type = type;
    bag->status = CHECKED_IN;
    bag->gate = gate;
    bag->description = description;
    return bag;
}

// Check in a baggage
void check_in_baggage(airport *apt, baggage *bag) {
    for (int i = 0; i < NUM_GATES; i++) {
        if (apt->gates[i].num_bags < NUM_BAGS) {
            bag->gate = i;
            apt->gates[i].bags[apt->gates[i].num_bags] = bag;
            apt->gates[i].num_bags++;
            break;
        }
    }
}

// Load a baggage onto a plane
void load_baggage(airport *apt, baggage *bag) {
    bag->status = LOADED;
    apt->gates[bag->gate].num_bags--;
}

// Unload a baggage from a plane
void unload_baggage(airport *apt, baggage *bag) {
    bag->status = UNLOADED;
}

// Deliver a baggage to a passenger
void deliver_baggage(airport *apt, baggage *bag) {
    bag->status = DELIVERED;
}

// Update the status of all baggages
void update_baggage_status(airport *apt) {
    for (int i = 0; i < NUM_BAGS; i++) {
        baggage *bag = &apt->bags[i];
        switch (bag->status) {
            case CHECKED_IN:
                check_in_baggage(apt, bag);
                break;
            case LOADED:
                unload_baggage(apt, bag);
                break;
            case UNLOADED:
                deliver_baggage(apt, bag);
                break;
            case DELIVERED:
                // Do nothing
                break;
        }
    }
}

// Print the status of all baggages
void print_baggage_status(airport *apt) {
    for (int i = 0; i < NUM_BAGS; i++) {
        baggage *bag = &apt->bags[i];
        printf("Baggage %d:\n", i);
        printf("    Type: %s\n", bag->type == REGULAR ? "Regular" : bag->type == FRAGILE ? "Fragile" : "Oversized");
        printf("    Status: %s\n", bag->status == CHECKED_IN ? "Checked in" : bag->status == LOADED ? "Loaded" : bag->status == UNLOADED ? "Unloaded" : "Delivered");
        printf("    Gate: %d\n", bag->gate);
        printf("    Description: %s\n", bag->description);
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Create a new airport
    airport *apt = create_airport();

    // Create a bunch of baggages
    for (int i = 0; i < NUM_BAGS; i++) {
        int type = rand() % 3;
        int gate = rand() % NUM_GATES;
        char *description = malloc(100);
        sprintf(description, "Baggage %d", i);
        baggage *bag = create_baggage(type, gate, description);
        apt->bags[i] = *bag;
    }

    // Update the status of all baggages
    for (int i = 0; i < SIMULATION_TIME; i++) {
        update_baggage_status(apt);
    }

    // Print the status of all baggages
    print_baggage_status(apt);

    return 0;
}