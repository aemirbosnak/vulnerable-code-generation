//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the backpack
#define MAX_ITEMS 100

// Define the maximum weight that the backpack can hold
#define MAX_WEIGHT 100

// Define the structure of an item
typedef struct {
    int weight;
    int value;
} Item;

// Define the structure of the backpack
typedef struct {
    int weight;
    int value;
    Item items[MAX_ITEMS];
} Backpack;

// Function to create a new backpack
Backpack* create_backpack() {
    Backpack* backpack = malloc(sizeof(Backpack));
    backpack->weight = 0;
    backpack->value = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        backpack->items[i].weight = 0;
        backpack->items[i].value = 0;
    }
    return backpack;
}

// Function to add an item to the backpack
void add_item(Backpack* backpack, Item item) {
    if (backpack->weight + item.weight <= MAX_WEIGHT) {
        backpack->weight += item.weight;
        backpack->value += item.value;
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (backpack->items[i].weight == 0) {
                backpack->items[i] = item;
                break;
            }
        }
    }
}

// Function to print the contents of the backpack
void print_backpack(Backpack* backpack) {
    printf("Backpack contents:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (backpack->items[i].weight != 0) {
            printf("Item %d: weight = %d, value = %d\n", i + 1, backpack->items[i].weight, backpack->items[i].value);
        }
    }
    printf("Total weight: %d\n", backpack->weight);
    printf("Total value: %d\n", backpack->value);
}

// Main function
int main() {
    // Create a new backpack
    Backpack* backpack = create_backpack();

    // Create a list of items
    Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120},
        {40, 150},
        {50, 180},
    };

    // Add the items to the backpack
    for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
        add_item(backpack, items[i]);
    }

    // Print the contents of the backpack
    print_backpack(backpack);

    return 0;
}