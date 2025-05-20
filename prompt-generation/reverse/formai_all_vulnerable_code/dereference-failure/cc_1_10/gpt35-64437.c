//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 1000 // maximum number of bags
#define MAX_HOLD_CAPACITY 200 // maximum capacity of the hold

// Define a struct for the bags
typedef struct {
    int bagNumber; // unique identification number of the bag
    int weight; // weight of the bag in kg
    int destination; // code of the destination airport
} Bag;

// Define a struct for the hold
typedef struct {
    int holdCapacity; // maximum capacity of the hold
    int currentLoad; // current load of the hold
    Bag *contents[MAX_BAGS]; // an array of pointers to bags
} Hold;

// Function to randomly generate a bag
Bag *generateBag(int bagNumber, int maxWeight, int maxDestination) {
    Bag *bagPtr = malloc(sizeof(Bag));
    if (bagPtr == NULL) {
        fputs("Memory allocation error!\n", stderr);
        exit(EXIT_FAILURE);
    }
    bagPtr->bagNumber = bagNumber;
    bagPtr->weight = 1 + rand() % maxWeight;
    bagPtr->destination = rand() % maxDestination;
    return bagPtr;
}

int main() {

    srand((unsigned)time(NULL)); // seed the random number generator

    int numBags = 1 + rand() % MAX_BAGS; // randomly generate the number of bags
    int maxWeight = 30; // maximum weight of a bag in kg
    int maxDestination = 10; // maximum code of a destination airport

    // Create the hold
    Hold hold = {MAX_HOLD_CAPACITY, 0, {0}};

    // Load the bags into the hold
    for (int i=0; i<numBags; i++) {
        Bag *bag = generateBag(i+1, maxWeight, maxDestination);
        if (hold.currentLoad + bag->weight > hold.holdCapacity) {
            printf("Hold is full! Bag %d cannot be loaded.\n", bag->bagNumber);
            free(bag);
        } else {
            hold.contents[i] = bag;
            hold.currentLoad += bag->weight;
            printf("Loaded bag %d (weight: %d kg, destination: %d) into the hold.\n", bag->bagNumber, bag->weight, bag->destination);
        }
    }

    // Unload the bags from the hold and transfer to the conveyor belts according to their destinations
    for (int i=0; i<numBags; i++) {
        Bag *bag = hold.contents[i];
        if (bag != NULL) {
            printf("Unloaded bag %d (weight: %d kg, destination: %d) from the hold.\n", bag->bagNumber, bag->weight, bag->destination);
            hold.contents[i] = NULL;
            hold.currentLoad -= bag->weight;
            // Transfer the bag to the appropriate conveyor belt according to the destination airport
            printf("Transferring bag %d to the conveyor belt for destination airport %d...\n", bag->bagNumber, bag->destination);
        }
        free(bag);
    }

    return 0;
}