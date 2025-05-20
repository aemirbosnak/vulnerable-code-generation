//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Global variables for the house
int numRooms = 5;
int numDoors = 3;
int numTraps = 2;
char** roomNames = {"Foyer", "Living Room", "Kitchen", "Bedroom", "Bathroom"};

// Function to generate a random number between min and max
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create the house
void createHouse() {
    // Create the rooms
    for (int i = 0; i < numRooms; i++) {
        printf("Creating room %s\n", roomNames[i]);
        // Create the doors
        for (int j = 0; j < numDoors; j++) {
            printf("Creating door in room %s\n", roomNames[i]);
        }
        // Create the traps
        for (int k = 0; k < numTraps; k++) {
            printf("Creating trap in room %s\n", roomNames[i]);
        }
    }
}

// Function to print the house
void printHouse() {
    // Print the rooms
    for (int i = 0; i < numRooms; i++) {
        printf("Room %s:\n", roomNames[i]);
        // Print the doors
        for (int j = 0; j < numDoors; j++) {
            printf("Door %d\n", j);
        }
        // Print the traps
        for (int k = 0; k < numTraps; k++) {
            printf("Trap %d\n", k);
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the house
    createHouse();

    // Print the house
    printHouse();

    return 0;
}