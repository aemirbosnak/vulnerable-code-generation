//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Sherlock Holmes's trusty assistant, Dr. Watson
typedef struct {
    char *name;
    int age;
    int experience;
} watson;

// The airport's baggage handling system
typedef struct {
    int num_bags;
    int max_bags;
    watson *workers;
    int num_workers;
} baggage_system;

// Initialize the baggage handling system
baggage_system *init_baggage_system(int num_bags, int max_bags, int num_workers) {
    baggage_system *system = malloc(sizeof(baggage_system));
    system->num_bags = num_bags;
    system->max_bags = max_bags;
    system->num_workers = num_workers;
    system->workers = malloc(sizeof(watson) * num_workers);
    for (int i = 0; i < num_workers; i++) {
        system->workers[i].name = malloc(20);
        sprintf(system->workers[i].name, "Watson %d", i + 1);
        system->workers[i].age = rand() % 65 + 18;
        system->workers[i].experience = rand() % 10 + 1;
    }
    return system;
}

// Destroy the baggage handling system
void destroy_baggage_system(baggage_system *system) {
    for (int i = 0; i < system->num_workers; i++) {
        free(system->workers[i].name);
    }
    free(system->workers);
    free(system);
}

// Simulate the baggage handling system
void simulate_baggage_system(baggage_system *system) {
    // Handle the bags
    while (system->num_bags > 0) {
        // Get the next bag
        int bag = rand() % system->num_bags;

        // Assign a worker to the bag
        int worker = rand() % system->num_workers;

        // Handle the bag
        system->workers[worker].experience++;
        system->num_bags--;
    }

    // Print the results
    printf("All bags have been handled.\n");
    for (int i = 0; i < system->num_workers; i++) {
        printf("Watson %d handled %d bags.\n", i + 1, system->workers[i].experience);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the baggage handling system
    baggage_system *system = init_baggage_system(100, 200, 5);

    // Simulate the baggage handling system
    simulate_baggage_system(system);

    // Destroy the baggage handling system
    destroy_baggage_system(system);

    return 0;
}