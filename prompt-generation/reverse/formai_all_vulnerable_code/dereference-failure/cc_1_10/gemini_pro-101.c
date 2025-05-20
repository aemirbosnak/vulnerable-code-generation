//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the baggage handling system
typedef struct baggage_handling_system {
    // The number of belts in the system
    int num_belts;

    // The length of each belt (in meters)
    int belt_length;

    // The speed of each belt (in meters per second)
    float belt_speed;

    // The capacity of each belt (in number of bags)
    int belt_capacity;

    // The current number of bags on each belt
    int *bags_on_belt;
} baggage_handling_system;

// Create a new baggage handling system
baggage_handling_system *create_baggage_handling_system(int num_belts, int belt_length, float belt_speed, int belt_capacity) {
    // Allocate memory for the new system
    baggage_handling_system *system = malloc(sizeof(baggage_handling_system));

    // Initialize the system's parameters
    system->num_belts = num_belts;
    system->belt_length = belt_length;
    system->belt_speed = belt_speed;
    system->belt_capacity = belt_capacity;

    // Allocate memory for the array of bags on each belt
    system->bags_on_belt = malloc(sizeof(int) * num_belts);

    // Initialize the array of bags on each belt to zero
    for (int i = 0; i < num_belts; i++) {
        system->bags_on_belt[i] = 0;
    }

    // Return the new system
    return system;
}

// Destroy a baggage handling system
void destroy_baggage_handling_system(baggage_handling_system *system) {
    // Free the memory allocated for the array of bags on each belt
    free(system->bags_on_belt);

    // Free the memory allocated for the system
    free(system);
}

// Add a bag to the baggage handling system
void add_bag_to_system(baggage_handling_system *system, int belt) {
    // Increment the number of bags on the belt
    system->bags_on_belt[belt]++;
}

// Remove a bag from the baggage handling system
void remove_bag_from_system(baggage_handling_system *system, int belt) {
    // Decrement the number of bags on the belt
    system->bags_on_belt[belt]--;
}

// Move the bags on the baggage handling system
void move_bags(baggage_handling_system *system) {
    // For each belt in the system
    for (int i = 0; i < system->num_belts; i++) {
        // Move the bags on the belt forward by one position
        for (int j = 0; j < system->bags_on_belt[i]; j++) {
            system->bags_on_belt[i] = (system->bags_on_belt[i] + 1) % system->belt_capacity;
        }
    }
}

// Print the state of the baggage handling system
void print_system_state(baggage_handling_system *system) {
    // For each belt in the system
    for (int i = 0; i < system->num_belts; i++) {
        // Print the number of bags on the belt
        printf("Belt %d: %d bags\n", i, system->bags_on_belt[i]);
    }
}

// Main function
int main() {
    // Create a new baggage handling system
    baggage_handling_system *system = create_baggage_handling_system(3, 100, 1.0, 10);

    // Add some bags to the system
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        add_bag_to_system(system, rand() % system->num_belts);
    }

    // Move the bags around the system
    for (int i = 0; i < 100; i++) {
        move_bags(system);
    }

    // Print the state of the system
    print_system_state(system);

    // Destroy the system
    destroy_baggage_handling_system(system);

    return 0;
}