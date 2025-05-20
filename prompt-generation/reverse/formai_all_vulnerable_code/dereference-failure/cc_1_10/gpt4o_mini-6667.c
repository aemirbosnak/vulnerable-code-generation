//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio; // value/weight ratio
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    if (item1->ratio < item2->ratio) return 1;  // Sorting in descending order
    if (item1->ratio > item2->ratio) return -1; 
    return 0;
}

void greedyKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items based on the value-to-weight ratio

    double totalValue = 0.0;
    int currentWeight = 0;
    printf("Items included in the knapsack:\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d\n", i+1, items[i].weight, items[i].value);
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity; // Take the fraction of the item
            printf("Item %d (partial): Weight = %d, Value = %.2f\n", i+1, remainingCapacity, items[i].ratio * remainingCapacity);
            break;
        }
    }

    printf("Maximum value in the knapsack = %.2f\n", totalValue);
}

int main() {
    int n;
    int capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio for sorting
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &capacity);

    greedyKnapsack(items, n, capacity);

    free(items);
    return 0;
}