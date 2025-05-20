//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define structure for representing an item in the knapsack
typedef struct {
    int value;
    int weight;
} item;

// Define the knapsack problem function
void knapsack(int capacity, item items[], int n) {

    // Sort the items in decreasing order of value/weight ratio
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double ratio_i = (double)items[i].value/items[i].weight;
            double ratio_j = (double)items[j].value/items[j].weight;
            if (ratio_j > ratio_i) {
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // Initialize variables for the knapsack solution
    int *selected_items = (int *) malloc(n * sizeof(int));
    int total_value = 0;
    int total_weight = 0;

    // Fill the knapsack with items greedily
    for (int i = 0; i < n; i++) {
        if (total_weight + items[i].weight <= capacity) {
            selected_items[i] = 1;
            total_value += items[i].value;
            total_weight += items[i].weight;
        } else {
            selected_items[i] = 0;
        }
    }

    // Print out the knapsack solution
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (selected_items[i]) {
            printf("Item %d (value: %d, weight: %d)\n", i+1, items[i].value, items[i].weight);
        }
    }
    printf("Total weight: %d\n", total_weight);
    printf("Total value: %d\n", total_value);
}

// Main function to test the knapsack function
int main() {
    item items[] = {{12, 4}, {8, 3}, {10, 6}, {15, 8}, {5, 1}, {7, 3}};
    int capacity = 14;
    int num_items = sizeof(items)/sizeof(item);

    knapsack(capacity, items, num_items);

    return 0;
}