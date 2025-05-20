//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Structure to represent the baggage
typedef struct Baggage {
    char* passenger_name;
    int weight;
} Baggage;

// Structure to represent the conveyor belt
typedef struct ConveyorBelt {
    Baggage* baggage;
    int current_weight;
    int max_weight;
} ConveyorBelt;

// Function to generate a random integer between min and max
int generate_random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random passenger name
char* generate_random_name() {
    char* names[] = {"John", "Mary", "William", "Elizabeth", "James", "Margaret", "George", "Anne", "Thomas", "Sarah", "Charles", "Catherine", "Robert", "Jane", "Edward", "Frances", "Henry", "Alice", "Richard", "Martha"};
    int num_names = sizeof(names) / sizeof(names[0]);
    int index = generate_random_int(0, num_names - 1);
    return names[index];
}

// Function to create a new baggage object with a random passenger name and weight
Baggage* create_baggage() {
    Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
    baggage->passenger_name = generate_random_name();
    baggage->weight = generate_random_int(10, 30);
    return baggage;
}

// Function to create a new conveyor belt with the given max weight capacity
ConveyorBelt* create_conveyor_belt(int max_weight) {
    ConveyorBelt* conveyor_belt = (ConveyorBelt*)malloc(sizeof(ConveyorBelt));
    conveyor_belt->baggage = NULL;
    conveyor_belt->current_weight = 0;
    conveyor_belt->max_weight = max_weight;
    return conveyor_belt;
}

// Function to add the given baggage to the given conveyor belt
bool add_baggage_to_conveyor_belt(Baggage* baggage, ConveyorBelt* conveyor_belt) {
    if (conveyor_belt->current_weight + baggage->weight > conveyor_belt->max_weight) {
        // Conveyor belt is at max capacity, cannot add more baggage
        return false;
    }
    conveyor_belt->baggage = baggage;
    conveyor_belt->current_weight += baggage->weight;
    return true;
}

// Function to simulate the airport baggage handling process
void simulate_baggage_handling() {
    // Generate a random max weight capacity for the conveyor belt
    int max_weight = generate_random_int(100, 500);
    // Create a new conveyor belt
    ConveyorBelt* conveyor_belt = create_conveyor_belt(max_weight);

    printf("Baggage handling simulation started...\n");
    printf("Conveyor belt max weight capacity: %d kg\n", max_weight);

    srand(time(NULL));
    int num_baggage = 0;
    int total_weight_handled = 0;
    while (true) {
        // Generate a new baggage object
        Baggage* baggage = create_baggage();
        // Attempt to add the baggage to the conveyor belt
        bool added_to_conveyor_belt = add_baggage_to_conveyor_belt(baggage, conveyor_belt);
        if (added_to_conveyor_belt) {
            printf("Passenger %s has added %d kg baggage to the conveyor belt\n", baggage->passenger_name, baggage->weight);
            num_baggage++;
            total_weight_handled += baggage->weight;
        } else {
            // Conveyor belt is at max capacity, cannot add more baggage
            printf("Conveyor belt is at max capacity. Waiting for baggage to be processed...\n");
            free(baggage);
            break;
        }
        // Wait for some time to simulate baggage processing time
        int wait_time = generate_random_int(1, 5);
        printf("Waiting %d seconds for baggage to be processed...\n", wait_time);
        sleep(wait_time);
    }

    printf("Baggage handling simulation ended.\n");
    printf("Total baggage handled: %d\n", num_baggage);
    printf("Total weight handled: %d kg\n", total_weight_handled);
}

int main() {
    simulate_baggage_handling();
    return 0;
}