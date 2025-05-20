//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags and the maximum capacity of the conveyor belt
#define MAX_BAGS 100
#define MAX_CAPACITY 50

// Define the structure of a bag
typedef struct {
    int id;
    int weight;
    int destination;
} Bag;

// Define the structure of the conveyor belt
typedef struct {
    Bag bags[MAX_CAPACITY];
    int size;
} ConveyorBelt;

// Create a new bag
Bag* createBag(int id, int weight, int destination) {
    Bag* bag = (Bag*)malloc(sizeof(Bag));
    bag->id = id;
    bag->weight = weight;
    bag->destination = destination;
    return bag;
}

// Create a new conveyor belt
ConveyorBelt* createConveyorBelt() {
    ConveyorBelt* belt = (ConveyorBelt*)malloc(sizeof(ConveyorBelt));
    belt->size = 0;
    return belt;
}

// Add a bag to the conveyor belt
void addBag(ConveyorBelt* belt, Bag* bag) {
    if (belt->size < MAX_CAPACITY) {
        belt->bags[belt->size++] = *bag;
    }
}

// Remove a bag from the conveyor belt
void removeBag(ConveyorBelt* belt) {
    if (belt->size > 0) {
        belt->size--;
    }
}

// Simulate the movement of bags on the conveyor belt
void simulate(ConveyorBelt* belt) {
    while (belt->size > 0) {
        // Remove the first bag from the belt
        Bag bag = belt->bags[0];
        removeBag(belt);

        // Print the bag's information
        printf("Bag %d (weight %d, destination %d) has been unloaded.\n", bag.id, bag.weight, bag.destination);
    }
}

// Main function
int main() {
    // Create a new conveyor belt
    ConveyorBelt* belt = createConveyorBelt();

    // Create a random number generator
    srand(time(NULL));

    // Add bags to the conveyor belt
    for (int i = 0; i < MAX_BAGS; i++) {
        int weight = rand() % 20 + 1;
        int destination = rand() % 10 + 1;
        Bag* bag = createBag(i, weight, destination);
        addBag(belt, bag);
    }

    // Simulate the movement of bags on the conveyor belt
    simulate(belt);

    return 0;
}