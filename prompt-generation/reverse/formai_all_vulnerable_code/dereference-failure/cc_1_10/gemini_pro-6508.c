//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of items and the maximum weight capacity
#define NUM_ITEMS 10
#define MAX_WEIGHT 15

// Define a structure to represent an item
typedef struct item {
    int weight;
    int value;
} item;

// Define a function to compare two items based on their value-to-weight ratio
int compare_items(const void *a, const void *b) {
    const item *item1 = (const item *)a;
    const item *item2 = (const item *)b;
    return (item2->value / item2->weight) - (item1->value / item1->weight);
}

// Define a function to solve the knapsack problem using a greedy algorithm
int knapsack_greedy(item items[], int num_items, int max_weight) {
    // Sort the items in decreasing order of value-to-weight ratio
    qsort(items, num_items, sizeof(item), compare_items);

    // Initialize the current weight and total value
    int current_weight = 0;
    int total_value = 0;

    // Iterate over the items
    for (int i = 0; i < num_items; i++) {
        // If the current weight plus the weight of the current item is less than or equal to the maximum weight capacity,
        // add the current item to the knapsack and update the current weight and total value
        if (current_weight + items[i].weight <= max_weight) {
            current_weight += items[i].weight;
            total_value += items[i].value;
        }
    }

    // Return the total value of the items in the knapsack
    return total_value;
}

// Define a function to generate a random set of items
item *generate_items(int num_items) {
    // Allocate memory for the items
    item *items = (item *)malloc(num_items * sizeof(item));

    // Initialize the random number generator
    srand(time(NULL));

    // Generate the items
    for (int i = 0; i < num_items; i++) {
        items[i].weight = rand() % MAX_WEIGHT;
        items[i].value = rand() % 100;
    }

    // Return the items
    return items;
}

// Define a function to print the items in a set
void print_items(item items[], int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: weight = %d, value = %d\n", i + 1, items[i].weight, items[i].value);
    }
}

// Define a main function to test the knapsack_greedy function
int main() {
    // Generate a random set of items
    item *items = generate_items(NUM_ITEMS);

    // Print the items
    printf("Items:\n");
    print_items(items, NUM_ITEMS);

    // Solve the knapsack problem using a greedy algorithm
    int total_value = knapsack_greedy(items, NUM_ITEMS, MAX_WEIGHT);

    // Print the total value of the items in the knapsack
    printf("Total value: %d\n", total_value);

    // Free the memory allocated for the items
    free(items);

    return 0;
}