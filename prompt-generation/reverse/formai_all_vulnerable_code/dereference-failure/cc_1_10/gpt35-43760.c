//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags and random seed.
#define MAX_BAGS 10
#define RANDOM_SEED 42

// Define a structure for a baggage item.
typedef struct {
    int weight;
} BaggageItem;

// Define a structure for a baggage conveyor belt.
typedef struct {
    BaggageItem *items[MAX_BAGS];
    int num_items;
} BaggageConveyorBelt;

// Function to generate a random weight for a bag between 10 and 30 kg.
int generateRandomWeight() {
    return (rand() % 21) + 10;
}

// Function to add a baggage item to the conveyor belt.
void addItemToConveyorBelt(BaggageConveyorBelt *conveyorBelt, BaggageItem *item) {
    if (conveyorBelt->num_items == MAX_BAGS) {
        printf("Oops! The conveyor belt is full.\n");
        return;
    }
    conveyorBelt->items[conveyorBelt->num_items++] = item;
    printf("A %d kg bag has been added to the conveyor belt.\n", item->weight);
}

// Function to remove a baggage item from the conveyor belt.
BaggageItem *removeItemFromConveyorBelt(BaggageConveyorBelt *conveyorBelt) {
    if (conveyorBelt->num_items == 0) {
        printf("Oops! The conveyor belt is empty.\n");
        return NULL;
    }
    BaggageItem *item = conveyorBelt->items[--conveyorBelt->num_items];
    printf("A %d kg bag has been removed from the conveyor belt.\n", item->weight);
    return item;
}

int main() {

    // Initialize the random seed.
    srand(RANDOM_SEED);

    // Create the baggage conveyor belt.
    BaggageConveyorBelt conveyorBelt = {.num_items = 0};

    printf("Welcome to the Baggage Handling Simulation!\n\n");

    // Add some random bags to the conveyor belt.
    for (int i = 1; i <= 5; i++) {
        BaggageItem *item = malloc(sizeof(BaggageItem));
        item->weight = generateRandomWeight();
        addItemToConveyorBelt(&conveyorBelt, item);
    }

    printf("\n");

    // Remove some bags from the conveyor belt.
    for (int i = 1; i <= 3; i++) {
        BaggageItem *item = removeItemFromConveyorBelt(&conveyorBelt);
        if (item != NULL) {
            free(item);
        }
        printf("\n");
    }

    // Add some more bags to the conveyor belt.
    for (int i = 1; i <= 3; i++) {
        BaggageItem *item = malloc(sizeof(BaggageItem));
        item->weight = generateRandomWeight();
        addItemToConveyorBelt(&conveyorBelt, item);
    }

    printf("\n");

    // Remove the remaining bags from the conveyor belt.
    while (conveyorBelt.num_items > 0) {
        BaggageItem *item = removeItemFromConveyorBelt(&conveyorBelt);
        if (item != NULL) {
            free(item);
        }
        printf("\n");
    }

    printf("Thanks for trying the Baggage Handling Simulation!\n");

    return 0;
}