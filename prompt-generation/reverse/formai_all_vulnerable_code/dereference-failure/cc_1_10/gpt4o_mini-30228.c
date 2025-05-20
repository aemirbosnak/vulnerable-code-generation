//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

// Function declarations
void knapSackRecursive(Item items[], int n, int capacity, int currentWeight, int currentValue, int *maxValue);
void knapSackGreedy(Item items[], int n, int capacity);

// Function to calculate the maximum value using recursion
void knapSackRecursive(Item items[], int n, int capacity, int currentWeight, int currentValue, int *maxValue) {
    // Base condition: If we reach the end of items or the remaining capacity is 0
    if (n == 0 || capacity == 0) {
        if (currentValue > *maxValue) {
            *maxValue = currentValue;
        }
        return;
    }
    
    // If the weight of the nth item is more than the capacity, skip it
    if (items[n - 1].weight > capacity) {
        knapSackRecursive(items, n - 1, capacity, currentWeight, currentValue, maxValue);
    } else {
        // Include the nth item
        knapSackRecursive(items, n - 1, capacity - items[n - 1].weight, currentWeight + items[n - 1].weight, currentValue + items[n - 1].value, maxValue);
        // Exclude the nth item
        knapSackRecursive(items, n - 1, capacity, currentWeight, currentValue, maxValue);
    }
}

// Greedy approach to demonstrate knapsack problem solution on sorted items
void knapSackGreedy(Item items[], int n, int capacity) {
    // Sort items in decreasing order of value to weight ratio
    double ratio[MAX_ITEMS];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double) items[i].value / items[i].weight;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap items
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
                
                // Swap ratios
                double tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;
            }
        }
    }
    
    int totalValue = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    printf("Greedy approach total value: %d\n", totalValue);
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    // Recursive approach
    int maxValue = 0;
    knapSackRecursive(items, n, capacity, 0, 0, &maxValue);
    printf("Recursive approach maximum value: %d\n", maxValue);
    
    // Greedy approach
    knapSackGreedy(items, n, capacity);
    
    return 0;
}