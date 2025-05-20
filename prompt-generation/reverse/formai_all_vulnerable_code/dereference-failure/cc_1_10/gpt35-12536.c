//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_PASSENGERS 50

// Struct to represent a passenger
typedef struct Passenger {
    int id;
    int num_bags;
    int* bags;
} Passenger;

// Struct to represent a baggage
typedef struct Baggage {
    int id;
    int owner_id;
} Baggage;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables
    int num_passengers = rand() % (MAX_PASSENGERS + 1); // Random number of passengers
    Passenger passengers[num_passengers];
    bool handled_bags[MAX_BAGS] = {false};
    Baggage baggage[MAX_BAGS];
    int num_bags = 0;

    // Generate passengers and their bags
    for (int i = 0; i < num_passengers; i++) {
        int num_bags = rand() % 5 + 1; // Random number of bags for the passenger
        int bags[num_bags]; // Array to hold the bag IDs
        for (int j = 0; j < num_bags; j++) {
            // Generate a unique bag ID
            int bag_id = rand() % MAX_BAGS;
            while (handled_bags[bag_id]) {
                bag_id = rand() % MAX_BAGS;
            }
            handled_bags[bag_id] = true;
            // Add the bag to the passenger's list
            bags[j] = bag_id;
            // Create a new baggage object
            Baggage new_baggage = {bag_id, i};
            baggage[num_bags] = new_baggage;
        }
        Passenger new_passenger = {i, num_bags, bags};
        passengers[i] = new_passenger;
    }

    // Simulate the baggage handling process
    for (int pass = 0; pass < num_passengers; pass++) {
        printf("Processing bags for Passenger %d...\n", pass);
        for (int bag = 0; bag < passengers[pass].num_bags; bag++) {
            printf("Handling Baggage %d for Passenger %d...\n", passengers[pass].bags[bag], pass);
            // Simulate handling process
            int rand_num = rand() % 100;
            if (rand_num < 70) {
                printf("Baggage %d was handled successfully\n", passengers[pass].bags[bag]);
            } else {
                printf("Error: Baggage %d was lost in transit\n", passengers[pass].bags[bag]);
            }
        }
    }

    return 0;
}