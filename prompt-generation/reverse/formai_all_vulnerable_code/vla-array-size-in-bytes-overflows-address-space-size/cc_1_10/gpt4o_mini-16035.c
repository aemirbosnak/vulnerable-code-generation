//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio;
};

// Comparator function to sort items based on their value-to-weight ratio
int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    
    if (itemB->ratio > itemA->ratio) {
        return 1;
    } else if (itemB->ratio < itemA->ratio) {
        return -1;
    }
    return 0;
}

// Function to calculate the maximum value that can be carried
double fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0; // Total value of items in knapsack
    for (int i = 0; i < n; i++) {
        if (capacity <= 0) {
            break; // Knapsack is full
        }

        // Take the whole item if it fits
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } 
        // Take the fraction of the last item that fits
        else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n; // Number of items
    int capacity; // Capacity of the knapsack

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];

    // Input the value and weight of each item
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d (format: value weight): ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate the maximum value that can be carried
    double maxValue = fractionalKnapsack(items, n, capacity);
    
    // Output the result
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}