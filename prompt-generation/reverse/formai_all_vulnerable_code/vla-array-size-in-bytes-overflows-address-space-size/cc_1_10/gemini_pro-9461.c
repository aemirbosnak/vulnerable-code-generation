//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int weight;
    int value;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->value / item2->weight) - (item1->value / item1->weight);
}

double greedy_knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = greedy_knapsack(items, n, capacity);

    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    return 0;
}