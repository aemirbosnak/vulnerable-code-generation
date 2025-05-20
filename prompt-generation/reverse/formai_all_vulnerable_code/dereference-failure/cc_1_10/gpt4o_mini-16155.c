//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    Item* items;
    int count;
    int capacity;
} Knapsack;

int compare(const void* a, const void* b) {
    double r1 = ((Item*)a)->value / (double)((Item*)a)->weight;
    double r2 = ((Item*)b)->value / (double)((Item*)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

void printKnapsackItems(Item* items, int count) {
    for (int i = 0; i < count; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
    }
}

void greedyKnapsack(Knapsack knapsack) {
    qsort(knapsack.items, knapsack.count, sizeof(Item), compare);
    
    int totalValue = 0;
    int totalWeight = 0;

    printf("Selected items:\n");
    for (int i = 0; i < knapsack.count; i++) {
        if (totalWeight + knapsack.items[i].weight <= knapsack.capacity) {
            totalWeight += knapsack.items[i].weight;
            totalValue += knapsack.items[i].value;
            printf("Selected Item %d: Value = %d, Weight = %d, Ratio = %.2f\n",
                   i + 1, knapsack.items[i].value, knapsack.items[i].weight,
                   (double)knapsack.items[i].value / knapsack.items[i].weight);
        }
    }
    
    printf("Total weight in knapsack: %d\n", totalWeight);
    printf("Total value in knapsack: %d\n", totalValue);
}

int main() {
    int itemCount = 5;
    int knapsackCapacity = 15;

    Knapsack knapsack;
    knapsack.count = itemCount;
    knapsack.capacity = knapsackCapacity;
    knapsack.items = (Item*)malloc(itemCount * sizeof(Item));

    // Example items
    knapsack.items[0] = (Item){60, 10};
    knapsack.items[1] = (Item){100, 20};
    knapsack.items[2] = (Item){120, 30};
    knapsack.items[3] = (Item){30, 5};
    knapsack.items[4] = (Item){20, 4};

    printf("Items available for selection:\n");
    printKnapsackItems(knapsack.items, itemCount);

    greedyKnapsack(knapsack);
    
    // Free allocated memory
    free(knapsack.items);

    return 0;
}