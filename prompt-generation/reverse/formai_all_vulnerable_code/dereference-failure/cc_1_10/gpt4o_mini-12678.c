//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->ratio < itemB->ratio) return 1;
    else if (itemA->ratio > itemB->ratio) return -1;
    else return 0;
}

void knapsackGreedy(int maxWeight, Item *items, int itemCount) {
    qsort(items, itemCount, sizeof(Item), compare);

    int currentWeight = 0;
    float totalValue = 0.0;

    printf("Selected items:\n");

    for (int i = 0; i < itemCount; i++) {
        if (currentWeight + items[i].weight <= maxWeight) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d - Value: %d, Weight: %d, Ratio: %.2f\n",
                   i + 1, items[i].value, items[i].weight, items[i].ratio);
        } else {
            float remainingWeight = maxWeight - currentWeight;
            totalValue += items[i].value * (remainingWeight / items[i].weight);
            printf("Item %d (partial) - Value: %.2f, Weight: %.2f, Ratio: %.2f\n",
                   i + 1, items[i].value * (remainingWeight / items[i].weight),
                   remainingWeight, items[i].ratio);
            break; // No more space in knapsack
        }
    }

    printf("Total Value: %.2f\n", totalValue);
}

void initItems(Item *items, int count) {
    for (int i = 0; i < count; i++) {
        items[i].value = rand() % 100 + 1; // Random value between 1 and 100
        items[i].weight = rand() % 50 + 1; // Random weight between 1 and 50
        items[i].ratio = (float)items[i].value / (float)items[i].weight; // Value/Weight ratio
    }
}

void printItems(Item *items, int count) {
    printf("Available items:\n");
    for (int i = 0; i < count; i++) {
        printf("Item %d - Value: %d, Weight: %d, Ratio: %.2f\n",
               i + 1, items[i].value, items[i].weight, items[i].ratio);
    }
}

int main() {
    int itemCount = 10;
    Item *items = malloc(itemCount * sizeof(Item));
    int maxWeight = 100;

    srand(42); // Seed for reproducibility
    initItems(items, itemCount);
    printItems(items, itemCount);

    knapsackGreedy(maxWeight, items, itemCount);

    free(items);
    return 0;
}