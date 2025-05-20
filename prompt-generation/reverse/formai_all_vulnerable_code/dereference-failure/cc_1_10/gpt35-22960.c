//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold Baggage details
typedef struct {
    int id; // Baggage ID
    int weight; // Baggage Weight
} Baggage;

// Structure to hold Bin details
typedef struct {
    int id; // Bin ID
    int capacity; // Bin Capacity
    int current_weight; // Current weight in the bin
    int num_bags; // Number of bags in the bin
} Bin;

// Function to generate random number between min and max (inclusive)
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random Baggage
Baggage* generate_baggage(int id) {
    Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
    baggage->id = id;
    baggage->weight = generate_random_number(2, 50); // Assume weight is between 2-50 Kg
    return baggage;
}

// Function to generate a random Bin
Bin* generate_bin(int id) {
    Bin* bin = (Bin*)malloc(sizeof(Bin));
    bin->id = id;
    bin->capacity = generate_random_number(50, 200); // Assume capacity is between 50-200 Kg
    bin->current_weight = 0;
    bin->num_bags = 0;
    return bin;
}

// Function to add Baggage to a Bin
void add_baggage_to_bin(Baggage* baggage, Bin* bin) {
    bin->current_weight += baggage->weight;
    bin->num_bags++;
    printf("Baggage with ID %d added to Bin with ID %d\n", baggage->id, bin->id);
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    // Assume there are 10 Bins in the system
    int num_bins = 10;
    Bin** bins = (Bin**)malloc(num_bins * sizeof(Bin*));

    // Generate Bins and add them to the system
    for (int i = 0; i < num_bins; i++) {
        bins[i] = generate_bin(i);
        printf("Bin with ID %d, Capacity %dKg added to the system\n", bins[i]->id, bins[i]->capacity);
    }

    // Assume there are 50 Baggage items to be added to the system
    int num_baggage = 50;
    Baggage** baggage_items = (Baggage**)malloc(num_baggage * sizeof(Baggage*));

    // Generate Baggage items and add them to the system
    for (int i = 0; i < num_baggage; i++) {
        baggage_items[i] = generate_baggage(i);
        printf("Baggage with ID %d, Weight %dKg added to the system\n", baggage_items[i]->id, baggage_items[i]->weight);
    }

    // Add Baggage to Bins
    for (int i = 0; i < num_baggage; i++) {
        // Find the Bin with least weight
        int min_weight_bin_index = 0;
        for (int j = 1; j < num_bins; j++) {
            if (bins[j]->current_weight < bins[min_weight_bin_index]->current_weight) {
                min_weight_bin_index = j;
            }
        }

        // Add Baggage to Bin with least weight
        add_baggage_to_bin(baggage_items[i], bins[min_weight_bin_index]);
    }

    // Print final status of the Bins
    printf("\nFinal Status of Bins:\n");
    for (int i = 0; i < num_bins; i++) {
        printf("Bin with ID %d, Capacity %dKg, Current Weight %dKg, Number of Bags %d\n", bins[i]->id, bins[i]->capacity, bins[i]->current_weight, bins[i]->num_bags);
    }

    return 0;
}