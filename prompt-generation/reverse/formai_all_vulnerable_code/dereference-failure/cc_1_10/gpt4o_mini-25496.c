//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

typedef struct {
    int n;
    Item* items;
} Knapsack;

void initializeKnapsack(Knapsack* knapsack, int n) {
    knapsack->n = n;
    knapsack->items = (Item*)malloc(n * sizeof(Item));
    
    for (int i = 0; i < n; i++) {
        knapsack->items[i].value = rand() % 100 + 1;  // Value between 1 and 100
        knapsack->items[i].weight = rand() % 20 + 1;  // Weight between 1 and 20
    }
}

void freeKnapsack(Knapsack* knapsack) {
    free(knapsack->items);
}

int comparator(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    
    return (ratioA < ratioB) ? 1 : -1;
}

void greedyKnapsack(Knapsack* knapsack, int maxWeight) {
    qsort(knapsack->items, knapsack->n, sizeof(Item), comparator);

    int totalValue = 0;
    int totalWeight = 0;
    int i = 0;

    printf("Items taken:\n");

    while (i < knapsack->n && totalWeight < maxWeight) {
        if (totalWeight + knapsack->items[i].weight <= maxWeight) {
            totalWeight += knapsack->items[i].weight;
            totalValue += knapsack->items[i].value;
            printf("Item %d: Value = %d, Weight = %d\n", i, knapsack->items[i].value, knapsack->items[i].weight);
        } else {
            double fraction = (double)(maxWeight - totalWeight) / knapsack->items[i].weight;
            totalValue += (int)(knapsack->items[i].value * fraction);
            totalWeight += maxWeight - totalWeight;
            printf("Item %d: Value = %.2f (fraction taken), Weight = %.2f (fraction taken)\n", i, knapsack->items[i].value * fraction, knapsack->items[i].weight * fraction);
            break;
        }
        i++;
    }

    printf("Total value: %d, Total weight: %d\n", totalValue, totalWeight);
}

int main() {
    int n = 10;
    int maxWeight = 50;
    
    // Seed the random number generator for consistent behavior
    srand(time(NULL));

    Knapsack knapsack;
    initializeKnapsack(&knapsack, n);
    
    printf("Knapsack Problem\n");
    printf("Max Weight: %d\n\n", maxWeight);
    
    for (int i = 0; i < n; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i, knapsack.items[i].value, knapsack.items[i].weight);
    }
    
    printf("\n");
    greedyKnapsack(&knapsack, maxWeight);
    
    freeKnapsack(&knapsack);
    
    return 0;
}