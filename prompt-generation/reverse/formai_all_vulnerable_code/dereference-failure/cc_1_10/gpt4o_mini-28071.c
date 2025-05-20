//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_POTIONS 5

typedef struct {
    int id;
    char name[30];
    float potency;
} Potion;

// Function to create potions in an array
Potion* brewPotions(int numPotions) {
    Potion *potions = (Potion*)malloc(numPotions * sizeof(Potion));
    if (potions == NULL) {
        fprintf(stderr, "Alas! Unable to create potions. Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    return potions;
}

// Function to initialize potion properties
void initializePotion(Potion *potion, int id, const char *name, float potency) {
    potion->id = id;
    snprintf(potion->name, sizeof(potion->name), "%s", name);
    potion->potency = potency;
}

// Function to display the potion details
void displayPotions(Potion *potions, int numPotions) {
    printf("---- Magical Potions ----\n");
    for (int i = 0; i < numPotions; i++) {
        printf("Potion ID: %d\n", potions[i].id);
        printf("Potion Name: %s\n", potions[i].name);
        printf("Potion Potency: %.2f\n", potions[i].potency);
        printf("------------------------\n");
    }
}

// Function to clean up brewed potions
void disposePotions(Potion *potions) {
    free(potions);
    potions = NULL;  // Optional, for good practice
}

int main() {
    int numPotions;
    printf("Welcome to the Potion Brewing Factory!\n");
    printf("How many potions do you wish to brew (Max: %d)? ", MAX_POTIONS);
    scanf("%d", &numPotions);

    if (numPotions > MAX_POTIONS) {
        printf("Nay! You may only brew up to %d potions at once.\n", MAX_POTIONS);
        return EXIT_FAILURE;
    }

    Potion *potions = brewPotions(numPotions);

    // Initializing our potions with some magical properties
    initializePotion(&potions[0], 1, "Invisibility Potion", 75.5);
    initializePotion(&potions[1], 2, "Healing Potion", 80.0);
    initializePotion(&potions[2], 3, "Strength Potion", 90.3);
    initializePotion(&potions[3], 4, "Wisdom Potion", 65.4);
    initializePotion(&potions[4], 5, "Speed Potion", 88.8);

    // Display the brewed potions
    displayPotions(potions, numPotions);

    // Dispose of potions
    disposePotions(potions);

    printf("All potions brewed successfully and the cauldron is clean!\n");
    return EXIT_SUCCESS;
}