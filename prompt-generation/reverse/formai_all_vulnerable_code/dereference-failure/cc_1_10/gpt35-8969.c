//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// define a structure for representing baggage
typedef struct {
    int id;      // unique id of the baggage
    int weight;  // weight of the baggage in kg
} Baggage;

// define a structure for representing a baggage conveyor belt
typedef struct {
    Baggage *items;  // array of baggages on the belt
    int length;      // total length of the belt in meters
    int occupancy;   // total number of baggages on the belt
} ConveyorBelt;

// function for initializing the conveyor belt
void initConveyorBelt(ConveyorBelt *belt, int length) {
    belt->items = NULL;
    belt->length = length;
    belt->occupancy = 0;
}

// function for adding a baggage to the conveyor belt
void addBaggageToConveyorBelt(ConveyorBelt *belt, Baggage baggage) {
    int newLength = belt->occupancy + 1;
    belt->items = (Baggage*) realloc(belt->items, newLength * sizeof(Baggage));
    belt->items[newLength - 1] = baggage;
    belt->occupancy = newLength;
}

int main() {
    // initialize the conveyor belt
    ConveyorBelt belt;
    initConveyorBelt(&belt, 10);

    // add some baggages to the belt
    Baggage baggage1 = {1, 23};
    addBaggageToConveyorBelt(&belt, baggage1);

    Baggage baggage2 = {2, 19};
    addBaggageToConveyorBelt(&belt, baggage2);

    Baggage baggage3 = {3, 31};
    addBaggageToConveyorBelt(&belt, baggage3);

    // print the contents of the conveyor belt
    printf("Contents of the conveyor belt:\n");
    for (int i = 0; i < belt.occupancy; i++) {
        printf("Baggage #%d: %d kg\n", belt.items[i].id, belt.items[i].weight);
    }

    // free memory
    free(belt.items);

    return 0;
}