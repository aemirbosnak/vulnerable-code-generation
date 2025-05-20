//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of bags that can be handled by the system
#define MAX_BAGS 100

// Define the types of bags that can be handled by the system
typedef enum bag_type {
    HAND_LUGGAGE,
    CHECKED_LUGGAGE
} bag_type;

// Define the structure of a bag
typedef struct bag {
    bag_type type;
    int weight;
    int destination;
} bag;

// Define the structure of a baggage handling system
typedef struct baggage_handling_system {
    bag bags[MAX_BAGS];
    int num_bags;
} baggage_handling_system;

// Create a new baggage handling system
baggage_handling_system* create_baggage_handling_system() {
    baggage_handling_system* system = (baggage_handling_system*)malloc(sizeof(baggage_handling_system));
    system->num_bags = 0;
    return system;
}

// Add a bag to the baggage handling system
void add_bag(baggage_handling_system* system, bag* bag) {
    if (system->num_bags < MAX_BAGS) {
        system->bags[system->num_bags] = *bag;
        system->num_bags++;
    }
}

// Remove a bag from the baggage handling system
void remove_bag(baggage_handling_system* system, int index) {
    if (index >= 0 && index < system->num_bags) {
        for (int i = index; i < system->num_bags - 1; i++) {
            system->bags[i] = system->bags[i + 1];
        }
        system->num_bags--;
    }
}

// Sort the bags in the baggage handling system by destination
void sort_bags(baggage_handling_system* system) {
    for (int i = 0; i < system->num_bags - 1; i++) {
        for (int j = i + 1; j < system->num_bags; j++) {
            if (system->bags[i].destination > system->bags[j].destination) {
                bag temp = system->bags[i];
                system->bags[i] = system->bags[j];
                system->bags[j] = temp;
            }
        }
    }
}

// Print the bags in the baggage handling system
void print_bags(baggage_handling_system* system) {
    for (int i = 0; i < system->num_bags; i++) {
        printf("Bag %d: type = %d, weight = %d, destination = %d\n", i, system->bags[i].type, system->bags[i].weight, system->bags[i].destination);
    }
}

// Simulate the baggage handling system
void simulate_baggage_handling_system(baggage_handling_system* system) {
    // Add some bags to the system
    bag bag1 = {HAND_LUGGAGE, 10, 1};
    add_bag(system, &bag1);
    bag bag2 = {CHECKED_LUGGAGE, 20, 2};
    add_bag(system, &bag2);
    bag bag3 = {HAND_LUGGAGE, 15, 3};
    add_bag(system, &bag3);

    // Sort the bags by destination
    sort_bags(system);

    // Print the bags in the system
    print_bags(system);

    // Remove a bag from the system
    remove_bag(system, 1);

    // Print the bags in the system
    print_bags(system);
}

// Main function
int main() {
    // Create a new baggage handling system
    baggage_handling_system* system = create_baggage_handling_system();

    // Simulate the baggage handling system
    simulate_baggage_handling_system(system);

    // Free the memory allocated for the baggage handling system
    free(system);

    return 0;
}