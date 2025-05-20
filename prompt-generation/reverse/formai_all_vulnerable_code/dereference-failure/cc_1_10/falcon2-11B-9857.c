//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void simulation(void);
void handle_error(void);

int main(void) {
    simulation();
    return 0;
}

void simulation(void) {
    printf("Welcome to the Airport Baggage Handling Simulation!\n");

    // Define constants
    const int CONVEYOR_BELT_CAPACITY = 50;
    int *bags = (int *) malloc(CONVEYOR_BELT_CAPACITY * sizeof(int));

    // Initialize bags to 0
    for (int i = 0; i < CONVEYOR_BELT_CAPACITY; i++) {
        bags[i] = 0;
    }

    int removed_bags = 0;

    // Simulate bags being added to the conveyor belt
    for (int i = 0; i < 10; i++) {
        // Generate a random weight for each bag
        srand(time(NULL));
        int weight = rand() % 100 + 1;

        // Add the bag to the conveyor belt
        bags[removed_bags] = weight;
        removed_bags++;
    }

    // Simulate bags being removed from the conveyor belt
    for (int i = 0; i < 10; i++) {
        // Remove a bag from the conveyor belt
        int removed_bag = bags[removed_bags - 1];

        // Print the weight of the removed bag
        printf("Removed bag: %d\n", removed_bag);

        // Check if there are any bags remaining in the conveyor belt
        if (removed_bags == 0) {
            handle_error();
            return;
        }

        // Remove the removed bag from the conveyor belt
        for (int j = 0; j < CONVEYOR_BELT_CAPACITY; j++) {
            if (bags[j] == removed_bag) {
                bags[j] = 0;
            }
        }

        removed_bags--;
    }

    // Print a message indicating the end of the simulation
    printf("Simulation complete!\n");

    free(bags);
}

void handle_error(void) {
    printf("Error: Unable to remove all bags from the conveyor belt.\n");
    exit(1);
}