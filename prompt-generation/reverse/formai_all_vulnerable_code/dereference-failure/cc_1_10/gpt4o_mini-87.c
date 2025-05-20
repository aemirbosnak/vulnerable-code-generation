//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;                 // Item ID
    double value;          // Value of the item
    double weight;         // Weight of the item
    double valuePerWeight; // Value-to-weight ratio
} Item;

// Comparison function to sort items by value-to-weight ratio
int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    if (itemA->valuePerWeight < itemB->valuePerWeight) return 1;
    if (itemA->valuePerWeight > itemB->valuePerWeight) return -1;
    return 0;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int capacity, Item items[], int numItems) {
    // Sort items based on value-to-weight ratio
    qsort(items, numItems, sizeof(Item), compare);

    double totalValue = 0.0;  // Total value accumulated in the knapsack
    for (int i = 0; i < numItems; i++) {
        if (capacity == 0) break; // No more capacity in the knapsack

        // Current item
        Item currentItem = items[i];

        // If the item can fit in the knapsack
        if (currentItem.weight <= capacity) {
            totalValue += currentItem.value; // Take whole item
            capacity -= currentItem.weight;   // Reduce remaining capacity
        } else {
            // Take the fraction of the remaining item
            totalValue += currentItem.valuePerWeight * capacity;
            capacity = 0; // Knapsack is full
        }
    }
    return totalValue;
}

int main() {
    int numItems;
    int capacity;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Input capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item* items = malloc(numItems * sizeof(Item)); // Allocate memory for items

    // Input item details
    for (int i = 0; i < numItems; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].id = i + 1;
        items[i].valuePerWeight = items[i].value / items[i].weight; // Calculate value/weight ratio
    }

    // Calculate maximum value that can be accommodated in the knapsack
    double maxValue = fractionalKnapsack(capacity, items, numItems);

    // Output the result
    printf("Max value in Knapsack = %.2f\n", maxValue);

    free(items); // Free allocated memory
    return 0;
}