//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
// Fallout: Scavenger's Delight in the Nuclear Wasteland

#include <stdio.h>
#include <stdlib.h>

// Resources and their respective weights (importance)
typedef struct Resource {
    char* name;
    int weight;
} Resource;

// Scavenger's backpack with a limited capacity
typedef struct Backpack {
    Resource* items;
    int capacity;
    int current_weight;
} Backpack;

// Comparison function to sort resources in descending order of weight
int compare_weights(const void* a, const void* b) {
    Resource* item1 = (Resource*)a;
    Resource* item2 = (Resource*)b;
    return item2->weight - item1->weight;
}

// Initialize the scavenger's backpack
Backpack* initialize_backpack(int capacity) {
    Backpack* backpack = malloc(sizeof(Backpack));
    backpack->capacity = capacity;
    backpack->current_weight = 0;
    backpack->items = NULL;
    return backpack;
}

// Load the backpack with resources greedily
void fill_backpack(Backpack* backpack, Resource* resources, int num_resources) {
    // Sort the resources in descending order of weight
    qsort(resources, num_resources, sizeof(Resource), compare_weights);

    // Iterate over the resources and add them to the backpack if possible
    for (int i = 0; i < num_resources; i++) {
        if (backpack->current_weight + resources[i].weight <= backpack->capacity) {
            backpack->items = realloc(backpack->items, (backpack->current_weight + 1) * sizeof(Resource));
            backpack->items[backpack->current_weight] = resources[i];
            backpack->current_weight += resources[i].weight;
        }
    }
}

// Display the contents of the backpack
void display_backpack(Backpack* backpack) {
    printf("Scavenger's Backpack:\n");
    for (int i = 0; i < backpack->current_weight; i++) {
        printf(" - %s (%d)\n", backpack->items[i].name, backpack->items[i].weight);
    }
}

// Deallocate the backpack and its contents
void destroy_backpack(Backpack* backpack) {
    free(backpack->items);
    free(backpack);
}

int main() {
    // Define the available resources and their weights
    Resource resources[] = {
        {"Canned Meat", 15},
        {"Water Purifier", 20},
        {"Medical Kit", 10},
        {"Radiation Suit", 25},
        {"Flashlight", 5},
        {"Assault Rifle", 30},
        {"Ammunition", 15},
        {"Radio", 10},
        {"First Aid Kit", 5},
        {"Solar Charger", 10}
    };
    int num_resources = sizeof(resources) / sizeof(resources[0]);

    // Initialize the backpack with a capacity of 50
    Backpack* backpack = initialize_backpack(50);

    // Find the most valuable resources and fill the backpack
    fill_backpack(backpack, resources, num_resources);

    // Show the result
    display_backpack(backpack);

    // Clean up
    destroy_backpack(backpack);
    return 0;
}