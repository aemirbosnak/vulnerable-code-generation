//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags and the maximum weight of a bag
#define MAX_BAGS 100
#define MAX_WEIGHT 50

// Define the structure of a bag
typedef struct {
    int weight;
    int destination;
} Bag;

// Define the structure of a conveyor belt
typedef struct {
    int length;
    int speed;
    Bag bags[MAX_BAGS];
    int num_bags;
} ConveyorBelt;

// Define the structure of an airport
typedef struct {
    ConveyorBelt belts[10];
    int num_belts;
} Airport;

// Create a new airport
Airport *create_airport() {
    Airport *airport = malloc(sizeof(Airport));
    airport->num_belts = 0;
    return airport;
}

// Add a new conveyor belt to the airport
void add_conveyor_belt(Airport *airport, ConveyorBelt belt) {
    airport->belts[airport->num_belts] = belt;
    airport->num_belts++;
}

// Create a new bag
Bag *create_bag(int weight, int destination) {
    Bag *bag = malloc(sizeof(Bag));
    bag->weight = weight;
    bag->destination = destination;
    return bag;
}

// Add a bag to a conveyor belt
void add_bag_to_belt(ConveyorBelt *belt, Bag *bag) {
    belt->bags[belt->num_bags] = *bag;
    belt->num_bags++;
}

// Move the bags on a conveyor belt
void move_bags(ConveyorBelt *belt) {
    for (int i = 0; i < belt->num_bags; i++) {
        belt->bags[i].destination--;
        if (belt->bags[i].destination == 0) {
            // The bag has reached its destination
            belt->num_bags--;
            for (int j = i; j < belt->num_bags; j++) {
                belt->bags[j] = belt->bags[j+1];
            }
            i--;
        }
    }
}

// Simulate the airport
void simulate_airport(Airport *airport) {
    // Create a random number generator
    srand(time(NULL));

    // Add some conveyor belts to the airport
    for (int i = 0; i < 10; i++) {
        ConveyorBelt belt;
        belt.length = 100;
        belt.speed = 10;
        belt.num_bags = 0;
        add_conveyor_belt(airport, belt);
    }

    // Add some bags to the conveyor belts
    for (int i = 0; i < 100; i++) {
        int weight = rand() % MAX_WEIGHT + 1;
        int destination = rand() % 10 + 1;
        Bag *bag = create_bag(weight, destination);
        add_bag_to_belt(&airport->belts[rand() % 10], bag);
    }

    // Simulate the airport for 100 time steps
    for (int i = 0; i < 100; i++) {
        // Move the bags on the conveyor belts
        for (int j = 0; j < airport->num_belts; j++) {
            move_bags(&airport->belts[j]);
        }
    }
}

// Print the status of the airport
void print_airport_status(Airport *airport) {
    printf("Airport status:\n");
    for (int i = 0; i < airport->num_belts; i++) {
        printf("Conveyor belt %d:\n", i+1);
        printf("Length: %d\n", airport->belts[i].length);
        printf("Speed: %d\n", airport->belts[i].speed);
        printf("Number of bags: %d\n", airport->belts[i].num_bags);
        for (int j = 0; j < airport->belts[i].num_bags; j++) {
            printf("Bag %d:\n", j+1);
            printf("Weight: %d\n", airport->belts[i].bags[j].weight);
            printf("Destination: %d\n", airport->belts[i].bags[j].destination);
        }
    }
}

// Free the memory allocated for the airport
void free_airport(Airport *airport) {
    for (int i = 0; i < airport->num_belts; i++) {
        free(airport->belts[i].bags);
    }
    free(airport);
}

// Main function
int main() {
    // Create a new airport
    Airport *airport = create_airport();

    // Simulate the airport
    simulate_airport(airport);

    // Print the status of the airport
    print_airport_status(airport);

    // Free the memory allocated for the airport
    free_airport(airport);

    return 0;
}