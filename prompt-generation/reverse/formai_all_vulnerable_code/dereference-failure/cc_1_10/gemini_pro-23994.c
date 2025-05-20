//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the airport's baggage handling system
struct baggage_system {
    int num_conveyors;
    struct conveyor *conveyors;
    int num_sorters;
    struct sorter *sorters;
    int num_gates;
    struct gate *gates;
    int num_bags;
    struct bag *bags;
};

// Define a baggage conveyor
struct conveyor {
    int id;
    int length;
    int speed;
    int capacity;
    int num_bags;
    struct bag *bags;
};

// Define a baggage sorter
struct sorter {
    int id;
    int capacity;
    int num_bags;
    struct bag *bags;
};

// Define a baggage gate
struct gate {
    int id;
    int capacity;
    int num_bags;
    struct bag *bags;
};

// Define a baggage item
struct bag {
    int id;
    int weight;
    int size;
    int destination;
    int status;
};

// Initialize the airport's baggage handling system
struct baggage_system *init_baggage_system(int num_conveyors, int num_sorters, int num_gates, int num_bags) {
    struct baggage_system *system = malloc(sizeof(struct baggage_system));
    system->num_conveyors = num_conveyors;
    system->conveyors = malloc(sizeof(struct conveyor) * num_conveyors);
    system->num_sorters = num_sorters;
    system->sorters = malloc(sizeof(struct sorter) * num_sorters);
    system->num_gates = num_gates;
    system->gates = malloc(sizeof(struct gate) * num_gates);
    system->num_bags = num_bags;
    system->bags = malloc(sizeof(struct bag) * num_bags);
    return system;
}

// Generate random baggage items
void generate_bags(struct baggage_system *system) {
    for (int i = 0; i < system->num_bags; i++) {
        system->bags[i].id = i;
        system->bags[i].weight = rand() % 100;
        system->bags[i].size = rand() % 100;
        system->bags[i].destination = rand() % system->num_gates;
        system->bags[i].status = 0;
    }
}

// Simulate the movement of baggage through the system
void simulate_baggage_handling(struct baggage_system *system) {
    // Move bags from conveyors to sorters
    for (int i = 0; i < system->num_conveyors; i++) {
        struct conveyor *conveyor = &system->conveyors[i];
        for (int j = 0; j < conveyor->num_bags; j++) {
            struct bag *bag = &conveyor->bags[j];
            if (bag->status == 0) {
                int sorter_id = rand() % system->num_sorters;
                struct sorter *sorter = &system->sorters[sorter_id];
                if (sorter->num_bags < sorter->capacity) {
                    sorter->bags[sorter->num_bags] = *bag;
                    sorter->num_bags++;
                    bag->status = 1;
                }
            }
        }
    }

    // Move bags from sorters to gates
    for (int i = 0; i < system->num_sorters; i++) {
        struct sorter *sorter = &system->sorters[i];
        for (int j = 0; j < sorter->num_bags; j++) {
            struct bag *bag = &sorter->bags[j];
            if (bag->status == 1) {
                int gate_id = bag->destination;
                struct gate *gate = &system->gates[gate_id];
                if (gate->num_bags < gate->capacity) {
                    gate->bags[gate->num_bags] = *bag;
                    gate->num_bags++;
                    bag->status = 2;
                }
            }
        }
    }
}

// Print the status of the baggage handling system
void print_baggage_system_status(struct baggage_system *system) {
    printf("Conveyor Belts:\n");
    for (int i = 0; i < system->num_conveyors; i++) {
        struct conveyor *conveyor = &system->conveyors[i];
        printf("  Conveyor %d: %d bags\n", conveyor->id, conveyor->num_bags);
    }

    printf("Sorters:\n");
    for (int i = 0; i < system->num_sorters; i++) {
        struct sorter *sorter = &system->sorters[i];
        printf("  Sorter %d: %d bags\n", sorter->id, sorter->num_bags);
    }

    printf("Gates:\n");
    for (int i = 0; i < system->num_gates; i++) {
        struct gate *gate = &system->gates[i];
        printf("  Gate %d: %d bags\n", gate->id, gate->num_bags);
    }

    printf("Bags:\n");
    for (int i = 0; i < system->num_bags; i++) {
        struct bag *bag = &system->bags[i];
        printf("  Bag %d: weight %d, size %d, destination %d, status %d\n", bag->id, bag->weight, bag->size, bag->destination, bag->status);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the airport's baggage handling system
    struct baggage_system *system = init_baggage_system(3, 2, 5, 100);

    // Generate random baggage items
    generate_bags(system);

    // Simulate the movement of baggage through the system
    simulate_baggage_handling(system);

    // Print the status of the baggage handling system
    print_baggage_system_status(system);

    return 0;
}