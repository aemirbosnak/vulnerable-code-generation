//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct for the Baggage
typedef struct {
    int weight;
    char type[255];
} Baggage;

// Struct for the Flight
typedef struct {
    int id;
    char destination[255];
    int numOfPassengers;
    Baggage *baggage;
} Flight;

// Struct for the Conveyor Belt
typedef struct {
    Baggage baggageQueue[50];
    int firstItemIndex;
    int lastItemIndex;
} ConveyorBelt;

// Function declaration
void loadBaggageOntoConveyorBelt(ConveyorBelt *cb, Baggage *b);
Baggage* removeBaggageFromConveyorBelt(ConveyorBelt *cb);
void printConveyorBelt(ConveyorBelt *cb);

int main() {
    // Initialise the Conveyor Belt
    ConveyorBelt cb;
    cb.firstItemIndex = 0;
    cb.lastItemIndex = 0;
    
    // Initialise the Flight
    Flight f;
    f.id = 1234;
    sprintf(f.destination, "London");
    f.numOfPassengers = 100;
    
    // Creating Baggage and adding them to the Conveyor Belt
    Baggage b1;
    b1.weight = 25;
    sprintf(b1.type, "Suitcase");
    loadBaggageOntoConveyorBelt(&cb, &b1);

    Baggage b2;
    b2.weight = 10;
    sprintf(b2.type, "backpack");
    loadBaggageOntoConveyorBelt(&cb, &b2);

    // Print the initial Conveyor Belt
    printf("Initial Conveyor Belt:\n");
    printConveyorBelt(&cb);
    printf("\n");

    // Remove Baggage from Conveyor Belt and move it to the flight
    printf("Loading Belt onto flight %d to %s:\n", f.id, f.destination);
    while (cb.firstItemIndex != cb.lastItemIndex) {
        Baggage *currentBaggage = removeBaggageFromConveyorBelt(&cb);
        printf("\nBaggage Type: %s, Weight: %d", currentBaggage->type, currentBaggage->weight);
        free(currentBaggage);
    }
    
    return 0;
}

// Function to load Baggage onto Conveyor Belt
void loadBaggageOntoConveyorBelt(ConveyorBelt *cb, Baggage *b) {
    cb->baggageQueue[cb->lastItemIndex] = *b;
    cb->lastItemIndex = (cb->lastItemIndex + 1) % 50;
}

// Function to remove Baggage from Conveyor Belt
Baggage* removeBaggageFromConveyorBelt(ConveyorBelt *cb) {
    if (cb->firstItemIndex == cb->lastItemIndex) {
        return NULL;
    }
    Baggage* result = (Baggage*) malloc(sizeof(Baggage));
    *result = cb->baggageQueue[cb->firstItemIndex];
    cb->firstItemIndex = (cb->firstItemIndex + 1) % 50;
    return result;
}

// Function to print the Conveyor Belt
void printConveyorBelt(ConveyorBelt *cb) {
    int i;
    for (i = cb->firstItemIndex; i != cb->lastItemIndex; i = (i + 1) % 50) {
        printf("Baggage Type: %s, Weight: %d\n", cb->baggageQueue[i].type, cb->baggageQueue[i].weight);
    }
}