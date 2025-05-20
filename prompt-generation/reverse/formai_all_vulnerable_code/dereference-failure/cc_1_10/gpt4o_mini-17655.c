//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
} Item;

// Function to compare two items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1; // descending order
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Greedy fractional knapsack algorithm
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0; // Total value of the knapsack
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) break; // No remaining capacity

        // If the current item's weight is less than or equal to remaining capacity
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight; // Reduce capacity
            totalValue += items[i].value; // Add full value of the item
        } else {
            // We can only take a fraction of the remaining item
            totalValue += items[i].value * ((double) capacity / items[i].weight);
            capacity = 0; // knapsack is full
        }
    }
    return totalValue;
}

// Main function to test the fractional knapsack function
int main() {
    int n; // number of items
    int capacity; // maximum weight capacity of knapsack

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item)); // Allocate memory for items

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Inputting items' weight and value
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio
    }

    // Calculate the maximum value that can be carried in the knapsack
    double maxValue = fractionalKnapsack(capacity, items, n);

    // Output the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(items);

    return 0;
}