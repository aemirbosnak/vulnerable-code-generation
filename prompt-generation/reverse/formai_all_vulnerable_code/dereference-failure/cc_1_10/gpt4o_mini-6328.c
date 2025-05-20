//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int profit;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    double r1 = ((Item*)a)->profit / (double)((Item*)a)->weight;
    double r2 = ((Item*)b)->profit / (double)((Item*)b)->weight;
    return (r1 < r2) ? -1 : (r1 > r2) ? 1 : 0;
}

void knapsackGreedy(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    
    int totalProfit = 0;
    int totalWeight = 0;
    int i = 0;

    printf("Items chosen for maximum profit:\n");

    while (i < n && totalWeight + items[i].weight <= capacity) {
        totalWeight += items[i].weight;
        totalProfit += items[i].profit;
        printf("Item ID: %d, Profit: %d, Weight: %d\n", items[i].id, items[i].profit, items[i].weight);
        i++;
    }

    if (i < n) {
        double fraction = (capacity - totalWeight) / (double)items[i].weight;
        totalProfit += items[i].profit * fraction;
        printf("Item ID: %d, Profit: %.2f (Taking fraction: %.2f)\n", items[i].id, items[i].profit * fraction, fraction);
    }

    printf("Total profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item*)malloc(n * sizeof(Item));

    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d (space separated): ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].id = i + 1;
    }

    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsackGreedy(items, n, capacity);

    free(items);
    return 0;
}