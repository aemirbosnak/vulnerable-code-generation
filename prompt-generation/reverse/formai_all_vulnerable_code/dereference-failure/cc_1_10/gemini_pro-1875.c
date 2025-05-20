//GEMINI-pro DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A serene meadow, where flowers bloom and birds sing
typedef struct Meadow {
    int num_flowers;
    int num_birds;
    int peacefulness;
} Meadow;

// Create a new meadow with a given number of flowers and birds
Meadow* create_meadow(int num_flowers, int num_birds) {
    Meadow* meadow = malloc(sizeof(Meadow));
    meadow->num_flowers = num_flowers;
    meadow->num_birds = num_birds;
    meadow->peacefulness = 0;
    return meadow;
}

// Add a new flower to the meadow
void add_flower(Meadow* meadow) {
    meadow->num_flowers++;
}

// Add a new bird to the meadow
void add_bird(Meadow* meadow) {
    meadow->num_birds++;
}

// Calculate the peacefulness of the meadow
void calculate_peacefulness(Meadow* meadow) {
    meadow->peacefulness = meadow->num_flowers * meadow->num_birds;
}

// Print the meadow's details
void print_meadow(Meadow* meadow) {
    printf("The meadow has %d flowers and %d birds.\n", meadow->num_flowers, meadow->num_birds);
    printf("The peacefulness of the meadow is %d.\n", meadow->peacefulness);
}

// Destroy the meadow
void destroy_meadow(Meadow* meadow) {
    free(meadow);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new meadow
    Meadow* meadow = create_meadow(rand() % 10, rand() % 10);

    // Add some flowers and birds to the meadow
    for (int i = 0; i < rand() % 10; i++) {
        add_flower(meadow);
    }
    for (int i = 0; i < rand() % 10; i++) {
        add_bird(meadow);
    }

    // Calculate the peacefulness of the meadow
    calculate_peacefulness(meadow);

    // Print the meadow's details
    print_meadow(meadow);

    // Destroy the meadow
    destroy_meadow(meadow);

    return 0;
}