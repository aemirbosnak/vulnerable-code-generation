//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    int num_bags = rand() % 10 + 1; // Generate a random number of bags between 1 and 10
    int num_carriers = rand() % 3 + 1; // Generate a random number of carriers between 1 and 3
    int num_bags_per_carrier = rand() % 10 + 1; // Generate a random number of bags per carrier between 1 and 10
    int* carriers = malloc(num_carriers * sizeof(int)); // Allocate memory for the carriers
    int* bags = malloc(num_bags * sizeof(int)); // Allocate memory for the bags
    int* bags_per_carrier = malloc(num_carriers * sizeof(int)); // Allocate memory for the bags per carrier

    // Generate random bag and carrier IDs
    for (int i = 0; i < num_bags; i++) {
        bags[i] = rand() % 1000 + 1; // Generate a random bag ID between 1 and 1000
    }
    for (int i = 0; i < num_carriers; i++) {
        carriers[i] = rand() % 1000 + 1; // Generate a random carrier ID between 1 and 1000
    }
    for (int i = 0; i < num_carriers; i++) {
        bags_per_carrier[i] = rand() % 10 + 1; // Generate a random number of bags per carrier between 1 and 10
    }

    // Print the generated bag and carrier IDs
    printf("Generated Bag IDs:\n");
    for (int i = 0; i < num_bags; i++) {
        printf("Bag %d: %d\n", i+1, bags[i]);
    }
    printf("Generated Carrier IDs:\n");
    for (int i = 0; i < num_carriers; i++) {
        printf("Carrier %d: %d\n", i+1, carriers[i]);
    }

    // Simulate the baggage handling process
    printf("Simulating baggage handling...\n");
    for (int i = 0; i < num_carriers; i++) {
        printf("Carrier %d: ", i+1);
        for (int j = 0; j < bags_per_carrier[i]; j++) {
            printf("Bag %d: ", j+1);
            printf("Carried by Carrier %d\n", carriers[i]);
        }
    }

    // Free allocated memory
    free(carriers);
    free(bags);
    free(bags_per_carrier);

    return 0;
}